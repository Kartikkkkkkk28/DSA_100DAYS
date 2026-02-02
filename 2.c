#include <stdio.h>

int main() {
    int n, pos;
    int arr[1000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    for(int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    printf("Updated array: ");
    for(int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);

    return 0;
}
