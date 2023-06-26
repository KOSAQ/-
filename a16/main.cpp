#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int main(void){
    int N;
    int A[100009];
    int B[100009];

    cin >> N;
    rep2(i, 2, N){
        cin >> A[i];
    }
    rep2(i, 3, N){
        cin >> B[i];
    }

    int dp[100009];

    dp[1] = 0;
    dp[2] = dp[1] + A[2];
    rep2(i, 3, N){
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
    }
    cout << dp[N] << endl;

    return 0;
}