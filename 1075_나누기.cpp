#include<iostream>

using namespace std;

int main()
{
	int n, f;
	cin >> n >> f;

	int ans = f - ((n/100)*100) % f;

	if (ans == f) // f에서 0을 뺏다는 것은 뒷자리가 00일때 f의 배수라는 뜻
		cout << "00";
	else if (ans < 10) // ~00에서 더해야할 수가 한자리 수면 앞에 0추가 출력 
		cout << "0"<<ans;
	else //아니면 전부 출력
		cout << ans;
	
	return 0;
}