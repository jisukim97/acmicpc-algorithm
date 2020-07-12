#include<iostream>
#include<utility>

using namespace std;


int main() {

	int a;
	pair<int, int>* p;
	cin >> a;

	p = new pair<int, int>[a];

	for (int i = 0; i < a; i++) 
		cin >>p[i].first>>p[i].second;

	for (int i = 0; i < a; i++) {
		cout << "Case #"<<(i+1)<<": "<<p[i].first<<" + "<<p[i].second<<" = "<< p[i].first + p[i].second;
		if (i == (a - 1)) break;
		cout << "\n";
	}

	return 0;
}