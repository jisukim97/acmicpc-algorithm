#include<stdio.h>
#pragma warning(disable:4996)

int main() {

	int si, boon;

	scanf("%d %d", &si, &boon);

	if (boon >= 45) boon -= 45;
	else {
		if (si >= 1) {
			si -= 1; boon += 15;
		}
		else {
			si = 23; boon += 15;
		}
	}

	printf("%d %d", si, boon);



	return 0;
}