#include<iostream>
#include<algorithm>

using namespace std;

typedef pair <int, string> book;

bool cmp(book a, book b) {
	if (a.first == b.first) return a.second < b.second; //second(책이름)은 알파벳순
	return a.first > b.first; //first(판매부수)가 더 큰수가 앞으로
}

int main() {

	int n, flag=0;
	cin >> n;

	int index = 0;
	book * seller = new book[n];

	for (int i = 0; i < n; i++) {
		flag = 0;
		string s;
		cin >> s;
		for (int j = 0; j < index; j++)
			if (seller[j].second == s) { 
				seller[j].first += 1; 
				flag = 1;
				break;
			}
		if (!flag)  //seller리스트에 없는 책이라면
			seller[index++] = { 1,s };
	}

	sort(seller, seller + index, cmp);

	cout << seller[0].second;

	return 0;
}