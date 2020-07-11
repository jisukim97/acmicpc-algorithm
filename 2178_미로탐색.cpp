#include<iostream>
#include<queue>

using namespace std;

typedef pair<pair<int, int>,int> Pair; // < <i,j>, step >
int** map;
int** marked; //방문 했는지 마킹
int n, m; //행렬 크기

int step_N; //한 try에서 걸음 수
queue<Pair> aq;
priority_queue<int> sq; //step queue 걸음 저장


void BFS(int a, int b) { 
	aq.push({ { a,b }, step_N });
	marked[a][b] = 1;

	while (!aq.empty()) {
		Pair tmp = aq.front();
		aq.pop();
		int i = tmp.first.first;
		int j = tmp.first.second;
		step_N = tmp.second+1;

		if (i == (n - 1) && j == (m - 1)) sq.push(step_N);
		else{ 
			if ((j + 1) < m && map[i][j + 1] && !marked[i][j + 1]) //오른쪽 탐색
			{
				aq.push({ {i, j + 1},step_N });
				marked[i][j + 1] = 1;
			}
			if ((i + 1) < n && map[i + 1][j] && !marked[i + 1][j]) //아랫쪽 탐색
			{
				aq.push({ { i + 1, j },step_N });
				marked[i + 1][j] = 1;
			}
			if ((j - 1) >= 0 && map[i][j - 1] && !marked[i][j - 1]) //왼쪽 탐색
			{
				aq.push({ {i,j - 1},step_N });
				marked[i][j - 1] = 1;
			}
			if ((i - 1) >= 0 && map[i - 1][j] && !marked[i - 1][j]) //위쪽 탐색
			{
				aq.push({ {i - 1,j},step_N });
				marked[i - 1][j] = 1;
			}
		}

	}
}

int main() {

	cin >> n>> m;

	map = new int* [n];
	for (int i = 0; i < n; i++)
		map[i] = new int[m] {0};
	marked = new int* [n];
	for (int i = 0; i < n; i++)
		marked[i] = new int[m] {0};

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}

	step_N = 0;
	BFS(0, 0);

	cout << sq.top();

return 0;
}