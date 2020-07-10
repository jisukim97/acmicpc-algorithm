#include<iostream>
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> Pair;
int** map; //배추위치
int** marked; //방문 했는지 마킹
int n, m; //행렬 크기

int worm_N; //total 지렁이 수
queue<Pair> aq;
priority_queue<int, vector<int>,greater<int> > hq;


void RFS(int a, int b) { //Right First Search
	aq.push({ a,b });
	marked[a][b] = 1;

	while (!aq.empty()) {
		Pair tmp = aq.front();
		aq.pop();
		int i = tmp.first;
		int j = tmp.second;

		if (map[i][j] == 1) { // 새 배추 군집에 진입
			if ((j + 1) < m && map[i][j + 1] && !marked[i][j + 1]) //오른쪽 탐색
			{
				Pair tmp= make_pair(i,j + 1 );
				aq.push(tmp);
				marked[i][j + 1] = 1; 
			}
			if ((i + 1) < n && map[i + 1][j] && !marked[i + 1][j]) //아랫쪽 탐색
			{
				aq.push(make_pair(i+1, j));
				marked[i + 1][j] = 1; 
			}
			if ((j - 1) >= 0 && map[i][j - 1] && !marked[i][j - 1]) //왼쪽 탐색
			{
				aq.push(make_pair(i, j-1));
				marked[i][j - 1] = 1; 
			}
			if ((i - 1) >= 0 && map[i - 1][j] && !marked[i - 1][j]) //위쪽 탐색
			{
				aq.push(make_pair(i - 1, j));
				marked[i - 1][j] = 1; 
			}
		}

	}
}

int main() {

	int tc_N; // Test Case 수
	int cabbage_N; //total 배추 수
	scanf("%d", &tc_N);

	for (int k = 0; k < tc_N; k++) {
		scanf("%d %d %d", &m, &n, &cabbage_N);
		map = new int* [n];
		for (int i = 0; i < n; i++)
			map[i] = new int[m] {0};
		marked = new int* [n];
		for (int i = 0; i < n; i++)
			marked[i] = new int[m] {0};

		for (int i = 0; i < cabbage_N; i++) {
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			if (!map[n2][n1]) map[n2][n1] = 1;
		}

		worm_N = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 1 && marked[i][j] != 1) { //새 배추 군집 발견
					worm_N++;
					RFS(i, j);
				}

		

		printf("%d\n", worm_N);
	}

	return 0;
}