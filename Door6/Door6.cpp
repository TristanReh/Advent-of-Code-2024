#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int mapPath(std::vector<std::string> &data, int x, int y, int result) {
    while (data[y - 1][x] != '#') {
        if (data[y][x] != 'H') {
            result += 1;
        }
        data[y][x] = 'H';
        y--;
        if (y - 1 < 0) {
            return result;
        }
    }
    while (data[y][x + 1] != '#') {
        if (data[y][x] != 'H') {
            result += 1;
        }
        data[y][x] = 'H';
        x++;
        if (x + 1 == data[0].size()) {
            return result;
        }
    }
    while (data[y + 1][x] != '#') {
        if (data[y][x] != 'H') {
            result += 1;
        }
        data[y][x] = 'H';
        y++;
        if (y + 1 == data.size()) {
            return result;
        }
    }

    while (data[y][x - 1] != '#') {
        if (data[y][x] != 'H') {
            result += 1;
        }
        data[y][x] = 'H';
        x--;
        if (x - 1 < 0) {
            return result;
        }
    }
    return mapPath(data, x, y, result);
}


int main() {
    std::fstream input;
    int result = 0;
    int x = 0, y = 0;
    input.open("input.txt", std::ios::in);
    std::string s;
    std::vector<std::string> data;
    while (std::getline(input, s)) {
        data.push_back(s);
    }
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            if (data[i][j] == '^') {
                y = i;
                x = j;
            }
        }
    }
    result = mapPath(data, x, y, 0) + 1;
    std::cout << result << std::endl;



    return 0;
}
