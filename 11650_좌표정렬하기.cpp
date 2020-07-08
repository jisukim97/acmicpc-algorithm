#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Point {
	int x;
	int y;
}point;

bool compare(const point& first, const point& second) {
	if (first.x < second.x) return true;
	else if (first.x == second.x) return first.y < second.y;
	else return false;
}

int main() {

	point* array;
	int n, i;
	std::cin >> n;

	array = new point[n];

	for (i = 0; i < n; i++)
		std::cin >> array[i].x >> array[i].y;

	stable_sort(array, array + n, compare);

	for (i = 0; i < n; i++) 
		std::cout << array[i].x <<" "<< array[i].y<<"\n";
	

	delete [] array;
	return 0;
}