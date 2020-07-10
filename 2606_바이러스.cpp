#include<iostream>
#include<stack>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

int** adjacent;
int* marked;
int node_N, edge_N;
stack<int> dfs;

int DFS(int d) {
	marked = new int[node_N] {0};
	int cnt=0;

	dfs.push(d);
	while (!dfs.empty()) { 
		int tmp = dfs.top();
		dfs.pop();
		for (int i = node_N-1; i >=0; i--) 
			if (adjacent[tmp - 1][i]&&!marked[i]) dfs.push(i + 1); 
		
		if (!marked[tmp - 1]) {
			cnt++;
			marked[tmp - 1] = 1;
		}
	}

	return cnt;
}


int main() {

	scanf("%d %d", &node_N, &edge_N);
	
	adjacent = new int* [node_N];
	for (int i = 0; i < node_N; i++)
		adjacent[i] = new int[node_N] {0};

	for (int i = 0; i < edge_N; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		if (!adjacent[n1-1][n2-1]) adjacent[n1-1][n2-1] = 1;
		if (!adjacent[n2-1][n1-1]) adjacent[n2-1][n1-1] = 1;
	}

	printf("%d", DFS(1)-1);

	return 0;
}