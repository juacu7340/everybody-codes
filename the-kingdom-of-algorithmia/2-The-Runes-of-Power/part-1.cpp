#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <algorithm>

const std::string file = "input-1.txt";

std::string get_input() {
    std::ifstream input_stream(file);

    std::string input;
    std::getline(input_stream, input);

    return input;
}

int main() {
    const std::string input = get_input();

    return 0;
}
