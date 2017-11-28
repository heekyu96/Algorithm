//
// Created by imtt9 on 2017-11-28.
//
#include<iostream>
#include <ctime>
#define TotalData 100000
using namespace std;

int data1[TotalData];
int N;
int temp;

void repetitionsolution();
void recursivesolution(int num);
int findmax(int num);
void arrswap(int *ptr1, int *ptr2);

int main()
{
    long start, end;
    double seconds;
    FILE *in;
    in = fopen("Testcase.txt", "r");
    for(int i=0;i<TotalData;i++){
        fscanf(in,"%d",&data1[i]);
//        printf("%d ",data[i]);
    }

    start = clock();
    repetitionsolution();
//    recursivesolution(TotalData);
    end = clock();
//    for (int i = 0; i < 100000; i++)
//    {
//        cout << data1[i] << " ";
//    }
    cout<<endl<<"---" <<endl<<"Total Data Count : "<<TotalData<<endl<<"Total time : "<< end - start << " ";

}

void repetitionsolution() {
    int minIdx;;
    for (int i = 0; i < TotalData; i++) {
        minIdx = i;
        for (int j = i + 1; j < TotalData; j++) {
            if (data1[minIdx] > data1[j]) {
                minIdx = j;
            }
        }
        arrswap(&data1[minIdx], &data1[i]);
    }
}


void recursivesolution(int num)
{
    arrswap(&data1[findmax(num)],&data1[num]);
    recursivesolution(num - 1);
}

int findmax(int num)
{
    int maxidx;
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            maxidx = 0;
        }
        else if (data1[i] > data1[maxidx])
        {
            maxidx = i;
        }
    }
    return maxidx;
}

void arrswap(int * ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
