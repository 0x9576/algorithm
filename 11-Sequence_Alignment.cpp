#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int M, G, axy;
		string X, Y;
		cin >> G >> M;
		cin >> X >> Y;
		int A[105][105] = { 0, };

		for (int i = 0; i <= X.size(); i++)
			A[i][0] = i * G;

		for (int i = 0; i <= Y.size(); i++)
			A[0][i] = i * G;

		for(int i = 1; i<= X.size(); i++)
			for (int j = 1; j <= Y.size(); j++) {
				axy = X[i-1] == Y[j-1] ? 0 : M;
				A[i][j] = min(A[i - 1][j - 1] + axy, min(A[i - 1][j] + G, A[i][j - 1] + G));
			}
		cout << A[X.size()][Y.size()] << endl;
	}
}