#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end) {
    int low = start, high = mid + 1, idx = start, tem[20000] = { 0, };
    while (low <= mid || high <= end) {
        if (arr[low] < arr[high])
            tem[idx++] = arr[low++];
        else
            tem[idx++] = arr[high++];
    }
    while (low <= mid) tem[idx++] = arr[low++];
    while (high <= end) tem[idx++] = arr[high++];
    for (int i = start; i <= end; i++)
        arr[i] = tem[i];
}

void merge_sort(int *arr, int start, int end) {
    int mid = (start + end) / 2;
    if (start < end) {
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int arr[10001], N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            scanf("%d", arr + i);
        }
        merge_sort(arr, 0, N-1);
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        puts("");
    }
}