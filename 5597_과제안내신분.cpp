#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


int main() {

    int* submit_student = new int[28]{ 0 };
    priority_queue<int, vector<int>, greater<int> > no;

    for (int i = 0; i < 28; i++) {
        int tmp;
        cin >> tmp;
        submit_student[i] = tmp;
    }

    sort(submit_student, submit_student + 28);

    int num = 1, cnt=0;
    for (int i = 0; i<28 ; i++, num++)
        while (submit_student[i] != num) {
            no.push(num); cnt++;
            num++;
        }

    if (cnt == 0) {
        no.push(29); no.push(30);
    }
    else if (cnt == 1) no.push(30);

    while (!no.empty()) {
        cout << no.top()<<"\n";
        no.pop();
    }

    return 0;
}