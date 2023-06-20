#include <iostream>
using namespace std;

int N;
int A[100009], B[100009], C[100009], D[100009];
int T[1509][1509];
 
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) T[i][j] = 0;
	}
	for (int i = 1; i <= N; i++) {
		T[A[i]][B[i]]++;
		T[A[i]][D[i]]--;
		T[C[i]][B[i]]--;
		T[C[i]][D[i]]++;
	}

	for (int i = 0; i <= 1500; i++) {
		for (int j = 1; j <= 1500; j++){
            T[i][j] += T[i][j - 1];
        }
	}
	for (int i = 1; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++){
            T[i][j] += T[i - 1][j];
        }
	}

	int Answer = 0;
	for (int i = 0; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) {
			if (T[i][j] >= 1){
                Answer += 1;
            }
		}
	}
	cout << Answer << endl;
	return 0;
}

