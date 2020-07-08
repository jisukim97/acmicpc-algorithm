#include<iostream>
#include<stack>

using namespace std;

int main() {

	int n;
	cin >> n;
	int temp;
	stack<int>s;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp != 0) s.push(temp);
		else s.pop();
	}

	temp = 0;
	while (!s.empty()) {
		temp += s.top();
		s.pop();
	}

	cout << temp;

	return 0;
}