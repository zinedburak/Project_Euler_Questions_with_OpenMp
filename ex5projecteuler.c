#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int divide(int n){
    int total = 0;
    for(int i = 1;i<20;i++){
       
        if(n % i != 0){
       
            return 0;
        }
    }
    return 1;
}


int main(){
    int count = 20;
    int limit = 500000000;
    int i;
    int control = 0;
    clock_t start,start2,end,end2;
    start = clock();
     #pragma omp parallel shared(i,limit)
    {
        
    #pragma omp for schedule(static,200) 
        for(i =  20;i<limit;i++){
            //printf("thread id %d, i = %d  \n",omp_get_thread_num(),i);
            
            if(divide(i)){
                printf("the number  is equal to = %d \n",i);
                control = 1; 
            }
            //printf("burak deniz");
            if(i%100000000 == 0){
                 printf("***thread id : %d, limit = %d \n",omp_get_thread_num(),limit);
            }
            
        }
    }
    end = clock();
    start2 = clock();
    for(int i = 20;i<limit;i++){
        if(divide(i)){
            printf("the number is equal to %d  \n" ,i);
            control = 1;
        }
         if(i%100000000 == 0){
                 printf("***thread id : %d, limit = %d point = %d\n",omp_get_thread_num(),limit,i);
        }
        if(control == 0 && i == limit-1 ){
            limit+=limit;
        }
       

    }
    end2 = clock();
    double cpu_time = ((double)end-start)/CLOCKS_PER_SEC;
    double cpu_time2 = ((double)end2-start2)/CLOCKS_PER_SEC;
    printf("%f the parallel time is \n",cpu_time);
    printf("%f the lineer time ",cpu_time2);

    
  
}  


