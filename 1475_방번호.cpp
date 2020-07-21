#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string num; //다솜이의 방번호
	cin >> num;
	
	int* arr = new int[10]{ 0 }; //각 인덱스의 숫자가 필요한 개수 저장

	int six_or_nine=0, len = num.size();
	for (int i = 0; i < len; i++) {
		int tmp = num[i] - '0';
		if (tmp == 6 || tmp == 9) six_or_nine++;
		else arr[tmp]++;

	}
	
	sort(arr, arr + 10);
	six_or_nine = (six_or_nine % 2 == 0) ? six_or_nine / 2 : six_or_nine / 2 + 1;

	if (six_or_nine < arr[9]) cout << arr[9];
	else cout<< six_or_nine;
	
	return 0;
}