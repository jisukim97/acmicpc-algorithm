#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	int n;
	cin >> n;

	stack<int> s;
	string command;

	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			int m;
			cin >> m;
			s.push(m);
		}
		else if (command == "top") {
			if (s.empty()) cout << -1 << "\n";
			else cout << s.top() << "\n";
		}
		else if (command == "size") cout << s.size() << "\n";
		else if (command == "empty") {
			if (s.empty()) cout << 1 << "\n";
			else cout << 0<<"\n";
		}
		else if (command == "pop") {
			if (s.empty()) cout << -1 << "\n";
			else { 
				cout << s.top() << "\n";
				s.pop();
			}
		}
	}

	return 0;
}