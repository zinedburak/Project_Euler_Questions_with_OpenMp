#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>



int check(int a){
    int sum = 0;
    for(int i = 1;i<a;i++){
        if(a%i == 0){
            sum+=i;
        }
    }
    if(sum == a){
        return 1;
    }
    else if(sum<a){
        return 2;
    }
    else if(sum>a){
        return 3;
    }
}
int main(){
    int sum = 0;
    for(int i = 0;i<28124;i++){
        
    }
    printf("the sum is equal to : %d",sum);   
}

