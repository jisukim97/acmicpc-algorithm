#include<iostream>
#include<cstdio>
#include<queue>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> PQ;


int main() {

	int tc;
	scanf("%d", &tc);

	int n, m;
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &n, &m);
		queue<PQ>q;
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			q.push({ j,tmp });
		}
		int max_first, cnt=0;
		int max_second;
		for (int j = 0; j < n; j++) {
			max_first = q.front().first;
			max_second = q.front().second;
			q.push(q.front());
			q.pop();
			for (int k = 0; k < n; k++){
				if (max_second < q.front().second) { 
					max_first = q.front().first; 
					max_second = q.front().second;
				}
				q.push(q.front());
				q.pop();
			}
			if (m == max_first) {
				cnt++;  break;
			}
			else {
				for (int k = 0; k < q.size(); k++) {
					if (max_first == q.front().first) { q.pop(); cnt++; break; }
					else {
						q.push(q.front());
						q.pop(); 
					}
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}