#include<iostream>
#include<string>
#include<queue>

using namespace std;

typedef pair<int, string> Word;

struct cmp {
	bool operator()(Word a, Word b) {
		if (a.first != b.first) return a.first>b.first;
		else if (a.first == b.first) return a.second > b.second;
	}
};

int main() {
	
	int n;
	cin >> n;

	priority_queue<Word, vector<Word>, cmp> q;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		q.push({ s.size(),s });
	}
	string tmp;
	while (true) {
		tmp = q.top().second;
		q.pop();
		if (q.empty()) break;
		else if(tmp == q.top().second) continue;
		cout<< tmp << "\n";
	}
	cout << tmp;

	return 0;
}