#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> S(N + 1);

    rep(i,N){
        cin >> A[i];
    }

    vector<int> L(Q);
    vector<int> R(Q);

    rep(i, Q){
        cin >> L[i] >> R[i];
    }

    S[0] = 0;
    for(int i = 0; i < N; i++){
        S[i + 1] = S[i] + A[i]; 
    }

    rep(i, Q){
        cout << S[R[i]] - S[L[i] - 1] << endl;
    }
    return 0;
}