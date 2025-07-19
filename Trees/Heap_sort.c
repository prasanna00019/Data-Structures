#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&a[largest], &a[i]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
   }
  
printf("\n");
printf("\n");
// Delete elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]); 
        heapify(a, i, 0);  
    
   }
}

int main() {
  
    int a[] = {10, 34, 2, 89, 145, 57, 94,900,1020,12,11,45};
    int n = sizeof(a) / sizeof(a[0]);
    printf("UNSORTED ARRAY\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    heapsort(a, n);
    printf("AFTER HEAP SORT \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
printf("\n");


    return 0;
}

/*
OUTPUT OF THE RUN PROGRAM
UNSORTED ARRAY
10 34 2 89 145 57 94 900 1020 12 11 45 

AFTER HEAP SORT 
2 10 11 12 34 45 57 89 94 145 900 1020 

*/
