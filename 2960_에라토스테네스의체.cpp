#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;


int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    int* arr = new int[n - 1]{ 0 }; //지우면 1로 변환, index+2가 실제값
    int cnt = 0, flag=0;
    int i, j;

    for (i = 0; i < (n-1); i++) {
        int prime=0;
        for (j = 0; j < (n-1); j++) {
            if (prime==0 &&!arr[j]) { prime = j + 2; arr[j] = 1; cnt++; }
            else if(prime!=0 && !arr[j] && (j + 2) % prime == 0) { arr[j] = 1; cnt++; }
            if (cnt == k) {
                flag = 1; break;
            }
        }
        if (flag) break;
    }

    cout << j + 2;

    return 0;
}