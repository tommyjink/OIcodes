#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int cnt=0,NN=1;
// 解题函数，计算最少操作次数
long long solve(int n, int* p) {
    long long ans = p[0];
    for (int i = 1; i < n; ++i) {
        ans += std::max(0, p[i] - p[i - 1]);
    }
    return ans;
}

// 生成输入文件
void generateInputFiles() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int fileIndex = 1; fileIndex <= NN; ++fileIndex) {
        std::string inputFileName = std::to_string(fileIndex) + ".in";
        std::ofstream inFile(inputFileName);

        // 随机确定数据范围，进而确定电脑数量 n
        int n;
        if(++cnt<=6)n=10;
        else if(cnt<=14)n=1000;
        else n=1e6;

        inFile << n << std::endl;
        for (int i = 0; i < n; ++i) {
            // 随机生成每台电脑的目标性能值
            int pi = std::rand() % 10;
            inFile << pi;
            if (i != n - 1) {
                inFile << " ";
            }
        }
        inFile << std::endl;
        inFile.close();
    }
}

// 处理输入文件并生成输出文件
void processInputFiles() {
    for (int fileIndex = 1; fileIndex <= NN; ++fileIndex) {
        std::string inputFileName = std::to_string(fileIndex) + ".in";
        std::string outputFileName = std::to_string(fileIndex) + ".out";
        std::ifstream inFile(inputFileName);
        std::ofstream outFile(outputFileName);

        int n;
        inFile >> n;
        int* p = new int[n];
        for (int i = 0; i < n; ++i) {
            inFile >> p[i];
        }

        // 调用解题函数计算结果
        long long result = solve(n, p);
        outFile << result << std::endl;

        inFile.close();
        outFile.close();
        delete[] p;
    }
}

int main() {
    // 生成输入数据文件
    generateInputFiles();
    // 处理输入文件并生成输出文件
    processInputFiles();
    return 0;
}