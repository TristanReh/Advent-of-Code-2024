#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

bool handleMath(const std::vector<int> &dataSet, int i, long long currentResult, long long target) {
    long long concatenatedNumber;

    if (i >= dataSet.size()) {
        return currentResult == target;
    }
    if (i < dataSet.size()) {
        std::string num1 = std::to_string(currentResult);
        std::string num2 = std::to_string(dataSet[i]);
        std::string num3 = num1 + num2;
        concatenatedNumber = std::stoll(num3);
    }

    return handleMath(dataSet, i + 1, currentResult + dataSet[i], target) ||
           handleMath(dataSet, i + 1, currentResult * dataSet[i], target) ||
           handleMath(dataSet, i + 1, concatenatedNumber, target);
}

int main() {
    std::fstream input("input.txt", std::ios::in);

    long long result = 0;
    std::string line;

    while (std::getline(input, line)) {
        size_t colonPos = line.find(':');

        std::string before = line.substr(0, colonPos);
        std::string after = line.substr(colonPos + 1);


        long long target = std::stoll(before); // Use stoll for larger numbers
        std::vector<int> dataSet;

        std::stringstream afterStream(after);
        std::string afterColumn;
        while (afterStream >> afterColumn) {
            dataSet.push_back(std::stoi(afterColumn)); // Elements are likely still within int range
        }

        if (handleMath(dataSet, 0, 0, target)) {
            result += target;

        }
    }


    std::cout << result << std::endl;
    input.close();
    return 0;
}
