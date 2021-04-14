#include<iostream>
#include<string>
using namespace std;

string rev(string::iterator& it) {
	char first = *it;
	++it;
	if (first != 'x')
		return string(1, first);
	string upper_left = rev(it);
	string upper_right = rev(it);
	string lower_left = rev(it);
	string lower_right = rev(it);

	return "x" + lower_left + lower_right + upper_left + upper_right;
}

int main() {
	int T;
	string str;
	cin >> T;
	while (T--) {
		cin >> str;
		string::iterator it = str.begin();
		cout << rev(it) << endl;
	}
}