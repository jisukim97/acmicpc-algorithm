#include<iostream>
#include<queue>

using namespace std;


int main() {

	int n, k;
	cin >> n >> k;
	queue<int> q;
	int* permu = new int[n] {0};

	for (int i = 1; i <= n; i++)
		q.push(i);
	int index = 0;
	while (!q.empty()) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		permu[index++] = q.front();
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << permu[i];
		if(i==(n-1)) break;
		cout<< ", ";
	}
	cout << ">";

	return 0;
}