#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N, K;
    cin >> N >> K;
    int count = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int k = K - i - j;
            if(1 <= k && k <= N){
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}