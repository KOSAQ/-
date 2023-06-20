#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> A(100009, 0);
    vector<int> B(100009, 0);
    vector<int> G[100009];
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
    }
    for(int i = 1; i <= M; i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++){
        sort(G[i].begin(), G[i].end());
    }

    for(int i = 1; i <= N; i++){
        cout << i << ": {";
        for(int j = 0; j < G[i].size(); j++){
            if(j != G[i].size() - 1){
                cout << G[i][j] << ", ";
            }
            else{
                cout << G[i][j];
            }
        }
        cout << "}" << endl;
    }



    return 0;
}