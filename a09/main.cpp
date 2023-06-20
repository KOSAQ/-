#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(100009, 0);
    vector<int> B(100009, 0);
    vector<int> C(100009, 0);
    vector<int> D(100009, 0);
    vector<vector<int> > X(1509, vector<int>(1509, 0));
    vector<vector<int> > cum(1509, vector<int>(1509, 0));
    rep(i, N){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }


    rep(i, N){
        X[A[i]][B[i]]++;
        X[C[i] + 1][D[i] + 1]++;
        X[A[i]][D[i] + 1]--;
        X[C[i] + 1][B[i]]--;
    }
    //(1,1),(4,4),(2,2),(5,5)++ 
    //(1,4),(4,1),(2,5),(5,2)--

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cum[i][j] = cum[i][j - 1] + X[i][j];
        }
    }
    for(int j = 1; j <= W; j++){
        for(int i = 1; i <= H; i++){
            cum[i][j] += cum[i - 1][j];
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cout << cum[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}