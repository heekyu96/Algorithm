//
// Created by imtt9 on 2017-11-27.
//
#define TotalData 100000
#include <iostream>
#include <ctime>


using namespace std;

void recursiveqsort1(int a[], int left, int right) // 재귀 : pivot을 배열의 중간값으로
{
    int pivot, temp;
    int i, j;


    if (left < right) {
        pivot = a[(left + right) / 2];
        i = left - 1;
        j = right + 1;

        while (1) {
            while (a[++i] < pivot);
            while (a[--j] > pivot);

            if (i >= j)
                break;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        recursiveqsort1(a, left, i - 1);
        recursiveqsort1(a, j + 1, right);
    }
}
void recursiveqsort2(int a[], int left, int right) // 재귀 : pivot을 배열의 첫 번째 값으로
{
    int pivot, temp;
    int i, j;


    if (left < right) {
        pivot = a[left];
        i = left;
        j = right + 1;

        while (1) {
            while (a[++i] < pivot);
            while (a[--j] > pivot);

            if (i >= j)
                break;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        /* pivot 값을 교환 */
        a[left] = a[j];
        a[j] = pivot;

        recursiveqsort2(a, left, j - 1);
        recursiveqsort2(a, j + 1, right);
    }
}

int top;
int stack[TotalData];


void init_stack()
{
    top = 0;
}

void push(int i)
{

    if (top >= TotalData) {
        printf("stack full\n");
        return;
    }
    else
        stack[top++] = i;
}

int pop()
{

    if (top == 0)
        return 0;
    else
        return stack[--top];

}

int is_stack_empty()
{

    if (top == 0)
        return 1;
    else
        return 0;

}
void repeatqsort(int a[], int n) // 반복문과 스택을 이용한 방법
{
    int pivot, temp;
    int i, j;
    int left, right;

    init_stack();

    left = 0;
    right = n - 1;

    push(right);
    push(left);

    while (!is_stack_empty()) {
        left = pop();
        right = pop();

        if (right - left + 1 > 1) {  // 종료조건 :: 남아 있는 분할의 원소 개수가 1개 이상일 경우
            pivot = a[right];
            i = left - 1;
            j = right;

            while (1) {
                while (a[++i] < pivot);
                while (a[--j] > pivot);

                if (i >= j)
                    break;

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

            }

            // pivot과 i값을 교환
            temp = a[i];
            a[i] = a[right];
            a[right] = temp;

            push(right);     // 오른쪽 분할의 오른쪽 끝
            push(i + 1);  // 오른쪽 분할의 왼쪽 끝
            push(i - 1);  // 왼쪽 분할의 오른쪽 끝
            push(left);     // 왼쪽 분할의 왼쪽 끝

        }
    }
}
int get_random(int range) //난수 발생
{

    return rand() % range;

}

void repeatqsort2(int a[], int n) // 난수를 발생하여 피봇으로 정하는 방법
{
    int pivot, temp;
    int i, j;
    int left, right;


    init_stack();

    left = 0;
    right = n - 1;

    push(right);
    push(left);

    while (!is_stack_empty()) {

        left = pop();
        right = pop();

        if (right - left + 1 > 1) {
            temp = get_random(right - left + 1) + left; // 난수 발생

            pivot = a[temp];
            a[temp] = a[right];
            a[right] = pivot;

            i = left - 1;
            j = right;

            while (1) {
                while (a[++i] < pivot);
                while (a[--j] > pivot);

                if (i >= j)
                    break;

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

            }

            temp = a[i];
            a[i] = a[right];
            a[right] = temp;

            push(right);
            push(i + 1);
            push(i - 1);
            push(left);

        }
    }
}
int main() {
    int data[TotalData];
    FILE *in = fopen("Testcase.txt", "r");
    long start;
    long end;

    for (int i = 0; i <TotalData; i++) {
        fscanf(in,"%d ",&data[i]);
    }
    start=clock();
//    recursiveqsort2(data,0,TotalData-1);
    repeatqsort2(data,TotalData);
    end=clock();

    cout<<endl<<"---" <<endl<<"Total Data Count : "<<TotalData<<endl<<"Total time : "<< end - start << " ";
}