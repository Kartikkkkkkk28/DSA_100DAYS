#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(n == 0) return 0;

    int i = 0;  // index of last unique element

    for(int j = 1; j < n; j++) {
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    // print unique elements
    for(int k = 0; k <= i; k++)
        printf("%d ", arr[k]);

    return 0;
}
