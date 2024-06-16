#include <stdio.h>

void QuickSort(int arr[], int left, int right);
void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int center, int right);

int main() {
    int i, n, choice, arr[20];
    
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Choose the sorting algorithm:\n");
    printf("1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            QuickSort(arr, 0, n - 1);
            break;
        case 2:
            MergeSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    
    printf("The sorted elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void QuickSort(int arr[], int left, int right) {
    int i, j, temp, pivot;
    if (left < right) {
        pivot = left;
        i = left + 1;
        j = right;
        while (i < j) {
            while (i <= right && arr[i] < arr[pivot]) i++;
            while (arr[j] > arr[pivot]) j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        QuickSort(arr, left, j - 1);
        QuickSort(arr, j + 1, right);
    }
}

void MergeSort(int arr[], int left, int right) {
    int center;
    if (left < right) {
        center = (left + right) / 2;
        MergeSort(arr, left, center);
        MergeSort(arr, center + 1, right);
        Merge(arr, left, center, right);
    }
}

void Merge(int arr[], int left, int center, int right) {
    int a[20], b[20], n1, n2, aptr, bptr, cptr, i, j;
    n1 = center - left + 1;
    n2 = right - center;
    for (i = 0; i < n1; i++) {
        a[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        b[j] = arr[center + 1 + j];
    }
    aptr = 0;
    bptr = 0;
    cptr = left;
    while (aptr < n1 && bptr < n2) {
        if (a[aptr] <= b[bptr]) {
            arr[cptr] = a[aptr];
            aptr++;
        } else {
            arr[cptr] = b[bptr];
            bptr++;
        }
        cptr++;
    }
    while (aptr < n1) {
        arr[cptr] = a[aptr];
        aptr++;
        cptr++;
    }
    while (bptr < n2) {
        arr[cptr] = b[bptr];
        bptr++;
        cptr++;
    }
}
