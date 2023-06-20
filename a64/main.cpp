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
        confirm[i] = false;
        cur[i] = 2000000000;
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

    for(int i = 1; i <= N; i++){
        if(cur[i] == 2000000000){
            cout << "-1" << endl;
        }
        else{
            cout << cur[i] << endl;
        }
    }

    return 0;
}