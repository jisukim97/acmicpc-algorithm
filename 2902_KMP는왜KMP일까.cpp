#include<iostream>

using namespace std;


int main() {

    string longer,shorter;
    cin >> longer;

    shorter += longer[0];
    for (int i = 1; i < longer.size(); i++) 
        if (longer[i] == 45) shorter += longer[++i];
    
    cout << shorter;

    return 0;
}