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

    int position = N;
    vector<int> ans;
    ans.push_back(position);

    while(true){
        if(position == 1){
            break;
        }
        if(dp[position - 1] + abs(h[position] - h[position - 1]) == dp[position]){
            position--;
        }
        else if(dp[position - 2] + abs(h[position] - h[position - 2]) == dp[position]){
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