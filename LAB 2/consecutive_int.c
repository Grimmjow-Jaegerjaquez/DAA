# include <stdio.h>
# include <stdlib.h>

int gcd(int x,int y){
    int count = 0,t = 0;

    if(x == 0 && y == 0)
        t = 0;

    else if(x == 0 && y != 0){
        t = y;
        count++;
    }

    else if(x != 0 && y == 0){
        t = x;
        count++;
    }

    else{
        t = x < y ? x : y;

        while(1){
            count++;
            if(x % t == 0 && y % t == 0){
                break;
            }
            else{
                t--;
            }
        }
    }

    printf("Count = %d\n",count);
    return x+y;
    
}

int main(){
    for(int i = 0;i < 15;i++){
        printf("%d\n",gcd(rand() % 20 + 1,rand()%20 + 1));
    }
}