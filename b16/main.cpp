#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int main(void){
    int N;
    int h[100009];
    cin >> N;
    rep2(i, 1, N){
        cin >> h[i];
    }

    int dp[100009];
    dp[1] = 0;
    dp[2] = dp[1] + abs(h[2] - h[1]);
    rep2(i, 3, N){
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[N] << endl;
    return 0;
}