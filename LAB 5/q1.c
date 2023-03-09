#include <stdio.h>
#include <stdlib.h>

int mat[4][4] = {{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
int matlen = 4;

void swap(int*a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

int fact(int n){
	if(n==1)
		return 1;
	return n*fact(n-1);
}

void comp(int *arr, int ord[24][4], int* count, int s, int e, int y, int* opcount){
	if(s==e){
		for(int i =0;i<y;i++){
			
			ord[*count][i] = arr[i];

		}
		(*count)++;
	} 
    
    else{
		for(int i=s;i<=e;i++){
			swap(arr+s,arr+i);
			(*opcount)++;
			comp(arr,ord, count,s+1,e,y, opcount);
			swap(arr+s,arr+i);
		}
	}
}

void main(){
	for(int y=1;y<5;y++){
	    int ord[24][4];
	    int arr[] = {0,1,2,3},c =0;
	    int min = 10000000, *f, opcount = 0;
	    comp(arr,ord,&c,0,y-1, y, &opcount);
	    for(int i=0;i<fact(y);i++){
		    int sum = 0;
		    for(int j =0;j<y;j++){
				sum+= mat[j][ord[i][j]];
			}
			if(sum<min){
				min = sum;
				f = &(ord[i]);
			}
	    }
		printf("%d, %d\n",y, opcount);
	
    }
}