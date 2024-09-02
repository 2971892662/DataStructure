#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Sort.h"
using namespace std;



int main() {
	int s[] = { 0,22,-3,4,15,66,7,1 };
	HeapSelectSort(s,sizeof(s) / sizeof(int)-1);
}