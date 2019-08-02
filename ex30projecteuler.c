#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>


int check(int n){
    int temp = n;
    int sum = 0;
    while(n != 0){
        int digit = n%10;
        sum += pow(digit,5);
        n = n/10;
    }
    if(sum == temp){
        return 1;
    }
    return 0;
}
int main(){
    int sum = 0;
    int sum2 = 0;
    int tmpsum = 0;
    clock_t ps,pe,ls,le;
    ps = clock();

    #pragma omp parallel firstprivate(tmpsum) shared(sum2) 
    {
        #pragma omp for
        for(int i = 2;i<10000000;i++){
            if(check(i)){
                tmpsum+=i;
                printf("the number is equal to : %d\n",i);
            }
        }
        #pragma omp critical
        {
            sum2+=tmpsum;
        }
    }
    pe = clock();
    double parallel_time = ((double)pe-ps)/CLOCKS_PER_SEC;
    printf("the sum 2 is equal to : %d\n",sum2);
    printf("the parallel time is equal to :: %f\n",parallel_time);

    
    
    ls = clock();
    for(int i = 2;i<10000000;i++){
        if(check(i) ){
            sum += i;
            printf("the number is equal to : %d\n",i);
        }
    }
    le = clock();
    double linear_time = ((double)le-ls)/CLOCKS_PER_SEC;

    printf("sum is equal to : %d ",sum);
    printf("the linear time is equal to : %f",linear_time);
}