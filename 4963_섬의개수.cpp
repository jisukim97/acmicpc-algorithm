#include<iostream>
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> Pair;
int** map; //지도
int** marked; //방문 했는지 마킹
int h, w; //행렬 크기
int island_N; //total 섬 수

queue<Pair> aq; //adjacentcy 정보를 담는 queue

void BFS(int a, int b) { //한 지점으로부터 8개의 방면을 다 체크해서 queue에 쌓기
	aq.push({ a,b });
	marked[a][b] = 1;

	while (!aq.empty()) {
		Pair tmp = aq.front();
		aq.pop();
		int i = tmp.first;
		int j = tmp.second;
		
		if (map[i][j] == 1) { // 새 섬에 추가 가능
			if ((j + 1) < w && map[i][j + 1] && !marked[i][j + 1]) { //오른쪽
				aq.push(make_pair(i, j + 1));
				marked[i][j + 1] = 1;
			}
			if ((i + 1) < h && (j + 1) < w && map[i + 1][j + 1] && !marked[i + 1][j + 1]) { //오른쪽 아래 대각선
				aq.push(make_pair(i + 1, j + 1));
				marked[i + 1][j + 1] = 1;
			}
			if ((i + 1) < h && map[i + 1][j] && !marked[i + 1][j]) { //아랫쪽
				aq.push(make_pair(i + 1, j));
				marked[i + 1][j] = 1;
			}
			if ((i + 1) < h && (j - 1) >= 0 && map[i + 1][j - 1] && !marked[i + 1][j - 1]) { //왼쪽 아래 대각선 
				aq.push(make_pair(i + 1, j - 1));
				marked[i + 1][j - 1] = 1;
			}
			if ((j - 1) >= 0 && map[i][j - 1] && !marked[i][j - 1]) {  //왼쪽
				aq.push(make_pair(i, j - 1));
				marked[i][j - 1] = 1;
			}
			if ((i - 1) >= 0 && (j - 1) >= 0 && map[i - 1][j - 1] && !marked[i - 1][j - 1]) { //왼쪽 위 대각선
				aq.push(make_pair(i - 1, j - 1));
				marked[i - 1][j - 1] = 1;
			}
			if ((i - 1) >= 0 && map[i - 1][j] && !marked[i - 1][j]) { //위쪽
				aq.push(make_pair(i - 1, j));
				marked[i - 1][j] = 1;
			}
			if ((i - 1) >= 0 && (j + 1) < w && map[i - 1][j + 1] && !marked[i - 1][j + 1]) { //오른쪽 위 대각선
				aq.push(make_pair(i - 1, j + 1));
				marked[i - 1][j + 1] = 1;
			}
		}

	}
}

int main() {

	while (true) {

		scanf("%d %d", &w, &h);
		if (w == 0) break;

		map = new int* [h];
		for (int i = 0; i < h; i++)
			map[i] = new int[w] {0};
		marked = new int* [h];
		for (int i = 0; i < h; i++)
			marked[i] = new int[w] {0};

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &map[i][j]);

		island_N = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (map[i][j] == 1 && marked[i][j] != 1) { //아직 마킹 안됐는데 지도에 1이면, new island 발견
					island_N++;
					BFS(i, j);
				}
		printf("%d\n", island_N);
	}

	return 0;
}