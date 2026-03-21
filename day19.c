/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>

int main() {
    int n;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int left = 0, right = n - 1;
    int resLeft = arr[0], resRight = arr[1];
    int minSum = arr[0] + arr[1];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum * sum < minSum * minSum) {
            minSum = sum;
            resLeft = arr[left];
            resRight = arr[right];
        }

        if (sum < 0) left++;
        else right--;
    }

    printf("Pair closest to zero: %d %d\n", resLeft, resRight);
    return 0;
}