#include<iostream>

using namespace std;


int main() {

	int month, date;
	int total_dates = 0;
	cin >> month >> date;

	int* dates = new int[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	string* days = new string[7]{ "SUN","MON","TUE","WED","THU","FRI","SAT" };

	for (int i = 1; i < month; i++)  //month-1까지 해당 달 총 날짜수 더하기
		total_dates += dates[i - 1];
	total_dates += date; //현재 일 더하기

	cout << days[total_dates % 7];

	return 0;
}