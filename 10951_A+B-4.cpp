#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

int main(){
    //입력 종료 조건 없이 입력받고 결과출력하기
    
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", a+b);
    }
    
    return 0;
}