#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void f()
{
    int k = 1;
    char* p = (char*) &k;
    for (int i = 0; i < 32; i++, k <<= 1) {
        for (int j = 0; j < 4; j++)
        {
            printf("%4hhu ", p[j]);
        }
		cout << endl;
    }
}


int main()
{
	f();
}

