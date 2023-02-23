# include <stdio.h>

int fibo(int x){
    if(x == 1)
        return 0;
    if(x == 2)
        return 1;

    return fibo(x - 1) + fibo(x - 2);
}

int main()
{
    int num; 
    printf("Enter the number of elements to be in the series : ");
    scanf("%d", &num); 

    printf("%d",fibo(num));

    return 0;
}