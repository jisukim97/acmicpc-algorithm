#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int main() {

	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, cmp> q;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp != 0) q.push(tmp);
		else
			if (!q.empty()) {
				printf("%d\n", q.top());
				q.pop();
			}
			else printf("%d\n", 0);
	}

	return 0;
}