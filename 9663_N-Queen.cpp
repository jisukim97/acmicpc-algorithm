#include<iostream>
#include<cstdlib>

using namespace std;

int cnt;

bool promising(int k,int n, int * array) {
	if (k < 1) return true;

	for (int i = 0; i < k; i++) 
		if (array[k] == array[i] || abs(k - i) == abs(array[k] - array[i]))
			return false;
	
	return true;
}

void nqueen(int k, int n, int * array) {
	if (promising(k, n, array))
		if (k == (n - 1)) cnt++;
		else {
			for (int i = 0; i < n; i++) {
				array[k+1] = i;
				nqueen(k+1, n, array);
			}
		}
}

int main() {
	
	int n;
	int* array;
	cin >> n;

	cnt = 0;
	array = new int[n];

	for (int i = 0; i < n; i++) {
		array[0] = i;
		nqueen(0,n,array);
	}

	cout << cnt;

	return 0;
}