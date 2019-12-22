#define LENGTH 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift_element(int *arr, int i){
    int save1 = *(arr); 
   for (int j=0; j<i; j++, arr++){
        int save2 =*(arr+1);
         *(arr+1)= save1;
         save1=save2;
   }
}

void insertion_sort(int *arr, int len){
    for(int i=1; i<=len; i++){
        int count=0;
        int j=i;
        int *next = arr+i;
        int *pre = next-1;
        while (j>0 && (*(pre))>(*(next))){
            count++;
            pre--;
            j--;
        }
    if(count>0){
        int saveValue = *(next);
        shift_element(next-count, count);
        *(next-count)=saveValue;
        }   
    }
}

int main(){
int i=0;
    int r [LENGTH]={0};
    for (int j = 0; j < LENGTH; ++j) { 
        scanf("%d", &i);
        *(r+j)=i;
    }
    insertion_sort(r,LENGTH);
    for (int k = 0; k <LENGTH ; ++k) {
        if (k== LENGTH - 1) {
            printf("%d", *(r + k));
        } else {
            printf("%d", *(r + k));
            printf(",");
        }
    }



return 0;
}
