#include "testlib.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {

uint64_t low_mask(int bits) {
    if (bits == 0) return 0;
    if (bits == 64) return ~uint64_t(0);
    return (uint64_t(1) << bits) - 1;
}

class PackedBits {
public:
    PackedBits() : n_(0) {}

    explicit PackedBits(const string &s) : n_((int)s.size()), bits_((n_ + 63) / 64, 0) {
        for (int i = 0; i < n_; ++i) {
            if (s[i] == '1') bits_[i >> 6] |= uint64_t(1) << (i & 63);
        }
    }

    void flip_range(int l, int r) {
        const int first_word = l >> 6;
        const int last_word = r >> 6;
        for (int w = first_word; w <= last_word; ++w) {
            const int word_begin = w << 6;
            const int lo = std::max(l, word_begin) - word_begin;
            const int hi = std::min(r + 1, word_begin + 64) - word_begin;
            bits_[w] ^= low_mask(hi) & ~low_mask(lo);
        }
    }

    bool equal_range(int pos, const PackedBits &other, int other_pos, int len) const {
        while (len > 0) {
            const int take = std::min(len, 64);
            const uint64_t mask = low_mask(take);
            if ((read64(pos) & mask) != (other.read64(other_pos) & mask)) return false;
            pos += take;
            other_pos += take;
            len -= take;
        }
        return true;
    }

private:
    uint64_t read64(int pos) const {
        if (pos >= n_) return 0;
        const int w = pos >> 6;
        const int shift = pos & 63;
        uint64_t value = bits_[w] >> shift;
        if (shift != 0 && w + 1 < (int)bits_.size()) {
            value |= bits_[w + 1] << (64 - shift);
        }
        return value;
    }

    int n_;
    vector<uint64_t> bits_;
};

class CurrentString {
public:
    explicit CurrentString(const string &s)
        : n_((int)s.size()), forward_(s), backward_(string(s.rbegin(), s.rend())) {}

    bool is_palindrome(int l, int r) const {
        return forward_.equal_range(l, backward_, n_ - 1 - r, r - l + 1);
    }

    void flip_range(int l, int r) {
        forward_.flip_range(l, r);
        backward_.flip_range(n_ - 1 - r, n_ - 1 - l);
    }

    bool equals(const string &target) const {
        PackedBits target_bits(target);
        return forward_.equal_range(0, target_bits, 0, n_);
    }

private:
    int n_;
    PackedBits forward_, backward_;
};

bool valid_binary_string(const string &s, int n) {
    if ((int)s.size() != n) return false;
    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

}  // namespace

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    const int tests = inf.readInt(1, 500, "T");

    for (int tc = 1; tc <= tests; ++tc) {
        const int n = inf.readInt(4, 1000, "n");
        const string source = inf.readToken();
        const string target = inf.readToken();
        if (!valid_binary_string(source, n) || !valid_binary_string(target, n)) {
            quitf(_fail, "test %d: malformed binary string in input", tc);
        }

        const long long moves = ouf.readLong();
        if (moves < 0) {
            quitf(_wa, "test %d: negative operation count %lld", tc, moves);
        }

        CurrentString current(source);
        for (long long step = 1; step <= moves; ++step) {
            const int l = ouf.readInt();
            const int r = ouf.readInt();
            if (l < 1 || r > n || l >= r) {
                quitf(_wa,
                      "test %d, operation %lld: interval [%d,%d] must satisfy 1 <= l < r <= %d",
                      tc, step, l, r, n);
            }
            if (!current.is_palindrome(l - 1, r - 1)) {
                quitf(_wa, "test %d, operation %lld: current substring [%d,%d] is not a palindrome",
                      tc, step, l, r);
            }
            current.flip_range(l - 1, r - 1);
        }

        if (!current.equals(target)) {
            quitf(_wa, "test %d: final string differs from the target", tc);
        }
    }

    ouf.skipBlanks();
    if (!ouf.seekEof()) {
        quitf(_wa, "extra tokens after the last test case");
    }

    quitf(_ok, "all %d constructions are valid", tests);
}
