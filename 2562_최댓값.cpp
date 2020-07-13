#include<iostream>

using namespace std;

int main() {

	int* a = new int[9];
	for (int i = 0; i < 9; i++)
		cin >> a[i];

	int max = a[0], index=0;
	for (int i = 0; i < 9; i++) 
		if (max < a[i]) { max = a[i];  index = i; }


	cout << max<< "\n" << (index+1);

	return 0;
}