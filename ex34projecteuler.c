#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int methood(int n){
    int digit[10];
    int count = 0;
    while(n!=0){
        int tmp  = n%10;
        int tmpfac = 1;
        for(int i = 2;i<=tmp;i++){
            tmpfac = tmpfac*i;
            if(i%20 == 0 ){
                printf("%d",i);
            }
        }
        count = count + tmpfac;
        n = n/10;
    }
    return count;
}
int main(){
    int n = 0;
    printf("enter a number : ");
    scanf("%d",&n);
    printf("\n%d",n);
    int sum = 0;
    clock_t start,end;
    start =clock();
    for(int i = 3;i<n;i++){
        if(i == methood(i)){
            sum+=i;
        }
    }
    printf("%d",sum);
    end =clock();
    double linear_time = ((double)end-start)/CLOCKS_PER_SEC;
    printf("\n %f",linear_time);
    int tmpsum = 0;
     sum = 0;
     start = clock();
    #pragma omp parallel shared(sum) firstprivate(tmpsum)
    {
        #pragma omp for
        for(int i = 3;i<n;i++){
            if(i == methood(i)){
                tmpsum += i;
            }
        }
        #pragma omp critical
         {
             sum+=tmpsum;
         }
        
    }
    end = clock();
    double parallel_time = ((double)end - start)/CLOCKS_PER_SEC;

    printf("\n%d",sum);
    printf("\n the parallel time %f",parallel_time);
}