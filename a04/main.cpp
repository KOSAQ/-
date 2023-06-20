#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N;
    cin >> N;

    for(int i = 9; i >= 0; i--){
        int div = (1 << i);
        cout << (N / div) % 2;
    }
    cout << endl;

    return 0;
}