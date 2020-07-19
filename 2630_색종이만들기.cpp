#include<iostream>

using namespace std;

int** color; //색칠된 종이
int cnt_white;
int cnt_blue;
int n;

int checker(int row, int col, int num) { //i행 j열부터 n개의 행/열이 모두 같은 색인지 판단하는 함수
	int stand = color[row][col]; //판단의 기준이 되는 첫번째 원소
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			if (color[row+i][col+j] != stand) return -1; //다르면 -1 반환
	return stand; //다 같으면 파랑색이면 1, 흰색이면 0 반환
}

void divide(int row, int col, int num) {
	if (checker(row, col, num) == 1) cnt_blue++;
	else if (checker(row, col, num) == 0) cnt_white++;
	else {
		int num2 = num / 2;
		divide(row, col, num2);
		divide(row + num2, col, num2);
		divide(row, col + num2, num2);
		divide(row + num2, col + num2, num2);
	}
}

int main() {
	
	cin >> n;
	color = new int* [n];
	for (int i = 0; i < n; i++)
		color[i] = new int[n] {0};
	cnt_white = 0;
	cnt_blue = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> color[i][j];
	
	divide(0, 0, n);

	cout << cnt_white << "\n" << cnt_blue;

	return 0;
}