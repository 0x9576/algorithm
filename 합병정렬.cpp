#include<iostream>
using namespace std;

void merge(int *arr, int p, int q, int r) {
	//i = p ~ q , j = q+1 ~ r
	//k�� tmp�� �迭 �����͸� ��Ÿ���� ������ ió�� p�� ����
	int *tmp = new int [r-p+1]; //������ ���� �ӽ÷� ��Ƶδ� �迭�̴�.
	int i = p, j = q + 1, k = 0;
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) tmp[k++] = arr[i++]; //�ΰ��� �����͸� ���Ͽ� �� ���� �ͺ��� ���� ��´�.
		else tmp[k++] = arr[j++];
	}
	while (i <= q) tmp[k++] = arr[i++];
	while (j <= r) tmp[k++] = arr[j++];
	for (int i = p; i <= r; i++) //�迭�� ���� �ű�� �����̴�.
		arr[i] = tmp[i-p];
}

void merge_sort(int *arr, int p, int r) { // p�� �������̰� r�� �����̴�.
	if (p < r) {
		int q = (p + r) / 2; // p�� r�� ��Ȯ�� �߰������� �ִ� q�� �����Ѵ�.
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r); //���������� ���� ����
		merge(arr, p, q, r); //�׷��� ���� �� ���� �պ��ϴ� �����̴�.
	}
}

int main() {
	int test[6] = {4,5,1,2,3,1};
	merge_sort(test, 0, 5);
	for (int i = 0; i < 6; i++)
		cout << test[i] << " ";
	cout << endl;
}