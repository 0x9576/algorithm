#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[20000];
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while (i <= q) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int a = p; a <= r; a++) arr[a] = tmp[a];
}

void mergeSort(int arr[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int arr[10001], i, N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            scanf("%d", arr + i);
        }
        mergeSort(arr, 0, N-1);
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        puts("");
    }
}