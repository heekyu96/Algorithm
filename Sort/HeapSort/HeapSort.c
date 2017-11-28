#include<stdio.h>
#include <time.h>
#define TotalData 100000
void insertheap(int num); // 힙 데이터 삽입 함수
void getheap(void); // 힙 출력 함수

int heap[TotalData], arr[TotalData], i, j, temp; //힙과 출력 배열
int cnt = 0, size = 0;

int main()
{
    FILE* in = fopen("Testcase.txt","r");
    int ipnum;
    long start;
    long end;

    start=clock();

    for (i = 0; i < TotalData; i++)
    {
        fscanf(in,"%d", &ipnum); // 데이터 입력
        if (ipnum == 0) // 데이터가 0일 경우
            if (size == 0) // 데이터가 0인데 사이즈가 0일경우
            {
                arr[cnt] = 0; //힙에 데이터가 없으므로 0출력
                cnt++; // 출력 카운트
            }
            else getheap(); // 힙에서 맨 윗 노드 출력
        else if (ipnum > 0)
            insertheap(ipnum); // 자연수 입력시 힙에 데이터 삽입
    }

    for (i = 0; i < TotalData; i++){
        getheap();
    }

    end=clock();

//    for (i = 0; i < cnt; i++)
//        printf("%d\n", arr[i]);

    printf("Total Data Count : %d\n",TotalData);
    printf("Total time : %d\n ", end - start );
    return 0;
}


void insertheap(int num) // 힙 데이터 삽입
{
    heap[size + 1] = num; // 들어온 값을 힙 말단에 삽입
    j = size + 1;

    while (j != 1 && heap[j / 2] < heap[j]) // 힙에 데이터가 1이 아니면서 자식이 부모보다 클 경우 교환
    {
        // 부모와 자식을 교환
        temp = heap[j / 2];
        heap[j / 2] = heap[j];
        heap[j] = temp;
        j /= 2; // 비교 노드를 부모 노드로 옮겨 가면서 비교 진행
    }
    size++; // 데이터 삽입시 크기 증가
}

void getheap(void)
{
    arr[cnt] = heap[1]; // 출력 배열에 부모힙 입력
    heap[1] = heap[size]; // 부모 노드에 말단 값 입력
    j = 1;

    while (j * 2 < size) // 자식이 없는 말단 노드일 경우 종료
    {
        if (j * 2 + 1 < size) // 자식이 둘인 경우
        {    // 두 자식이 큰 쪽과 비교
            if (heap[j * 2 + 1] > heap[j * 2]) // 오른쪽 자식이 더 큰 경우
            {
                if (heap[j * 2 + 1] > heap[j]) // 오른쪽 자식과 비교해서 부모가 더 작은 경우
                {
                    // 부모와 오른쪽 자식을 교환
                    temp = heap[j * 2 + 1];
                    heap[j * 2 + 1] = heap[j];
                    heap[j] = temp;
                    j = j * 2 + 1; // 비교 노드를 오른쪽 자식 노드로 이동
                }
                else // 오른쪽 자식이 부모보다 작은 경우
                    break; // 배치 완료
            }
            else if (heap[j * 2 + 1] < heap[j * 2]) // 왼쪽 자식이 더 큰 경우
            {
                if (heap[j * 2] > heap[j]) // 왼쪽 자식과 비교해서 부모가 더 작은 경우
                {
                    // 부모와 왼쪽 자식을 교환
                    temp = heap[j * 2];
                    heap[j * 2] = heap[j];
                    heap[j] = temp;
                    j *= 2;// 비교 노드를 왼쪽 자식 노드로 이동
                }
                else // 왼쪽 자식이 부모보다 더 작은 경우
                    break; // 배치 완료
            }
            else // 부모가 왼쪽 오른쪽 자식보다 큰 경우
                break; // 배치 완료
        }
        else // 자식 노드가 하나인 겨우
        {
            if (heap[j * 2] > heap[j]) // 자식이 부모보다 큰 경우
            {
                // 자식과 부모를 교환
                temp = heap[j * 2];
                heap[j * 2] = heap[j];
                heap[j] = temp;
                j *= 2; // 비교 노드를 왼쪽 자식 노드로 이동
            }
            else
                break;
        }
    }
    cnt++; // 출력 카운트
    size--; // 트리에서 총 노드 개수 감소
}