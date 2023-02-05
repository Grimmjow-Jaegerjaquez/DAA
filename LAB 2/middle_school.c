# include <stdio.h>

int gcd(int x,int y){
    int temp;
    while(y != 0){
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

int main(){
    int x,y;
    printf("Enter two integers : ");
    scanf("%d %d",&x,&y);
    printf("HCF of %d and %d is %d\n",x,y,gcd(x,y));
    return 0;
}