#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int R, C;
int sy, sx;
int gy, gx;
char c[59][59];
int start, goal;

vector<int> G[2509];
int dist[2509];

int main(void){
    cin >> R >> C;
    cin >> sx >> sy;
    cin >> gx >> gy;
    start = sx * C + sy;
    goal = gx * C + gy;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C - 1; j++){
            int a = i * C + j;
            int b = i * C + (j + 1);
            if(c[i][j] == '.' && c[i][j + 1] == '.'){
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
    }
    for(int i = 1; i <= R - 1; i++){
        for(int j = 1; j <= C; j++){
            int a = i * C + j;
            int b = (i + 1) * C + j;
            if(c[i][j] == '.' && c[i + 1][j] == '.'){
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
    }

    for(int i = 1; i <= C * R; i++){
        dist[i] = -1;
    }

    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

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

    cout << dist[goal] << endl;
    return 0;
}