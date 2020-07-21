#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	string name;
	int korean;
	int english;
	int math;
}student;

struct cmp { //국어 점수 감소순 -> 영어 성적 증가순 -> 수학 점수 감소 순 -> 이름 증가 순
	bool operator()(student a, student b) {
		if (a.korean < b.korean) return true;
		else if (a.korean > b.korean) return false;
		else {
			if (a.english < b.english) return false;
			else if (a.english > b.english) return true;
			else {
				if (a.math < b.math) return true;
				else if (a.math > b.math) return false;
				else return a.name > b.name;
			}
		}
	}
};

int main() {

	int n;
	cin >> n;
	priority_queue<student, vector<student>, cmp> ranking;

	for (int i=0; i < n; i++) {
		student tmp;
		cin >> tmp.name >> tmp.korean >> tmp.english >> tmp.math;
		ranking.push(tmp);
	}

	while (!ranking.empty()) {
		cout << ranking.top().name << "\n";
		ranking.pop();
	}

	return 0;
}