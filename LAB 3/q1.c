#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void bubble_sort(int *a, int len){
    for(int i = 1; i <= len; i++){
        for(int j = 0; j < len - i; j++){
            opcount++;
            if(a[j] > a[j+1]){
                a[j] = a[j] + a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
    }
}
int main(){
    int len;
    printf("How many items? ");
    scanf("%d", &len);
    
    int a[len];
    printf("Enter elements: ");
    for(int i = 0; i < len; i++) scanf("%d", &a[i]);

    bubble_sort(a, len);

    printf("Sorted array is: ");
    for(int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\nFinal opcount is %d\n", opcount);
    return 0;
    
}