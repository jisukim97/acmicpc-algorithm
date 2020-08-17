#include<iostream>

using namespace std;

int* removed; //index+1이 해당 번호의 사람에 대한 정보

int main() {

	int n, k;
	cin >> n >> k;

	removed = new int[n] {0};


	int cnt_tot = 0; //전체 삭제 횟수
	int cnt_tmp = 0; //한번 지울때 k번째를 찾기 위함
	int i = 0;

	cout << "<";
	while (cnt_tot != n) {

		if (i >= n) i = i % n;
		if (removed[i]!=1) cnt_tmp++;

		if (cnt_tmp == k) {
			cout << i + 1;
			removed[i] = 1;
			cnt_tmp = 0;
			cnt_tot++;
			if (cnt_tot != n) cout << ", ";
		}
		i++;
	}

	cout << ">";

	return 0;
}