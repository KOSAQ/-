#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, M;
int A[100009], B[100009];
vector<int> G[100009];
int dist[100009];
queue<int> Q;


int main(void){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
    }
    for(int i = 1; i <= M; i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++){
        dist[i] = -1;
    }
    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        rep(i, G[pos].size()){
            int next = G[pos][i];
            if(dist[next] == -1){
                dist[next] = dist[pos] + 1;
                Q.push(next);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << dist[i] << endl;
    }
    return 0;
}