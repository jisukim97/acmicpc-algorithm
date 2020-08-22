#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)

//다익스트라 O(|V|^2) 
// with 인접행렬

using namespace std;

typedef struct {
	int start;
	int end;
	int weight;
} edge;

int vertex_N, edge_N; //정점개수, 간선개수
int start_V;		  //시작정점 번호
int* visited;		  //정점 포함 여부
int* shortest_path;	  //각 정점으로의 최단거리 from 시작점
int** weight;		  //각 정점 간의 weight를 나타내는 adjacency matrix

class cmp {
public:
	bool operator() (edge e1, edge e2) {
		if (visited[e1.start - 1] && visited[e2.start - 1]) {
			return e1.weight > e2.weight; // 두 엣지 다 시작노드가 visited면 weight가 더 작은게 우선순위가 높다.
		}
		else if (visited[e1.start - 1]) {
			return false; //e1만 visited인 시작 노드를 포함하면 엣지 e1 우선순위가 더 높다.
		}
		else if (visited[e2.start - 1]) {
			return true; //e2만 visited인 시작 노드를 포함하면 엣지 e2 우선순위가 더 높다.
		}
		else return e1.weight > e2.weight; //아무렴 어때
	}
};

priority_queue<edge, vector<edge>, cmp> pri_q;

int main() {

	scanf("%d %d %d", &vertex_N, &edge_N, &start_V);

	visited = new int[vertex_N] {0};

	shortest_path = new int[vertex_N] {0};
	fill(shortest_path, shortest_path + vertex_N, 9999999); //모두 무한대로 설정
	shortest_path[start_V - 1] = 0; //시작점은 cost 0으로 설정

	weight = new int* [vertex_N];
	for (int i = 0; i < vertex_N; i++) {
		weight[i] = new int[vertex_N];
		int* tmp = weight[i];
		fill(tmp, tmp + vertex_N, 9999999); //기본적으로 무한대INT_MAX로 설정
		weight[i][i] = 0; //자기자신으로 가는 가중치는 0
	}

	visited[start_V - 1] = 1; //시작점 방문표시

	for (int i = 0; i < edge_N; i++) { //주어진 간선 가중치 정보 adjacency matrix에 저장
		int s, e, w; //start, end, weight;
		scanf("%d %d %d", &s, &e, &w);
		weight[s - 1][e - 1] = min(weight[s - 1][e - 1], w);
		pri_q.push({ s,e,w });
	}

	int mini = min(vertex_N, edge_N);
	int cnt = 0;
	while (1) {
		edge tmp = pri_q.top();
		pri_q.pop();

		visited[tmp.end - 1] = 1; //연결된 노드 방문했다고 기록

		for (int i = 0; i < vertex_N; i++)
			if (shortest_path[i] > shortest_path[tmp.start - 1] + weight[tmp.start - 1][i])
				shortest_path[i] = shortest_path[tmp.start - 1] + weight[tmp.start - 1][i]; //shortest path 업데이트

		cnt++;
		if (cnt == mini) break;

		queue<edge> tmp_q;
		while (!pri_q.empty()) {
			tmp_q.push(pri_q.top());
			pri_q.pop();
		}
		while (!tmp_q.empty()) {
			pri_q.push(tmp_q.front());
			tmp_q.pop();
		}
	}

	for (int i = 0; i < vertex_N; i++) {
		if (shortest_path[i] == 9999999) printf("INF\n");
		else printf("%d\n",shortest_path[i]);
	}

	return 0;
}