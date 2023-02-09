# include <stdio.h>
# include <stdlib.h>

int gcd_middle(int x,int y){

    if(x > y)
        gcd_middle(y,x);

    int fact = 2,gcd = 1,k = x,count = 0;

    for(fact = 2;fact <= k;fact++){
        

        while((x % fact) == 0 && (y % fact) == 0){
            count++;
            gcd = gcd * fact;
            y = y/fact;
            x = x/fact;

            if(x == 0 || y == 0){
                printf("COUNT = %d\t",count);
                return gcd;
            }
        }
    }

    printf("Count = %d\t",count);
    return gcd;
}

int main(){
    
}