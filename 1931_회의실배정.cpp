#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Time {
	int x;
	int y;
}time;

bool compare(const time& first, const time& second) {
	if (first.y < second.y) return true;
	else if (first.y == second.y) return first.x < second.x;
	else return false;
}

int main() {

	time* array;
	int n, i, latest=0, cnt=0;
	cin >> n;

	array = new time[n];

	for (i = 0; i < n; i++)
		cin >> array[i].x >> array[i].y;

	stable_sort(array, array + n, compare);

	for (i = 0; i < n; i++)
		if (array[i].x >= latest) {
			cnt++; latest = array[i].y;
		}

	cout << cnt;

	delete [] array;
	return 0;
}
