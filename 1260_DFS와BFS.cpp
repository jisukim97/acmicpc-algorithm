#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

int** adjacent;
int* marked;
int node_N, edge_N;
stack<int> dfs;
queue<int> bfs;

void DFS(int d) {
	marked = new int[node_N] {0};

	dfs.push(d);
	while (!dfs.empty()) { 
		int tmp = dfs.top();
		dfs.pop();
		for (int i = node_N-1; i >=0; i--) 
			if (adjacent[tmp - 1][i]&&!marked[i]) dfs.push(i + 1); 
		
		if (!marked[tmp - 1]){
			printf("%d ", tmp);
			marked[tmp - 1] = 1;
		}
	}
}

void BFS(int d) {
	marked = new int[node_N] {0};

	bfs.push(d);
	while (!bfs.empty()) {
		int tmp = bfs.front();
		bfs.pop();
		for (int i = 0; i <= node_N; i++)
			if (adjacent[tmp - 1][i] && !marked[i]) bfs.push(i + 1);

		if (!marked[tmp - 1])
		{
			printf("%d ", tmp);
			marked[tmp - 1] = 1; 
		}
	}
}


int main() {

	int depart;
	scanf("%d %d %d", &node_N, &edge_N, &depart);
	
	adjacent = new int* [node_N];
	for (int i = 0; i < node_N; i++)
		adjacent[i] = new int[node_N] {0};

	for (int i = 0; i < edge_N; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		if (!adjacent[n1-1][n2-1]) adjacent[n1-1][n2-1] = 1;
		if (!adjacent[n2-1][n1-1]) adjacent[n2-1][n1-1] = 1;
	}

	DFS(depart);
	printf("\n");
	BFS(depart);

	return 0;
}