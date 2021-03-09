#include<iostream>
#include<vector>
using namespace std;
int T;
char L[5][2][2] = { {{'.','#'},{'#','#'}},{{'#','.'},{'#','#'}},{{'#','#'},{'#','.'}},{{'#','#'},{'.','#'}},{{'.','.'},{'.','.'}} };
int h, w, ans;
char board[24][24];

vector<pair<int, int>> v;

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
				return false;
			}

		}
	return true;
}

void cover(int s) {
	int a = v[s].first;
	int b = v[s].second;
	if (s == v.size() - 1) {
		if (all_filled()) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			if (board[i][j] == '.' && i < a)
				return;
		}

	int co = 0;
	for (int i = 0; i < 5; i++)
		if (possible(i, a, b)) {
			char nb[24][24] = { 0, };
			for (int j = 0; j < 24; j++)
				for (int k = 0; k < 24; k++)
					nb[j][k] = board[j][k];
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++) {
					if (L[i][j][k] == '#')
						board[a + j][b + k] = L[i][j][k];
				}
			co++;
			if (s + 1 < v.size())
				cover(s + 1);
			for (int c = 0; c < 2; c++)
				for (int d = 0; d < 2; d++)
					board[a + c][b + d] = nb[a + c][b + d];
		}
}

int main() {
	cin >> T;
	while (T--) {
		v.clear();
		ans = 0;
		cin >> h >> w;
		for (int i = 0; i < 24; i++)
			for (int j = 0; j < 24; j++)
				board[i][j] = '#';
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) {
				cin >> board[i][j];
				v.push_back({ i,j });
			}
		if (!v.empty())
			cover(0);
		else
			ans = 1;
		cout << ans << endl;
	}
}