#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int isprime(long long int n){
    // printf("burak deniz 2");
    if(n == 2){
        return 1;
    }
    else if(n<2){
        return 0;
    }
    for(long long int i = 2;i<n;i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
void lineer(){
    int count = 0;
    long long int n = 0;
    int tmpprime = 0;
    while(count < 10001){
        if(isprime(n)){
            count++;
          
            tmpprime = n;
            n++;
        }
        else{
            n++;
        }
        
    }
    printf("****n is equal to : %d",tmpprime);
}
void parallel(){
    for(int i = 0;i<10001;i+=0){
        
    }
}
int main(){
    clock_t start,end;
    start = clock();
    lineer();
    parallel();
    end = clock();
    double cpu_time = ((double)end - start)/CLOCKS_PER_SEC;
    printf("this is the time %f",cpu_time);
}