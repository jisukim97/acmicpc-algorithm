#include<iostream>
#include<queue>

using namespace std;


int main() {

	int kg;
	cin >> kg;

	int tot;
	priority_queue<int, vector<int>, greater<int> >q;

	for (int i = 0; (5 * i) <= kg; i++) 
		for (int j = 0; (5 * i + 3 * j) <= kg; j++) {
			int rest = kg;
			if (i > 0)
				rest -= 5 * i;
			if (j > 0) 
				rest -= 3 * j;
			if (!rest) 
				q.push(i+j);
		}
	
	if (q.empty()) cout << -1;
	else cout << q.top();

	return 0;
}