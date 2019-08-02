#include <stdio.h>
#include <omp.h>
#include <time.h>

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
void allprimes(long long int n){
   // printf("burak deniz n = %d",n);
    for(long long int i = 2;i<n;i++){
        //printf("burak deniz i ==  %d \n",i);
        if(n%i == 0 ){
          //  printf("burak deniz 3");
            long long int b = isprime(i);
            if(b == 1){
                printf("this is the number : %lld \n",i);
            }
        }
        if(i%1000000000 == 0){
            printf("we are at this point : %lld \n",i);
        }
    }
}
#pragma omp declare simd
int plisprime(long long int n){
    if(n < 2 ){
        return 0;
    }
    else if(n  == 2){
        return 1;
    }
    else{
        int psum = 1;
        int sum = 1;
        #pragma omp parallel firstprivate(psum) shared(sum) 
        {
            //printf("the number of threads  %d \n",omp_get_num_threads());
            #pragma omp for
            for(int i = 2;i<n;i++){
                if(n%i == 0){
                    psum = 0;
                }
            }
            #pragma omp critical
            {
                sum = psum*sum;
            }
        }
        return sum;
    }
}
void plallprimes(long long int n){
    int psum = 0;
    int sum = 0;
    #pragma omp parallel shared(sum) firstprivate(psum)
    { 
        #pragma omp for schedule(auto)
        for(long long int i = 2;i<n;i++){
            if(n%i == 0){
               // printf("burak deniz id : %d \n",omp_get_thread_num());
                if(plisprime(i)==1)
                {
                 //   printf("**burak deniz id : %d \n",omp_get_thread_num());
                psum += i;
                }
            }
            if(i%1000000000 == 0){
                printf("we are at this point : %lld with id : %d \n",i,omp_get_thread_num());
            }
        }
        #pragma omp critical
        {
            sum+=psum;
        }
    }
    printf("the sum is equal to : %d",sum);
}




int main(){
   long long int n = 0;
    scanf("%lld",&n);
    clock_t start,end,start1,end1;
    start = clock();
    plallprimes(n);
    end = clock();
    printf("time is =  %f",((double)end-start)/CLOCKS_PER_SEC);
}