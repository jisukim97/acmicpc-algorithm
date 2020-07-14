#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	
	int drwaf[9], sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> drwaf[i];
		sum += drwaf[i];
	}

	sort(drwaf, drwaf + 9);
	
	int i, j, flag=0;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++)
			if ((sum - drwaf[i] - drwaf[j]) == 100) {
				flag = 1;  break;
			}
		if (flag) break;
	}

	for (int k = 0; k < 9; k++)
		if (k != i && k != j) cout << drwaf[k] << "\n";

	return 0;
}