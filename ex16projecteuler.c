#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>


int lineer(){
    long long int  num = pow(2,60);
    int sum = 0;
    printf("the number is equal to : %lld \n",num);
     while(num != 0){
        sum += num % 10;
        num = num/10;
    }
    return sum;
}
int main(){
    printf("%d ",lineer());
}