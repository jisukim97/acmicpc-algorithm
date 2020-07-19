#include<iostream>

using namespace std;

int main() {

	int n,m;
	cin >> n;
	pair<int, string>* sp;
	sp = new pair<int, string>[n];

	for (int i = 0; i < n; i++)
		cin>>sp[i].first>>sp[i].second;

	for (int i = 0; i < n; i++) {
		for (int s = 0; s < sp[i].second.size(); s++)
			for (int j = 0; j < sp[i].first; j++)
				cout << sp[i].second[s];
		if (i == (n - 1)) break;
		cout << "\n";
	}
	return 0;
}