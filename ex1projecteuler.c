#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

void parallel(int n){
    int tmpsum = 0;
    int mainsum = 0;
    #pragma omp parallel firstprivate(tmpsum) shared(mainsum)
    {
        #pragma omp for
        for(int i = 3;i<n;i++){
            if(i%3 == 0 || i%5 == 0){
                tmpsum+=i;
            }
        }
        #pragma omp critical
        {
            mainsum +=tmpsum;
        }
    }
    printf("mainsum is equal to : %d \n",mainsum);
}
void lineer(int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(i%3 == 0 || i%5 == 0){
            sum+=i;
        }
    }
    printf("the sum is equal to %d \n",sum);
}
int main(){
    int n;
    scanf("%d",&n);
    clock_t start,end;
    start = clock();
    parallel(n);
    end = clock();

    double cpu_time = ((double)end-start)/CLOCKS_PER_SEC;
    printf("the time is equal to : %f \n",cpu_time);
    start = clock();
    lineer(n);
    end = clock();
    cpu_time = ((double)end-start)/CLOCKS_PER_SEC;
    printf("the linear time is equal to %f \n",cpu_time);
}