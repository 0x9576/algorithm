#include<iostream>
using namespace std;
int T;
char L[4][2][2] = { {{'.','#'},{'#','#'}},{{'#','.'},{'#','#'}},{{'#','#'},{'#','.'}},{{'#','#'},{'.','#'}} };
int h, w, ans, ta, tb, la, lb;
char board[24][24],o[24][24];

void find() {
	for (int j = 1; j <= h; j++) {
		for (int k = 1; k <= w; k++) {
			if (board[j][k] == '.') {
				ta = j;
				tb = k;
				return;
			}
		}
	}
}

bool all_filled() {
	for (int i = 1; i < 24; i++)
		for (int j = 1; j < 24; j++)
			if (board[i][j] == '.')
				return false;
	return true;
}

bool possible(int z, int a, int b) {
	for (int j = 0; j < 2; j++)
		for (int k = 0; k < 2; k++) {
			if (L[z][j][k] == '#' && board[a + j][b + k] == '#') {
				//cout << "false"<<z<<endl;
				return false;
			}

		}
	//cout << "true"<<z<<endl;
	return true;
}

void cover(int a, int b) {
	cout << a << " " << b << endl;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++)
			cout << board[i][j];
		cout << endl;
	}
	cout << endl;
	if (all_filled()) {
		ans++;
	}

	//find(a, b);
	//cover(ta, tb);
	for (int i = 0; i < 4; i++)
		if (possible(i, a, b)) {
			//cout << i << endl;
			char nb[24][24] = { 0, };
			for (int j = 0; j < 24; j++)
				for (int k = 0; k < 24; k++)
					nb[j][k] = board[j][k];
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++) {
					if(L[i][j][k]=='#')
						board[a+j][b+k] = L[i][j][k];
					//cout << L[i][j][k];
				}
			//cout<<board[a][b]<<nb[a][b];
			//find(a,b);
			for (int j = 1; j <= h; j++) {
				for (int k = 1; k <= w; k++) {
					if(board[j][k]=='.')
						cover(j, k);
				}
			}
			for (int c = 0; c < 2; c++)
				for (int d = 0; d < 2; d++)
					board[a + c][b + d] = nb[a + c][b + d];

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
			for (int j = 1; j <= w; j++) {
				cin >> board[i][j];
				o[i][j] = board[i][j];
				if (board[i][j] == '.') {
					la = i;
					lb = j;
				}
			}
		/*for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cout << board[i][j]*/
		find();
		//cout << L[2][1][1];
		//cout << ta << " " << tb << endl;
		cover(ta, tb);
		cout << ans << endl;
	}
}