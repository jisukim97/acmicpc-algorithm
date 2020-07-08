#include<iostream>
#include<algorithm>

using namespace std;


int main() {

	int* array;
	int n, i, delay=0, total=0;
	cin >> n;

	array = new int[n];

	for (i = 0; i < n; i++)
		cin >> array[i];

	sort(array, array + n);

	for (i = 0; i < n; i++) {
		delay += array[i];
		total += delay;
	}

	cout << total;

	delete[] array;
	return 0;
}
