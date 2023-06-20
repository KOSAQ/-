#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }
    int Q;
    cin >> Q;
    vector<int> L(Q);
    vector<int> R(Q);

    rep(i, Q){
        cin >> L[i] >> R[i];
    }

    vector<int> S(N + 1, 0);

    rep(i, N){
        S[i + 1] = S[i] + A[i];
    }

    rep(i, Q){
        if((S[R[i]] - S[L[i] - 1]) * 2 > (R[i] - L[i] + 1)){
            cout << "win" << endl;
        }
        else if((S[R[i]] - S[L[i] - 1]) * 2 < (R[i] - L[i] + 1)){
            cout << "lose" << endl;
        }
        else{
            cout << "draw" << endl;
        }
    }

    return 0;
}