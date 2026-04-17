#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Store prefix sum and its first index
    int hash[MAX] = {0};
    int used[MAX] = {0};

    // Offset to handle negative sums
    int offset = MAX / 2;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0 from start
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: seen before
        if (used[prefixSum + offset]) {
            int prevIndex = hash[prefixSum + offset];
            int len = i - prevIndex;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // Store first occurrence
            hash[prefixSum + offset] = i;
            used[prefixSum + offset] = 1;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}