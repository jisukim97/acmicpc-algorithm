#include<iostream>
#include<queue>
using namespace std;

typedef pair<pair<int, int>, string> User;

struct cmp {
	bool operator()(User a, User b) {
		if (a.first.first != b.first.first) return a.first.first > b.first.first;
		return a.first.second > b.first.second;
	}
};

int main() {

	
	priority_queue<User,vector<User>, cmp > user;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		user.push({ { age,i }, name });
	}

	while (!user.empty()) {
		cout << user.top().first.first << " " << user.top().second<<"\n";
		user.pop();
	}

	return 0;
}