#include<iostream>

using namespace std;

int main() {

	string* str = new string[5];
	int* slen = new int[5];

	int maxi = 0;

	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		slen[i] = str[i].size();
		if (slen[i] > maxi) maxi = slen[i];
	}

	for (int i = 0; i < maxi; i++) 
		for (int j = 0; j < 5; j++) 
			if (i < slen[j]) cout << str[j][i];

	return 0;
}