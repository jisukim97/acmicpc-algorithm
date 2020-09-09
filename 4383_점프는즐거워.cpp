#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#pragma warning(disable:4996)

// Jolly Jumpers 문제 - 출력초과(??)
// 주어진 N개의 수가 든 배열에서, 각 인접한 두 수의 차이들에 1~N-1이 모두 포함되면 그것은 Jolly Jumper라고 함

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int flag = 1;

		int* arr = new int[n - 1]{ 0, };
		int tmp1, tmp2;
		scanf("%d",&tmp1);

		for (int i = 1; i < n; i++) {
			scanf("%d", &tmp2);
			int gap = tmp2 > tmp1 ? tmp2 - tmp1 : tmp1 - tmp2;
			if (gap >= n || arr[gap] == 1) {
				//두 수의 차가 n이상이거나
				//이미 존재하는 gap이면 더이상 볼 필요도 없이 NO
				flag = 0; break;
			}
			arr[gap] = 1;
			tmp1 = tmp2;
		}

		if (flag) printf("Jolly\n");
		else printf("Not jolly\n");
	}

	return 0;
}