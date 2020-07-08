#include<stdio.h>
#pragma warning(disable:4996)

int main() {

	int coin[10];
	int i, K, N;
	int cnt = 0;


	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
		scanf("%d", coin + i);

	for (i = N-1; i >= 0; i--)  //i번째 동전, 큰거 부터
		while (coin[i] <= K) {
			K -= coin[i];
			cnt++;
		}
	

	printf("%d", cnt);

	return 0;
}