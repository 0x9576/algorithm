#include<iostream>
using namespace std;

long long pow(int a, int b, int c) {
	if (b == 1)
		return a;
	if (b % 2)
		return pow(a, b / 2,c) % c * pow(a, b / 2,c) % c * a %c;
	return pow(a, b / 2,c) % c * pow(a, b / 2,c) %c;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << pow(a, b,c) % c;
	return 0;
}