#include "NumberList.h"
#include <iostream>

using namespace std;

int main() {
	NumberList list;
	list.Init();

	list.Add(5);
	list.Add(9);
	list.Add(2);
	list.Add(1);

	list.Print();

	list.Sort();

	list.Print();

	return 0;
}