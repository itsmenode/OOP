#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	char s[1000];
	char words[100][100];
	int wordCount = 0;

	scanf(" %[^\n]", s);
	int start = 0, end = 0;

	while (s[end] != '\0') {
		while (s[start] == ' ' && s[start] != '\0') {
			start++;
		}

		end = start;
		while (s[end] != ' ' && s[end] != '\0') {
			end++;
		}

		if (start < end) {
			int wordLength = end - start;
			for (int i = 0; i < wordLength; i++) {
				words[wordCount][i] = s[start + i];
			}

			words[wordCount][wordLength] = '\0';
			wordCount++;
			start = end;
		}
	}

	for (int i = 0; i < wordCount - 1; i++) {
		for (int j = 0; j < wordCount - i - 1; j++) {
			// Get the lengths of the two words
			int len1 = strlen(words[j]);
			int len2 = strlen(words[j + 1]);

			// If second word is longer OR same length but comes first alphabetically
			if (len2 > len1 || (len2 == len1 && strcmp(words[j], words[j + 1]) > 0)) {
				// Swap the words
				char temp[100];
				strcpy(temp, words[j]);
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], temp);
			}
		}
	}

	for (int i = 0; i < wordCount; i++) {
		printf("%s\n", words[i]);
	}


	return 0;
}