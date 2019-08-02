#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int isphy(int a,int b,int c){
    if((a*a)+b*b == c*c){
        return 1;
    }
    else{
        return 0;
    }
}
void parallel(){
    #pragma omp parallel
    {
        #pragma omp for schedule(auto)
        for(int i = 0;i<1000;i++){
            for(int j = i+1;j<1000;j++){
                for(int z = j+1;z<1000;z++){
                    if(isphy(i,j,z)){
                        //printf("the numbers are %d , %d , %d \n",i,j,z);
                        if(i+j+z == 1000){
                            printf(" result the numbers are %d , %d , %d\n",i,j,z);
                            printf("%d",i*j*z);
                        }
                    }
                }
            }
        }
    }
}
void lineer(){
    for(int i = 0;i<1000;i++){
            for(int j = i+1;j<1000;j++){
                for(int z = j+1;z<1000;z++){
                    if(isphy(i,j,z)){
                        //printf("the numbers are %d , %d , %d \n",i,j,z);
                        if(i+j+z == 1000){
                            printf(" result the numbers are %d , %d , %d\n",i,j,z);
                            printf("%d",i*j*z);
                        }
                    }
                }
            }
        }
}
int main(){
    double time1,time2;
    clock_t  start,end,start2,end2;
    start = clock();
    parallel();
    end = clock();
    start2 =clock();
    lineer();
    end2 = clock();
    time1 = ((double)end-start)/CLOCKS_PER_SEC;
    time2 = ((double)end2-start2)/CLOCKS_PER_SEC;
    printf("parallel :: %f",time1);
    printf("lieneer :: %f",time2);


}