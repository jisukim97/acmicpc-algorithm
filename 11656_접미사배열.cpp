#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	
	string s;
	cin >> s;

	int s_len = s.size();
	string* arr = new string[s_len];

	for (int i = 0; i < s_len; i++) {
		string tmp;
		tmp = s.substr(i, s_len);
		arr[i] = tmp;
	}

	sort(arr, arr + s_len);

	for (int i = 0; i < s_len; i++)
		cout << arr[i] << "\n";

	return 0;
}