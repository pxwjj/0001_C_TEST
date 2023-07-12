/**
 * 二分查找(折半查找) 时间复杂度O(logn)
 *    满足单调性
 * 
*/

#include<stdio.h>

int EFCZ_fun(int *a , int n, int len)
{
    int head = 0, tail = len - 1, mid = (head + tail) / 2 ;
    
    while (1){
        if (head > tail){
            printf("err");
            return -1;
        }

        if ( a[mid] == n ){
            return mid;
        }else if ( a[mid] > n ){
            tail = mid -1;
            mid = (head + tail) / 2;
        }else{
            head = mid + 1;
            mid = (head + tail) / 2;
        }
    }
    
    return 1;
}

int main()
{
    int arr[10] = {0, 1, 5, 6, 7, 8, 9};
    int n;

    while (scanf("%d", &n) == 1)
    {
        printf("%d 在数组中的index：%d \n", n, EFCZ_fun(arr , n, sizeof(arr)/sizeof(arr[0])));
    }

    return 0;
}