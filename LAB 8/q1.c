# include <stdio.h>
# include <stdlib.h>

#define LEFT_CHILD(i) (2 * (i) + 1)
#define RIGHT_CHILD(i) (2 * (i) + 2)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i, int *count){
    int largest = i;
    int left = LEFT_CHILD(i);
    int right = RIGHT_CHILD(i);

    //find largest element between parent and children 
    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(&arr[i],&arr[largest]);
        (*count) += 3; //3 basic operations : swap, read i, read largest

        heapify(arr, n, largest, count);

    }
}

void build_heap(int arr[], int n, int *count){
    for(int i = (n / 2) - 1; i >= 0; i--){
        heapify(arr, n, i, count);
    }
}

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, count = 0;
    printf("Enter number of elements : ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements of array : ");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Original array: ");
    print_array(arr, n);

    build_heap(arr, n, &count);

    printf("Heapified array: ");
    print_array(arr, n);
    printf("Basic operations: %d\n", count);

    return 0;
}
