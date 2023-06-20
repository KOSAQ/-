#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> A(100009, 0);
    vector<int> B(100009, 0);
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
    }
    vector<int> G[100009];

    for(int i = 1; i <= M; i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    int ans = 0;
    int max = 0;

    for(int i = 1; i <= N; i++){
        if(G[i].size() > max){
            max = G[i].size();
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}