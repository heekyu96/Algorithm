//
// Created by imtt9 on 2017-11-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    FILE* out;
    out=fopen("./Testcase.txt","w");

    srand((unsigned)time(NULL));
    int data;
    for (int i = 0; i < 100000; i++) {
        data=(rand()%100000)+1;
        fprintf(out, "%d ", data);
        printf("%d",data);
    }
}