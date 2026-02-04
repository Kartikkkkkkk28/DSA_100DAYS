#include <stdio.h>

int main() {
    int n;

    // input size
    scanf("%d", &n);

    int arr[n];

    // input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = n - 1;

    // reverse using two pointers
    while(left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // print reversed array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
