#include<iostream>

using namespace std;


int main() {
	
	int cost;
	cin >> cost;
	cost = 1000 - cost;

	int* coin = new int[6]{ 500,100,50,10,5,1 };
	int cnt = 0;

	for (int i = 0; i < 6; i++) 
		while (cost >= coin[i]) {
			cost -= coin[i];
			cnt++;
		}
	
	cout << cnt;
	

	return 0;
}