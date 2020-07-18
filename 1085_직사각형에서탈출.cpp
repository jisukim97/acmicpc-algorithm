#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int* array = new int[4]{ x,y,w - x, h - y };

	sort(array, array + 4);

	cout << array[0];

	return 0;
}