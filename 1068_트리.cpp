#include<iostream>
#include<stack>

using namespace std;

typedef stack<int> Node; //그 인덱스 노드(의 스택)에는 자식 인덱스들이 저장됨

int root; // root가 되는 인덱스(이자 value)저장
int remove_v;
Node* arr;
int* visited; //dfs할때 중복을 방지하고자 
stack<int> stk;

int countLeaf() {

	int cnt = 0;

	while (remove_v != root && !arr[root].empty()) {
		int child = arr[root].top();
		arr[root].pop();
		if (child == remove_v || child == -1) continue;
		stk.push(child);
	}

	while (!stk.empty()) {
		int value = stk.top();
		Node tmp = arr[value];
		stk.pop();

		if ((tmp.size()==1 && tmp.top() == remove_v)|| (visited[value]!=1 && tmp.empty())) { //자식이 아무도 없으면 leaf노드임
			cnt++;
			visited[value] = 1; //첫방문이면 1로 표기
		}

		while (!tmp.empty()) {
			int child = tmp.top();
			tmp.pop();
			if (child == remove_v || child ==-1) continue;
			stk.push(child);
		}
	}
	if (remove_v != root && cnt == 0) cnt = 1; //cnt=0이라는 것은 자식이 아무도 없다는 것이므로, 루트노두 하나가 유일한 리프노드
	return cnt;
}

int main() {

	int n;
	cin >> n;

	arr = new Node[n];
	visited = new int[n] {0};

	for (int i = 0; i < n; i++) {
		int parent_value;
		cin >> parent_value;

		if (parent_value == -1) root = i;
		else arr[parent_value].push(i);
	}

	cin >> remove_v;

	cout<< countLeaf();

	return 0;
}