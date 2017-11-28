//
// Created by imtt9 on 2017-11-26.
//

#include <iostream>
#include <ctime>

using namespace std;
int temp;
int data[100000];
int totalData=50000;

void BubblesortRecursive(int i) {
    if (i >= totalData) {
        return;
    }
    for (int j = 0; j < i - 1; j++) {
        if (data[j] > data[j + 1]) {
            temp = data[j];
            data[j] = data[j + 1];
            data[j + 1] = temp;
        }
    }
    BubblesortRecursive(i + 1);
}

int main() {
    FILE *in;
    in = fopen("Testcase.txt", "r");
    for(int i=0;i<totalData;i++){
        fscanf(in,"%d",&data[i]);
//        printf("%d ",data[i]);
    }
    long start;
    long end;

    start = clock();
    BubblesortRecursive(0);

    end = clock();
//    for(int i=0;i<totalData;i++){
//        printf("%d ",data[i]);
//    }
    cout<<endl<<"---" <<endl<<"Total Data Count : "<<totalData<<endl<<"Total time : "<< end - start << " ";
}