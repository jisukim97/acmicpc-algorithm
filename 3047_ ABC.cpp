#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int* arr = new int[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	sort(arr, arr + 3);
	string s;
	cin >> s;

	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == 65) cout << arr[0];
		else if (s[i] == 66) cout << arr[1];
		else cout << arr[2];
		cout << " ";
	}


	return 0;
}