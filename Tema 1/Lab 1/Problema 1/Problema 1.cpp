#include <stdio.h>

using namespace std;

int convertString(char* str);

int main() {
	FILE* file;

	char line[100];

	int sum = 0;

	errno_t err;
	err = fopen_s(&file, "in.txt", "r");

	while (fgets(line, sizeof(line), file) != NULL) {
		sum += convertString(line);
	}

	fclose(file);
	printf("%d\n", sum);
	return 0;
}

int convertString(char* str) {
	int num = 0;
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = num * 10 + (str[i] - '0');
		}
	}

	return num;
}