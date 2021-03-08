#include<iostream>
using namespace std;
int T;
char L[4][2][2] = { {{'.','#'},{'#','#'}},{{'#','.'},{'#','#'}},{{'#','#'},{'#','.'}},{{'#','#'},{'.','#'}} };
int h, w,ans;
char board[24][24];

bool all_filled() {
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 24; j++)
			if (board[i][j] == '.')
				return false;
	return true;
}

bool possible(int z, int a, int b) {
	for (int j = 0; j < 2; j++)
		for (int k = 0; k < 2; k++) {
			if (L[z][j][k] == '#' && board[a + j][b + k] == '#')
				return false;
		}
	return true;
}

void cover(int a, int b) {
	//cout << a << " " << b << endl;
	if (b > w-1) {
		b = 0;
		a++;
	}
	if (a == h-1 && b == w-1) {
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				cout << board[i][j];
			cout << endl;
		}
		cout << endl;

		if (all_filled())
			ans++;
		return;
	}

	for (int i = 0; i < 4; i++)
		if (possible(i, a, b)) {
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					board[a + j][b + k] = L[i][j][k];
			for (int i = a; i <= h; i++)
				for (int j = b; j <= w; j++)
					if (board[i][j] == '.')
						cover(i, j);
		}


}

int main() {
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> h >> w;
		for (int i = 0; i < 24; i++)
			for (int j = 0; j < 24; j++)
				board[i][j] = '#';
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				scanf("%c", board[i] + j);

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if(board[i][j] == '.')
					cover(i,j);
		cout << ans << endl;
	}
}