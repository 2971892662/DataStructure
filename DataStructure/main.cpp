#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Sort.h"
using namespace std;



int main() {
	int s[] = { 1,2,3,4,5,6,7,0 };
	QuickSwapSort(s, 0,sizeof(s) / sizeof(int)-1);
	for (int i = 0; i < sizeof(s) / sizeof(int); i++) {
		cout << s[i] << " ";
	}
}