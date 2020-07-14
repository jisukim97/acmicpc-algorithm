#include<iostream>
#include<queue>

using namespace std;


int main() {
	
	string s;
	cin >> s;

	priority_queue<int> numArr;
	for (int i = 0; i < s.size(); i++)
		numArr.push(s[i] - '0');

	while (!numArr.empty()) {
		cout << numArr.top();
		numArr.pop();
	}
	return 0;
}