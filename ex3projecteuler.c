#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>

int ispal(long long int n){
    int count = 0;
    int newNum = 0;
    int tmp = n;
  
    char snum[6];
    char nsum[6];
    char tnum[6];
    itoa(n,tnum,10);
    itoa(n,snum,10);
    strrev(snum);
    //printf(" new Num = %s :: tmp = %d \n",snum,tmp);
    return (strcmp(snum,tnum));
}
int main(){
    int max = 0;
    printf("%d \n" ,ispal(908));
    printf("%d \n" ,ispal(101));
    for(int i = 999;i>0;i--){
        for(int j = 999;j>0;j--){
            //printf("burak deniz ");
            if(ispal(i*j) == 0 && i*j>max){
                max = i*j;
                
            }
        }
    }
    printf("this is the value : %d ",max);
}