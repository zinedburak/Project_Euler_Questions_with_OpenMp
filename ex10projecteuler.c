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
long long int lineer(){
    long long int sum = 0;
    for(int i = 2;i<2000000;i++){
        if(isprime(i)){
            sum+=i;
        }
        if(i%50000 == 0){
            printf("we are at this point %d\n",i);
        }
    }
    return sum;
}
void parallel(){
    long long  int sum = 0;
    long long int tmpsum = 0;
    #pragma omp parallel firstprivate(tmpsum)
    {
        //int tmpsum = 0;
        omp_set_num_threads(20);
      //  printf("tmp sum : %d , id : %d sum = %d \n",tmpsum,omp_get_thread_num(),sum);
        #pragma omp for schedule(auto)
        for(int i = 0;i< 2000000;i++){
            if(isprime(i) ==1 ){
                tmpsum+=i;
               // printf("this is a prime i : %d \n",i);
            }
            if(i%50000 == 0){
                printf("we are at this point %d id :: %d\n",i,omp_get_thread_num());
            }
        }
        printf("tmp sum : %d , id : %d sum = %d \n",tmpsum,omp_get_thread_num(),sum);
        #pragma omp critical
        {
            sum+=tmpsum;
        }
        //printf("the sum  = %lld \n",sum);
    }
    printf("the result : %lld",sum);
}
int main(){
    clock_t s,e;
    s = clock();
    //for(int i = 0;i<10;i++){
     //   printf("the number %d :: isprime %d \n",i,isprime(i));
    //}
    printf("lineer result : %lld\n",lineer());
    //parallel();
    e = clock();

    printf("lineer time = %f \n",(((double)e-s)/CLOCKS_PER_SEC));

}