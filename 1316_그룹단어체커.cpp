#include<iostream>

using namespace std;

bool checker(string s) {
	int len_s = s.size();
	char prev = s[0];
	char* arr = new char[len_s] { prev, }; //한번 등장한 알파벳은 저장하여 중복을 방지
	int index = 1; //s[0]은 넣은 것으로 간주하여 인덱스는 1부터 
	for (int j = 1; j < len_s; j++) {
		if (s[j] == prev) continue;
		else {
			for (int k = 0; k < index; k++)
				if (arr[k] == s[j]) return false;
			arr[index++] = s[j];
			prev = s[j];
		}
	}
	return true;
}


int main() {

	int n, cnt=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (checker(s)) cnt++;
	}

	cout << cnt;

	return 0;
}