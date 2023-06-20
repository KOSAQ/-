#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int A[100009];
int B[100009];
vector<int> G[100009];
bool visited[100009];

void dfs(int pos){
    visited[pos] = true;
    rep(i, G[pos].size()){
        int next = G[pos][i];
        if(!visited[next]){
            dfs(next);
        }
    }
    return;
}

int main(void){
    int N, M;
    cin >> N >> M;
    rep(i, M){
        cin >> A[i] >> B[i];
    }
    rep(i, M){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
    dfs(1);
    string ans = "The graph is connected.";
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            ans = "The graph is not connected.";
        }
    }
    cout << ans << endl;
    return 0;
}