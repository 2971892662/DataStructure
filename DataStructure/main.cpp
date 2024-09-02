#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Sort.h"
using namespace std;



int main() {
	int s[] = { 11,2,13,4,-2 };
	ShellInsertSort(s, sizeof(s) / sizeof(int));
	for (int i = 0; i < sizeof(s) / sizeof(int); i++) {
		cout << s[i] << " ";
	}
}