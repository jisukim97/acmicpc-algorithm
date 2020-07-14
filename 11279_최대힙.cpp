#include<iostream>
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	priority_queue<int> q;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) q.push(tmp);
		else
			if (!q.empty()) {
				printf("%d\n", q.top());
				q.pop();
			}
			else printf("%d\n", 0);
	}

	return 0;
}