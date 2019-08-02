#include <stdio.h>

int main(){

    int n,len,row,col,x,y,distance;
    printf("Give me n: ");
    scanf("%d", &n);
    
    len=2*n-1; //Compute the number of rows=columns
    
    for (row = 1; row <= len; row++) {
        for (col = 1; col <= len; col++) {

            //Generate the absolute value of the coordinates. I started from uper left.
            x=abs(col-n); //X-coordinate
            y=abs(n-row); //Y-coordinate

            //See which coordinate is further away from the center
            distance= x > y ? x : y;

            //The printed number will be the distance plus 1
            printf("%d ", distance + 1);
        }
        printf("\n");
    }
return 0;
}