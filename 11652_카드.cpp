#include<iostream>
#include<algorithm>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

typedef pair<long long, int> Card;
bool cmp(Card a, Card b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {

	int n;
	scanf("%d", &n);

	long long* input = new long long[n];
	Card* card = new Card[n]; //카드 들어온 순서대로

	//input 카드값 정리
	for (int i = 0; i < n; i++) 
		scanf("%lld", &input[i]);

	sort(input, input + n); 
	
	//초기값 하나 넣고 시작
	card[0] = { input[0],1 };
	int ptr = 0; //card 어디까지 저장했는지 기록

	for(int i=1; i<n;i++)
		if (card[ptr].first == input[i]) card[ptr].second++;
		else  //기존에 없는거면
			card[++ptr] = {input[i], 1};
	

	sort(card, card + ptr+1, cmp);

	printf("%lld", card[0].first);

	return 0;
}