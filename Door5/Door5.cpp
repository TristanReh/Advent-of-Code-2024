#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int checkArray(std::vector<int> dataSet, std::vector<int> dataLeft, std::vector<int> dataRight) {
    for (int j = 0; j < dataSet.size(); j++) {
        for (int k = 0; k < dataLeft.size(); k++) {
            if (dataSet[j] == dataLeft[k]) {
                for (int l = j; l >= 0; l--) {
                    if (dataSet[l] == dataRight[k]) {

                        return 0;
                    }
                }
            }
        }
    }
    return dataSet[(dataSet.size() - 1) / 2];
}

int fixArray(std::vector<int> dataSet, std::vector<int> dataLeft, std::vector<int> dataRight) {
    for (int j = 0; j < dataSet.size(); j++) {
        for (int k = 0; k < dataLeft.size(); k++) {
            if (dataSet[j] == dataLeft[k]) {
                for (int l = j - 1; l >= 0; l--) {
                    if (dataSet[l] == dataRight[k]) {
                        dataSet[l] = dataLeft[k];
                        dataSet[j] = dataRight[k];
                    }
                }
            }
        }
    }
    if (checkArray(dataSet, dataLeft, dataRight) == 0) {
        return fixArray(dataSet, dataLeft, dataRight);
    }

    return dataSet[(dataSet.size() - 1) / 2];
}

int main() {
    std::fstream input;
    input.open("input.txt", std::ios::in);
    int i = 0;
    int result1 = 0;
    int result2 = 0;
    std::string line;
    std::vector<int> dataLeft;
    std::vector<int> dataRight;
    std::vector<int> dataSet;

    while (std::getline(input, line)) {
        std::string token;

        if (line.empty()) {
            break;
        }
        std::stringstream ss(line);

        while (std::getline(ss, token, '|')) {
            (i++ % 2 == 0 ? dataLeft : dataRight).push_back(std::stoi(token));
        }
    }

    while (std::getline(input, line)) {
        std::string token;
        std::stringstream ss(line);
        while (std::getline(ss, token, ',')) {
            dataSet.push_back(std::stoi(token));
        }
        if (checkArray(dataSet, dataLeft, dataRight) == 0) {
            result2 += fixArray(dataSet, dataLeft, dataRight);
        }
        else {
            result1 += checkArray(dataSet, dataLeft, dataRight);
        }

        dataSet.clear();

    }
    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    return 0;
}
