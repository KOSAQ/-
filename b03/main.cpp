#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int main(void){
    int N;
    int A[109];
    cin >> N;
    rep2(i, 1, N){
        cin >> A[i];
    }
    bool flag = false;

    rep2(i, 1, N){
        rep2(j, i + 1, N){
            rep2(k, j + 1, N){
                if(A[i] + A[j] + A[k] == 1000){
                    flag = true;
                }
            }
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }


    return 0;
}