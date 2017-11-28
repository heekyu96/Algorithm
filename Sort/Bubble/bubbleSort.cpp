//
// Created by imtt9 on 2017-11-26.
//

#include <iostream>
#include <ctime>
using namespace std;
int totalData;
int temp;
int data[100000];
int main() {
    totalData = 100000;

    FILE *in;
    in = fopen("Testcase.txt", "r");
    for(int i=0;i<totalData;i++){
        fscanf(in,"%d",&data[i]);
//        printf("%d ",data[i]);
    }

    long start;
    long end;
    start = clock();

    for (int i = 0; i < totalData; i++) {
        for (int j = 0; j < totalData - 1; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    end = clock();

    cout<<endl<<"---" <<endl<<"Total Data Count : "<<totalData<<endl<<"Total time : "<< end - start << " ";
}