#include <algorithm>
#include <charconv>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <vector>

namespace {

constexpr int max_dimension = 1000;
constexpr int max_second = 1'000'000'000;

bool is_blank(int ch) {
    return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

int skip_blanks(std::streambuf& file) {
    int ch = file.sgetc();
    while (is_blank(ch)) ch = file.snextc();
    return ch;
}

std::string read_token(std::istream& file, std::size_t max_length, const char* field) {
    std::streambuf& buffer = *file.rdbuf();
    const int eof = std::char_traits<char>::eof();
    std::string token;
    for (int ch = skip_blanks(buffer); ch != eof && !is_blank(ch); ch = buffer.snextc()) {
        if (token.size() == max_length) {
            throw std::runtime_error(std::string("Token is too long for ") + field + '.');
        }
        token.push_back(static_cast<char>(ch));
    }
    if (token.empty()) throw std::runtime_error(std::string("Missing ") + field + '.');
    return token;
}

int read_int(std::istream& file, int low, int high, const char* field) {
    const std::string token = read_token(file, 10, field);
    int value = 0;
    const char* end = token.data() + token.size();
    const auto result = std::from_chars(token.data(), end, value);
    if (result.ec != std::errc{} || result.ptr != end ||
        token.front() < '0' || token.front() > '9' ||
        (token.size() > 1 && token.front() == '0') ||
        value < low || value > high) {
        throw std::runtime_error(std::string("Invalid ") + field + '.');
    }
    return value;
}

void expect_end(std::istream& file) {
    if (skip_blanks(*file.rdbuf()) != std::char_traits<char>::eof()) {
        throw std::runtime_error("Extra data at end of file.");
    }
}

struct Board {
    int rows;
    int columns;
    bool needs_plan;
    int light_count = 0;
    std::vector<int> move_to;
    std::vector<unsigned char> has_light;
};

Board read_board(std::istream& input) {
    const int rows = read_int(input, 1, max_dimension, "row count");
    const int columns = read_int(input, 1, max_dimension, "column count");
    const bool needs_plan = read_int(input, 0, 1, "output flag") == 1;
    const int cells = rows * columns;
    Board board{rows, columns, needs_plan, 0, std::vector<int>(cells),
                std::vector<unsigned char>(cells)};

    for (int r = 0; r < rows; ++r) {
        const std::string row = read_token(input, columns, "grid row");
        if (row.size() != static_cast<std::size_t>(columns)) {
            throw std::runtime_error("Grid row has the wrong length.");
        }
        for (int c = 0; c < columns; ++c) {
            const char mark = row[c];
            int next_r = r;
            int next_c = c;
            switch (mark) {
                case 'N': case 'n': --next_r; break;
                case 'S': case 's': ++next_r; break;
                case 'E': case 'e': ++next_c; break;
                case 'W': case 'w': --next_c; break;
                default: throw std::runtime_error("Invalid grid direction.");
            }
            if (next_r < 0 || next_r >= rows || next_c < 0 || next_c >= columns) {
                throw std::runtime_error("A movement leaves the grid.");
            }
            const int index = r * columns + c;
            board.move_to[index] = next_r * columns + next_c;
            board.has_light[index] = 'A' <= mark && mark <= 'Z';
            board.light_count += board.has_light[index];
        }
    }
    expect_end(input);
    return board;
}

struct Activation {
    int cell;
    int second;
};

std::vector<Activation> read_activations(std::istream& output, const Board& board, int count) {
    std::vector<Activation> plan;
    plan.reserve(count);
    std::vector<unsigned char> used(board.move_to.size());
    for (int i = 0; i < count; ++i) {
        const int row = read_int(output, 1, board.rows, "activation row");
        const int column = read_int(output, 1, board.columns, "activation column");
        const int second = read_int(output, 1, max_second, "activation second");
        const int cell = (row - 1) * board.columns + column - 1;
        if (!board.has_light[cell]) throw std::runtime_error("The activation cell has no light.");
        if (used[cell]) throw std::runtime_error("The same light is activated twice.");
        used[cell] = 1;
        plan.push_back({cell, second});
    }
    return plan;
}

void check_movements(const Board& board, std::vector<Activation>& plan) {
    if (plan.size() < 2) return;
    int latest = 0;
    for (const auto& activation : plan) latest = std::max(latest, activation.second);

    const int cells = static_cast<int>(board.move_to.size());
    // A pair has at most cells * cells states once both lights are active.
    // Positions that ever coincide stay equal at every later second.
    const std::uint64_t checkpoint = latest + static_cast<std::uint64_t>(cells) * cells;
    std::vector<int> jump = board.move_to;
    std::vector<int> double_jump(cells);
    for (std::uint64_t steps = 1; steps < checkpoint; steps *= 2) {
        for (auto& activation : plan) {
            if ((checkpoint - activation.second) & steps) {
                activation.cell = jump[activation.cell];
            }
        }
        if (steps * 2 >= checkpoint) break;
        for (int cell = 0; cell < cells; ++cell) {
            double_jump[cell] = jump[jump[cell]];
        }
        jump.swap(double_jump);
    }

    std::vector<unsigned char> occupied(cells);
    for (const auto& activation : plan) {
        if (occupied[activation.cell]) {
            throw std::runtime_error("Two activated lights occupy the same cell at some second.");
        }
        occupied[activation.cell] = 1;
    }
}

void check_output(std::istream& output, const Board& board, int reference_count) {
    const int count = read_int(output, 0, board.light_count, "activation count");
    if (count != reference_count) {
        throw std::runtime_error("Activation count does not match the reference output.");
    }
    if (!board.needs_plan) {
        expect_end(output);
        return;
    }

    auto plan = read_activations(output, board, count);
    expect_end(output);
    check_movements(board, plan);
}

}  // namespace

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: checker <input> <your-output> <reference-output>\n";
        return 2;
    }

    std::ifstream input(argv[1], std::ios::binary);
    std::ifstream output(argv[2], std::ios::binary);
    std::ifstream reference(argv[3], std::ios::binary);
    if (!input || !output || !reference) {
        std::cerr << "ERROR Could not open one of the three files.\n";
        return 2;
    }

    try {
        const auto board = read_board(input);
        const int count = read_int(reference, 0, board.light_count, "reference activation count");
        try {
            check_output(output, board, count);
        } catch (const std::runtime_error& error) {
            std::cerr << "WA " << error.what() << '\n';
            return 1;
        }
    } catch (const std::runtime_error& error) {
        std::cerr << "ERROR " << error.what() << '\n';
        return 2;
    }
    std::cout << "OK\n";
    return 0;
}
