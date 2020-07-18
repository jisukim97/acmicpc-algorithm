#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	pair<int, int>* p = new pair<int, int>[n];

	for (int i = 0; i < n; i++)
		cin >> p[i].second >> p[i].first;

	sort(p, p + n);

	for (int i = 0; i < n; i++){
		cout << p[i].second << " " << p[i].first;
		if (i == (n - 1)) break;
		cout << "\n";
	}

	return 0;
}