#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    string N;
    cin >> N;
    int ans = 0;

    for(int i = 0; i < N.size(); i++){
        if(N[i] == '1'){
            ans += pow(2, N.size() - 1 - i);
        }
    }
    cout << ans << endl;

    return 0;
}