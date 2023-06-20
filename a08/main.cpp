#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int H, W;
    cin >> H >> W;
    vector<vector<int> > X(1509, vector<int>(1509, 0));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> X[i][j];
        }
    }
    int Q;
    cin >> Q;
    vector<vector<int> > query(100009, vector<int>(4, 0));
    rep(i, Q){
        rep(j, 4){
            cin >> query[i][j];
        }
    }

    vector<vector<int> > Y(1509, vector<int>(1509, 0));
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            Y[i][j] = Y[i][j - 1] + X[i][j];
        }
    }

    for(int j = 1; j <= W; j++){
        for(int i = 1; i <= H; i++){
            Y[i][j] += Y[i - 1][j];
        }
    }

    rep(i, Q){
        cout << Y[query[i][2]][query[i][3]] + Y[query[i][0] - 1][query[i][1] - 1] - Y[query[i][0] - 1][query[i][3]] - Y[query[i][2]][query[i][1] - 1] << endl;
    }

    return 0;
}