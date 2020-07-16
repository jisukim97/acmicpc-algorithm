#include<iostream>
#include<queue>
using namespace std;


int main() {

	int n, m;
	cin >> n >> m;

	priority_queue<string, vector<string>, greater<string> > nono;
	queue<string> ans;

	for (int i = 0; i < (n + m-1); i++) {
		string tmp;
		cin >> tmp;
		nono.push(tmp);
	}

	string tmp;
	while (!nono.empty()) {
		tmp = nono.top();
		nono.pop();
		if (!nono.empty() && tmp == nono.top()) ans.push(tmp);
	}

	cout << ans.size() << "\n";
	while (!ans.empty()) {
		cout << ans.front()<<"\n";
		ans.pop();
	}

	return 0;
}