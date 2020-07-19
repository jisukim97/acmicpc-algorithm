#include<iostream>
#include<cctype>

using namespace std;

int main() {

	string s;
	cin >> s;
	pair<char, int>* cp = new pair<char, int>[s.size()];

	int max = 0;
	int hear = 0;

	for (int i = 0; i < s.size(); i++) {
		char c = toupper(s[i]);
		for (int j = 0; j < s.size(); j++) {
			if (c == cp[j].first) {
				cp[j].second++; break;
			}
			if (j == (s.size() - 1)) {
				cp[hear].first = c;
				cp[hear++].second = 1;
			}
		}
	}

	int cnt = 0, index;
	for (int i = 0; i < s.size(); i++)
		if (max < cp[i].second) {
			max = cp[i].second; cnt = 1; index = i;
		}
		else if (max == cp[i].second) cnt++;

	if (cnt > 1) cout << "?";
	else cout<< cp[index].first;

	return 0;
}