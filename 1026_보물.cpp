#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	int* arr = new int[n];
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	sort(arr, arr + n);
	sort(arr2, arr2 + n);

	int min_sum=0;
	for (int i = 0; i < n; i++)
		min_sum += arr[i] * arr2[n - i-1];

	cout << min_sum;

	return 0;
}