#include<iostream>
using namespace std;

void merge(int *arr, int p, int q, int r) {
	//i = p ~ q , j = q+1 ~ r
	//k는 tmp의 배열 포인터를 나타내기 때문에 i처럼 p로 시작
	int *tmp = new int [r-p+1]; //정리된 것을 임시로 담아두는 배열이다.
	int i = p, j = q + 1, k = 0;
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) tmp[k++] = arr[i++]; //두개의 포인터를 비교하여 더 작은 것부터 먼저 담는다.
		else tmp[k++] = arr[j++];
	}
	while (i <= q) tmp[k++] = arr[i++];
	while (j <= r) tmp[k++] = arr[j++];
	for (int i = p; i <= r; i++) //배열된 것을 옮기는 과정이다.
		arr[i] = tmp[i-p];
}

void merge_sort(int *arr, int p, int r) { // p는 시작점이고 r은 끝점이다.
	if (p < r) {
		int q = (p + r) / 2; // p와 r의 정확히 중간지점에 있는 q를 선언한다.
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r); //분할정복을 통해 정렬
		merge(arr, p, q, r); //그렇게 분할 된 것을 합병하는 과정이다.
	}
}

int main() {
	int test[6] = {4,5,1,2,3,1};
	merge_sort(test, 0, 5);
	for (int i = 0; i < 6; i++)
		cout << test[i] << " ";
	cout << endl;
}