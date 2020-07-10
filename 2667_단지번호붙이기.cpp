#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> Pair;
int** map; //지도
int** marked; //방문 했는지 마킹
int n; //행렬 크기
int danji_N; //total 단지 수
int house_N; //한 단지당 house 수
queue<Pair> aq;
priority_queue<int, vector<int>,greater<int> > hq;


void RFS(int a, int b) { //Right First Search
	aq.push({ a,b });
	marked[a][b] = 1;
	house_N++;

	while (!aq.empty()) {
		Pair tmp = aq.front();
		aq.pop();
		int i = tmp.first;
		int j = tmp.second;

		if (map[i][j] == 1) { // 새 단지에 추가 가능
			if ((j + 1) < n && map[i][j + 1] && !marked[i][j + 1]) //오른쪽 탐색
			{
				Pair tmp= make_pair(i,j + 1 );
				aq.push(tmp);
				marked[i][j + 1] = 1; house_N++;
			}
			if ((i + 1) < n && map[i + 1][j] && !marked[i + 1][j]) //아랫쪽 탐색
			{
				aq.push(make_pair(i+1, j));
				marked[i + 1][j] = 1; house_N++;
			}
			if ((j - 1) >= 0 && map[i][j - 1] && !marked[i][j - 1]) //왼쪽 탐색
			{
				aq.push(make_pair(i, j-1));
				marked[i][j - 1] = 1; house_N++;
			}
			if ((i - 1) >= 0 && map[i - 1][j] && !marked[i - 1][j]) //위쪽 탐색
			{
				aq.push(make_pair(i - 1, j));
				marked[i - 1][j] = 1; house_N++;
			}
		}

	}
}

int main() {

	cin >> n;

	map = new int* [n];
	for (int i = 0; i < n; i++)
		map[i] = new int[n] {0};
	marked = new int* [n];
	for (int i = 0; i < n; i++)
		marked[i] = new int[n] {0};

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j] = s[j] - '0';
	}

	danji_N = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 1 && marked[i][j] != 1) { //새 단지 발견
				danji_N++;
				house_N = 0;
				RFS(i, j);
				hq.push(house_N);
			}

	cout << danji_N << "\n";
	while (!hq.empty()) {
		cout << hq.top() << "\n";
		hq.pop();
	}

	return 0;
}