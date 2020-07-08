#include<iostream>
#include<stack>
#include<string>

using namespace std;

int flag, flag2;
stack<int>ps;

void YesOrNo() {
	if (!ps.empty() || !flag) {
		cout << "no\n";
		while (!ps.empty()) ps.pop();
		flag = 1;
	}
	else cout << "yes\n";
	flag2 = 0;
}

int main() {

	flag = 1;
	flag2 = 1;
	string line;
	
	while(true){
		getline(cin, line);
		if (line[0] == 46 && !flag2) break;

		for (int j = 0; j < line.size(); j++) {
			flag2 = 1;
			if (line[j] == 40 || line[j] == 91 || line[j] == 123 || line[j] == 60)
				ps.push(line[j]);
			else if (line[j] == 41) {
				if (ps.empty() || ps.top() != 40) flag = 0;
				else if (ps.top() == 40) ps.pop();
			}
			else if (line[j] == 93 || line[j] == 125 || line[j] == 62) {
				if (ps.empty()||ps.top()!=line[j]-2) flag = 0;
				else if (ps.top() == line[j] - 2) ps.pop();
			}
			else if (line[j] == 46) YesOrNo();
		}
	}
	return 0;
}