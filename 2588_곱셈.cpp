#include<iostream>

using namespace std;

int main() {

	int one;
	string two;
	int result = 0;
	cin >> one >> two;

	cout << one * (two[2] -'0')<<"\n";
	cout << one * (two[1] - '0') << "\n";
	cout << one * (two[0] - '0') << "\n";

	cout << one * (two[2] - '0') + one * (two[1] - '0') *10 + one * (two[0] - '0')*100;


}