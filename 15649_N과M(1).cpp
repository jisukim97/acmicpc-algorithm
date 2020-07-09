#include<iostream>

using namespace std;

bool promising(int k, int* a) {
    if (k < 1) return true;

    for (int i = 0; i < k; i++)
        if (a[i] == a[k]) return false;
    
    return true;
    
}

void permutation(int k, int n, int m, int* a) {
    if (promising(k,a)) {
        if (k == (m - 1)) {
            for (int i = 0; i < m; i++) cout << a[i] << " ";
            cout << "\n";
        }
        else {
            for (int i = 0; i < n; i++) {
                a[k + 1] = i + 1;
                permutation(k + 1, n, m, a);
            }
        }
    }
}

int main() {

    int* a;
    int N, M;
    cin >> N >> M;

    a = new int[M];

    for (int i = 0; i < N; i++) {
        a[0] = i + 1;
        permutation(0, N, M, a);
    }

    delete[] a;
    return 0;
}