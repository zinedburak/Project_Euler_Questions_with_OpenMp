#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int main(){
    int sum1 = 0;
    int sum2 = 0;
    int tmpsum2;
    int tmpsum1;
   /*  #pragma omp parallel private(tmpsum1,tmpsum2) shared(sum1,sum2)
    {
        #pragma omp for
        for(int i = 0;i<101;i++){
            tmpsum1+=pow(i,2);
        }
        #pragma omp barrier

        #pragma omp for
        for(int j = 0;j<101;j++){
            tmpsum2+=j;
        }
        #pragma omp barrier

        #pragma omp critical
        {
            sum1+=tmpsum1;
            sum2+=pow(tmpsum2,2);
        }
    }
    */
   #pragma omp parallel private(tmpsum1)  shared(sum1)
   {
        tmpsum1 = 0;

       #pragma omp for schedule(auto)
       for(int i = 0;i<101;i++){
           tmpsum1+=pow(i,2);
           //printf("the tmpsum1 : %d thread id :  %d the i : %d\n",tmpsum1,omp_get_thread_num(),i);
       }
       #pragma omp critical
       {
           sum1+=tmpsum1;
       }
   }
   printf("the sum 1 is equal to = %d\n",sum1);
   #pragma omp parallel private(tmpsum2) shared(sum2)
   {
       tmpsum2 = 0;
       #pragma omp for schedule(auto)
       for(int i = 0;i<101;i++){
           tmpsum2 +=i;
       }
       #pragma omp critical
       {
           sum2+=tmpsum2;
       }
       //printf("the sum2 : %d thread id :  %d\n",sum2,omp_get_thread_num());
       #pragma omp master
       {
           sum2 =pow(sum2,2);
       }
       //printf("the sum2 : %d thread id :  %d\n",sum2,omp_get_thread_num());
   }
   //printf("the sum 1 is equal to = %d\n",sum2);
    printf("the diffrence is equal to : %d",sum2-sum1);
}