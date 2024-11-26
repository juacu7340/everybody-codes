#include <iomanip>

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <string_view>

#include <algorithm>
#include <ranges>
#include <vector>

#include <utility>

std::string_view file = "input-1.txt";

std::pair<std::string, std::string> get_input() {
    std::ifstream input_stream(file);

    std::string words, inscription;

    std::getline(input_stream, words);
    std::size_t pos = words.find("WORDS:");
    words = words.substr(pos + 6);

    std::getline(input_stream, inscription);
    std::getline(input_stream, inscription);

    return std::make_pair(words, inscription);
}

int main() {
    auto [input_words, input_inscription] = get_input();

    std::ranges::replace_if(input_inscription, [](char c) { return c == ',' || c == '.'; }, ' ');

    std::string_view words = input_words;
    std::string_view inscription = input_inscription;

    constexpr std::string_view runes_delim{","};
    constexpr std::string_view inscription_delim{" "};
 
    std::vector<std::string_view> runes;

    for (const auto word : std::views::split(words, runes_delim))
        runes.push_back(std::string_view(word));

    int runic_words = 0;

    for (const auto word : std::views::split(inscription, inscription_delim)) {
        auto word_sv = std::string_view(word);
        for (const auto rune : runes) {
            if (word_sv.find(rune) != std::string::npos) {
                runic_words++;
            }
        }
    }

    std::cout << "Runic words: " << runic_words << '\n';

    return 0;
}
