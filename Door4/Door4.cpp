#include <iostream>
#include <fstream>
#include <string>
#include <vector>


bool checkString(std::string string1) {
    if (string1 == "XMAS" || string1 == "SAMX") {
        return true;
    } else return false;
}

int main() {
    int result = 0;
    int result2 = 0;
    std::string string1 = "";
    std::string string2 = "";
    std::fstream input;
    input.open("input.txt", std::ios::in);
    std::string s;
    std::vector<std::string> data;
    while (std::getline(input, s)) {
        data.push_back(s);
    }
    for (int j = 0; j < data.size(); j++) {
        const std::string &line = data[j];
        for (int i = 0; i < line.size(); i++) {
            if (i + 3 < line.size()) {
                string1 = {data[j][i], data[j][i + 1], data[j][i + 2], data[j][i + 3]};
                if (checkString(string1)) {
                    result += 1;
                }
            }
            if (j + 3 < data.size()) {
                string1 = {data[j][i], data[j + 1][i], data[j + 2][i], data[j + 3][i]};
                if (checkString(string1)) {
                    result += 1;
                }
            }
            if (j + 3 < data.size() && i + 3 < line.size()) {
                string1 = {data[j][i], data[j + 1][i + 1], data[j + 2][i + 2], data[j + 3][i + 3]};
                if (checkString(string1)) {
                    result += 1;
                }
            }
            if (j + 3 < data.size() && i - 3 >= 0) {
                string1 = {data[j][i], data[j + 1][i - 1], data[j + 2][i - 2], data[j + 3][i - 3]};
                if (checkString(string1)) {
                    result += 1;
                }
            }
            if (data[j][i] == 'A') {
                if (j + 2 <= data.size() && i + 2 <= line.size() && j - 1 >= 0 && i - 1 >= 0) {
                    string1 = {data[j + 1][i + 1], data[j][i], data[j - 1][i - 1]};
                    string2 = {data[j + 1][i - 1], data[j][i], data[j - 1][i + 1]};
                    if ((string1 == "MAS" || string1 == "SAM") && (string2 == "MAS" || string2 == "SAM")) {
                        result2 += 1;
                    }
                }
            }
        }
        std::cout << result2 << std::endl;
    }

    return 0;
}
