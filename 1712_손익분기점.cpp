#include<iostream>

using namespace std;


int main() {

	int a, b, c;
	cin >> a >> b >> c;

	int x = (c <= b) ? -1 : (a / (c - b)) +1;

	cout << x;
	 
	return 0;
}