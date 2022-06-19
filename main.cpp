#include <iostream>

constexpr auto chars = 256;
constexpr auto prime = 37;

int getHash(char str[], int length) {
	int hash = 0;
	for (int i = 0; i < length; i++) {
		hash = (chars * hash + str[i]);
	}

	return hash;
}

void rabinKarp(char pattern[], char text[]) {
	int pattern_length = strlen(pattern);
	int text_length = strlen(text);
	int hash_pattern = getHash(pattern, pattern_length);
	int hash_text = getHash(text, pattern_length);

	int h = 1;
	for (int i = 0; i < pattern_length - 1; i++) {
		h *= chars;
	}

	int counter = 0;
	for (int i = 0; i < text_length - pattern_length; i++) {
		if (hash_pattern == hash_text) {
			for (int j = 0; j < pattern_length; j++) {
				counter = j + 1;
				if (text[i + j] != pattern[j]) {
					break;
				}
			}

			if (counter == pattern_length) {
				std::cout << "Pattern has found in " << i << "th index." << std::endl;
			}
		}

		hash_text = (chars * (hash_text - text[i] * h) + text[i + pattern_length]);
		if (hash_text < 0) {
			hash_text += prime;
		}
	}
}

int main() {
	char text[] = "In computer science, the Rabin–Karp algorithm or Karp–Rabin algorithm is a string-searching algorithm created by Richard M. Karp and Michael O. Rabin.";
	char pattern[] = "algorithm";

	rabinKarp(pattern, text);

	return 0;
}