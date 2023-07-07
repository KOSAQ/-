#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int main(void){
    string S;
    cin >> S;
    stack<int> stk;
    rep(i, S.size()){
        if(S[i] == '('){
            stk.push(i + 1);
        }
        else if(S[i] == ')'){
            int n = stk.top();
            cout << n << " " << i + 1 << endl;
            stk.pop();
        }
    }
    
    return 0;
}