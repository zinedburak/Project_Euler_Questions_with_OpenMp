#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>


long long int steps(long long int x){
    int count = 0;
    if(x % 2 == 0) {
        
        return count+1+steps(x/2);    
    }
    else if(x == 1){
        
        return count+1;
    }
    else if(x % 2 != 0){
        
        return count+1+steps((3*x)+1);
    }
    
}
void lineer(){
    int value = 0;
    int tmp = 0;
     
    for(int i = 1000000;i>0;i--){
        if(steps(i)>value){
           // printf("%d **** %d\n ",i,steps(i));
            value = steps(i);
            tmp = i;
        }
     
    }
    
    printf("***%d***%d\n",value,tmp);
}
void parallel(){
    int value = 0;
    int tmpvalue = 0;
    int tmpi = 0;
    int maini = 0;
    #pragma omp parallel firstprivate(tmpvalue,tmpi) shared(value)
    {
        #pragma omp for
        for(int i = 1000000;i>0;i--){
            if(steps(i)>tmpvalue){
                tmpvalue = steps(i);
                tmpi = i;
            }
        }
        #pragma omp critical
        {
            if(tmpvalue>value){
                value = tmpvalue;
                maini = tmpi;
            }
        }
    }
    printf("the value is equal to : %d , the starting point is  : %d\n",value,maini);
}
int main(){
   clock_t start,end;
   start = clock();
   parallel();
   end = clock();
   double cpu_time = ((double)end-start)/CLOCKS_PER_SEC;
   printf("parallel time : %f s\n",cpu_time);
   start = clock();
   lineer();
   end = clock();
   cpu_time = ((double)end-start)/CLOCKS_PER_SEC;
   printf("lineer time : %f s",cpu_time);
}