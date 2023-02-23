# include <stdio.h>

void toh(int n, char from_rod, char to_rod, char aux_rod){
    if(n == 0)
        return;

    toh(n - 1,from_rod,aux_rod,to_rod);
    printf("Move disk %d from rod %c to rod %c \n",n,from_rod,to_rod);
    toh(n - 1,aux_rod,to_rod,from_rod);
}

int main(){
    int n = 3;
    //printf("Enter number of disks : ");
    //scanf("%d",&n);

    toh(3,'A','C','B');
    return 0;
}