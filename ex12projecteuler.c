#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int tau(int num){
    int n = num;
    int i = 2;
    int p = 1;
    if(num == 1) return 1;
    while(i*i<= n){
        int c = 1;
        while(n%i == 0){
            n/= i;
            c++;
        }
        i++;
        p*=c;
    }
    if(n == num || n>1){
        p*=1+1;

    }
    return p;
}
void solution(int x){
    int n = 1;
    int d = 1;
    while(tau(d)<=x){
        n++;
        d+=n;
    }
    printf("the value is equal to : %d",d);
}

int main(){
    solution(500);
}