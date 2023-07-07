#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int main(void){
    int Q;
    string query[100009];
    string title[100009];
    stack<string> S;
    cin >> Q;
    
    rep2(i, 1, Q){
        cin >> query[i];
        if(query[i] == "1"){
            cin >> title[i];
        }
    }
    rep2(i, 1, Q){
        if(query[i] == "1"){
            S.push(title[i]);
        }
        else if(query[i] == "2"){
            cout << S.top() << endl;
        }
        else if(query[i] == "3"){
            S.pop();
        }
    }

    return 0;
}