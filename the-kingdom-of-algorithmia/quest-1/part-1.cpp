#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <algorithm>

const std::string file = "input-1.txt";

int main() {

    std::ifstream input_stream(file);

    std::string input;
    std::getline(input_stream, input);

    int potions = 0;

    std::for_each(input.begin(), input.end(), [&potions](char enemy) {
        switch (enemy) {
            case 'A': break;
            case 'B': potions += 1; break;
            case 'C': potions += 3; break;
            default: break;
        } 
    });

    std::cout << "Potions: " << potions << '\n';

    return 0;
}
