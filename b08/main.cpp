#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N, Q;
    cin >> N;
    vector<vector<int> > point(100009, vector<int>(2, 0));
    rep(i, N){
        cin >> point[i][0] >> point[i][1];
    }

    cin >> Q;
    vector<vector<int> > query(100009, vector<int>(4, 0));
    rep(i, Q){
        cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];
    }

    vector<vector<int> > A(1509, vector<int>(1509, 0));
    rep(i, N){
        A[point[i][0]][point[i][1]]++;
    }
    vector<vector<int> > B(1509, vector<int>(1509, 0));

    for(int i = 1; i < 1509; i++){
        for(int j = 1; j < 1509; j++){
            B[i][j] = B[i - 1][j] + A[i][j];
        }
    }

    for(int j = 1; j < 1509; j++){
        for(int i = 1; i < 1509; i++){
            B[i][j] += B[i][j - 1];
        }
    }

    

    rep(i, Q){
        cout << B[query[i][2]][query[i][3]] + B[query[i][0] - 1][query[i][1] - 1] - B[query[i][0] - 1][query[i][3]] - B[query[i][2]][query[i][1] - 1] << endl;
    }


    return 0;
}