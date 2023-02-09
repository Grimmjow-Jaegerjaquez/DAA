# include <stdio.h>
# include <stdlib.h>

int gcd_middle(int x,int y){

    if(x > y)
        gcd_middle(y,x);

    int fact = 2,gcd = 1,k = x,count = 0;

    for(fact = 2;fact <= k;fact++){
        count++;

        while((x % fact) == 0 && (y % fact) == 0){
            count++;
            gcd = gcd * fact;
            y = y/fact;
            x = x/fact;

            if(x == 0 || y == 0){
                printf("%d\t",count);
                return gcd;
            }
        }
    }

    printf("%d\t",count);
    return gcd;
}

int main(){
    int x,y;
    printf("Enter the First Number : \n");
	scanf("%d", &x);
	
	printf("Enter the Second Number : \n");
	scanf("%d", &y);

    printf("The GCD of '%d' and '%d' = '%d' \n",x,y,gcd_middle(x,y));

}