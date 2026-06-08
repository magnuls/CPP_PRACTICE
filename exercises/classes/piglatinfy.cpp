#include <string>

std::string piglatinify(const std::string& word) {
    const std::string vowels = "aeiou";

    auto is_vowel = [&vowels](char c) {
        return vowels.find(c) != std::string::npos;
    };

    if (word.empty()) return word;

    if (is_vowel(word[0])) {
        return word + "way";
    }

    // treat 'qu' as a single consonant
    if (word[0] == 'q' && word.size() > 1 && word[1] == 'u') {
        return word.substr(2) + "-quay";
    }

    return word.substr(1) + "-" + word[0] + "ay";
}
