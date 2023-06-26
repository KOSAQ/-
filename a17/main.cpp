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

    int position = N;
    vector<int> ans;
    ans.push_back(position);

    while(true){
        if(position == 1){
            break;
        }
        if(dp[position - 1] + A[position] == dp[position]){
            position--;
        }
        else if(dp[position - 2] + B[position] == dp[position]){
            position -= 2;
        }
        ans.push_back(position);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}