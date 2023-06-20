#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N, X;
    cin >> N >> X;
    int A[109];
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    bool flag = false;
    for(int i = 1; i <= N; i++){
        if(A[i] == X){
            flag = true;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    

    return 0;
}