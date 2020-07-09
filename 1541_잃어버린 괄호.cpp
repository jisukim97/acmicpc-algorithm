#include<iostream>
#include<string>

using namespace std;

int getNum(int* p, char* str) {
	int num =0;

	while (isdigit(str[*p]) && str[*p]!='\0') {
		num *= 10;
		num +=  str[*p] -'0';
		(*p)++;
	}
	return num;
}

int main() {

	int i=0, temp, sum=0;
	int* ptr = &i;
	char str[50];
	cin >> str;

	sum = getNum(ptr, str);

	while (str[i] != '\0') {
		if (str[i] == '+') {
			i++;
			sum += getNum(ptr, str);
		}
		else if(str[i]=='-'){
			i++;
			temp = getNum(ptr, str);
			while (str[i] == '+') {
				i++;
				temp += getNum(ptr, str);
			}
			sum -= temp; temp = 0;
		}
	}

	std:: cout << sum;

	return 0;
}