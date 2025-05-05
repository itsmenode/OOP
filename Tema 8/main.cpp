#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main() {
	ifstream file("input.txt");
	if (!file) {
		cerr << "Eroare la deschiderea fisierului";
		return 1;
	}

	string line;
	getline(file, line);
	string sep = " ,?!.";
	string word;
	map<string, int> wordCount;
	for (char car : line) {
		if (isalpha(car)) {
			word += tolower(car);
		}
		else {
			if (word.size()) {
				wordCount[word]++;
				word.clear();
			}
		}
	}
	if (word.size()) {
		wordCount[word]++;
	}

	for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); it++) {
		cout << it->first << " : " << it->second<<endl;
	}

	priority_queue<pair<int, string>> wordList;

	for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); it++) {
		wordList.push(make_pair(it->second, it->first));
	}

	while (wordList.size()) {
		cout << wordList.top().second << " => " << wordList.top().first << endl;
		wordList.pop();
	}
	return 0;
}