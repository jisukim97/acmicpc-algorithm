#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {

	int n;
	int flag = 1;
	cin >> n;
	string line;
	stack<int>ps;

	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < line.size(); j++) {
			if (line[j] == 40) ps.push(40);
			else if (line[j] == 41) {
				if (ps.empty()) flag = 0;
				else ps.pop();
			}
		}
		if (!ps.empty() || !flag) { 
			cout << "NO"; 
			while (!ps.empty()) ps.pop();
			flag = 1;
		}
		else cout << "YES";
		if (i == (n - 1)) break;
		cout << "\n";
	}
	return 0;
}