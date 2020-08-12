#include<iostream>
#include<queue>

using namespace std;

int main() {

	string n;
	cin >> n;

	priority_queue<int> nums;

	int slen = n.size();
	int flag = 0; // 0이 한번이라도 나오면 1로 바꿈
	int sum = 0; // 모든 자릿수의 합
	for(int i=0; i<slen; i++) {
		int one = (n[i] -'0') % 10;
		if (one == 0) flag = 1;
		nums.push(one);
		sum += one;
	}

	if (flag && (sum % 3 == 0)) {
		while (!nums.empty()) {
			cout << nums.top();
			nums.pop();
		}
	}
	else 
		cout << -1;
	
	return 0;
}