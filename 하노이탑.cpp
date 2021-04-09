#include<iostream>
using namespace std;
int ans = 0;
bool complete = false;
void move(int s, int tmp, int d, int N) {
	if (N == 1) {
		if(complete)
			printf("%d %d\n", s, d);
		ans++;
	}

	else {
		move(s, d, tmp, N - 1);
		move(s, tmp, d, 1);
		move(tmp, s, d, N - 1);
	}

}

int main() {
	int N;
	cin >> N;
	move(1, 2, 3, N);
	complete = true;
	cout << ans << endl;
	move(1, 2, 3, N);
}