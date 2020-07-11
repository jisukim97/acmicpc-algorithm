#include<iostream>
#include<string>

using namespace std;


int main() {

    int tc_N;
    cin >> tc_N;

    for (int i = 0; i < tc_N; i++) {
        string s;
        cin >> s;
        long long score = 0;
        long long tmp = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 79) tmp++;
            else tmp = 0;
            score += tmp;
        }
        cout << score << "\n";
    }

    return 0;
}