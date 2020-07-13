#include<iostream>

using namespace std;

int main() {

	int* numbers = new int[10]{ 0 };
	int a, b, c;
	cin >> a >> b >> c;

	int result = a * b * c;
	int rest;

	while(result){
		rest = result % 10;
		result /= 10;
		numbers[rest]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << numbers[i];
		if (i == 9) break;
		cout << "\n";
	}
	return 0;
}