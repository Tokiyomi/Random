#include <stdio.h>

int main(){

    //Enter the values of the array
    float array[10][2]={{0.29112553, 11.49167042}, 
    {0.34560883, 11.91456656}, 
    {0.42620424, 34.7827111}, 
    {-0.62917499, -30.18052512}, 
    {1.40511363, 85.65344439}, 
    {-0.25637898, -30.41604961}, 
    {-0.04042276, 22.26176979}, 
    {0.10990232, 5.1054258}, 
    {-0.23691729, -15.81367694}, 
    {0.16324983, 17.81977289}};

    float X_sum=0, Y_sum=0;

    //Obtain X_prom and Y_prom
    for(int i=0;i<10;i++){
        X_sum+= array[i][0];
    }
    float X_prom=X_sum/10;
    
    for (int i=0;i<10;i++){
        Y_sum+= array[i][1];
    }
    float Y_prom=Y_sum/10;

    //Start the sum
    float numerator=0, denominator=0;
    for (int i=0;i<10;i++){
        numerator+=(array[i][0] - X_prom)*(array[i][1] - Y_prom);
        denominator+=(array[i][0] - X_prom)*(array[i][0] - X_prom);
    }
    //Compute the slope
    float m;
    m=numerator/denominator;

    //Compute the intersection b
    float b;
    b= Y_prom - m*(X_prom);

    //print the equation of the lineal regression
    printf("The equation of the linear regression is:\n");
    printf("y = %.4fx + %.4f", m,b);


    return 0;
}