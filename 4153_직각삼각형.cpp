#include<iostream>
#include<algorithm>

using namespace std;


int main() {

	int *num = new int[3];

	while(true){
		cin >> num[0] >> num[1] >> num[2];
		sort(num, num + 3);

		if (num[0] == 0) break;

		if ((num[0] * num[0]) + (num[1] * num[1]) == (num[2] * num[2])) cout << "right\n";
		else cout << "wrong\n";
	}

	return 0;
}