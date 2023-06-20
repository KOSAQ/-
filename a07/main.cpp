#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int D;
    cin >> D;
    int N;
    cin >> N;

    vector<int> L(N, 0);
    vector<int> R(N, 0);

    rep(i, N){
        cin >> L[i] >> R[i];
    }

    vector<int> ratio(D + 1, 0);

    rep(i, N){
        ratio[L[i] - 1]++;
        ratio[R[i]]--;
    }

    vector<int> ans(D + 1, 0);
    ans[0] = 0;

    for(int i = 1; i < D + 1; i++){
        ans[i] = ans[i - 1] + ratio[i - 1];
    }

    for(int i = 1; i <= D; i++){
        cout << ans[i] << endl;
    }

    return 0;
}