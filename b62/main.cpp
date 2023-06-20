#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, M;
int A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];
vector<int> path, ans;

void dfs(int pos){
    visited[pos] = true;
    if(pos == N){
        ans = path;
        return;
    }
    for(int i = 0; i < G[pos].size(); i++){
        int next = G[pos][i];
        if(!visited[next]){
            path.push_back(next);
            dfs(next);
            path.pop_back();
        }
    }
    return;
}

int main(void){
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
    path.push_back(1);
    dfs(1);

    rep(i, ans.size()){
        if(i == ans.size() - 1){
            cout << ans[i];
        }
        else{
            cout << ans[i] << " ";
        }
    }

    return 0;
}