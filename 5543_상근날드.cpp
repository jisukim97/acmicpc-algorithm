#include<iostream>

using namespace std;

int main() {

	int* buger, * drink;
	int min ;

	buger = new int[3];
	drink = new int[2];

	cin >> buger[0] >> buger[1] >> buger[2] >> drink[0] >> drink[1];
	min = buger[0] + drink[0] - 50;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			if ((buger[i] + drink[j]-50) < min) min = buger[i] + drink[j]-50;


	cout << min;

	return 0;
}