#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N;
    cin >> N;
    vector<int> A(100009, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    int D;
    cin >> D;
    vector<int> L(100009, 0);
    vector<int> R(100009, 0);
    for(int i = 1; i <= D; i++){
        cin >> L[i] >> R[i];
    }

    vector<int> cummaxleft(100009, 0);
    vector<int> cummaxright(100009, 0);

    for(int i = 1; i <= N; i++){
        cummaxleft[i] = max(A[i], cummaxleft[i - 1]);
    }
    for(int i = N; i >= 1; i--){
        cummaxright[i] = max(cummaxright[i + 1], A[i]);
    }

    for(int i = 1; i <= D; i++){
        cout << max(cummaxleft[L[i] - 1], cummaxright[R[i] + 1]) << endl;
    }

    return 0;
}