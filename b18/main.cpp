#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int main(void){
    int N, S;
    cin >> N >> S;
    int A[69];
    rep2(i, 1, N){
        cin >> A[i];
    }

    bool dp[69][10009];
    dp[0][0] = true;
    rep2(i, 1, S){
        dp[0][i] = false;
    }
    rep2(i, 1, N){
        rep2(j, 0, S){
            if(j < A[i]){
                if(dp[i - 1][j]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
            if(j >= A[i]){
                if(dp[i - 1][j] || dp[i - 1][j - A[i]]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
    }

    vector<int> ans;

    
    if(dp[N][S] == false){
        cout << "-1" << endl;
        return 0;
    }

    int sum = S;
    for(int i = N; i >= 1; i--){
        if(dp[i - 1][sum] == false){
            sum -= A[i];
            ans.push_back(i);
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}