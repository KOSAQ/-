#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, M;
int A[100009], B[100009], C[100009];
vector<pair<int, int> > G[100009];

int cur[100009];
bool confirm[100009];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

int main(void){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    for(int i = 1; i <= M; i++){
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }

    for(int i = 1; i <= N; i++){
        cur[i] = 2000000000;
        confirm[i] = false;
    }

    cur[1] = 0;
    Q.push(make_pair(cur[1], 1));

    while(!Q.empty()){
        int pos = Q.top().second;
        Q.pop();
        if(confirm[pos]){
            continue;
        }
        confirm[pos] = true;
        rep(i, G[pos].size()){
            int next = G[pos][i].first;
            int cost = G[pos][i].second;
            if(cur[pos] + cost < cur[next]){
                cur[next] = cur[pos] + cost;
                Q.push(make_pair(cur[next], next));
            }
        }
    }

    

    
    vector<int> ans;
    int point = N;
    while(point != 1){
        ans.push_back(point);
        rep(i, G[point].size()){
            int next = G[point][i].first;
            int cost = G[point][i].second;
            if(cur[next] + cost == cur[point]){
                point = next;
                break;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << "1" << " ";
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }
    

    return 0;
}