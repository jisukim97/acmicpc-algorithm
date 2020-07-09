#include<iostream>
#include<cstdio>
#include<deque>
#pragma warning(disable:4996)

using namespace std;

int main() {

	int n;
	cin >> n;

	deque<int> dq;
	string command;

	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push_front") {
			int m;
			scanf("%d", &m);
			dq.push_front(m);
		}
		else if (command == "push_back") {
			int m;
			scanf("%d", &m);
			dq.push_back(m);
		}
		else if (command == "pop_front") {
			if (dq.empty()) printf("%d\n", -1);
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (dq.empty()) printf("%d\n", -1);
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if (command == "size") printf("%d\n", dq.size());
		else if (command == "empty") printf("%d\n", dq.empty());
		else if (command == "front") {
			if (dq.empty()) printf("%d\n", -1);
			else printf("%d\n", dq.front());
		}
		else if (command == "back") {
			if (dq.empty()) printf("%d\n", -1);
			else printf("%d\n", dq.back());
		}
	}

	return 0;
}