//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target)
{
    if (numsSize > 2)
    {
        int *p1,*p2;
        p1 = p2 = nums;
        //p2 = nums + numsSize;

        for (int i = 0; i < numsSize; i++)
        {
            for (int j = 1; j < numsSize; j++)
            {
                if ((p1[i] + p2[j]) == target)
                {
                    printf("[%d,%d]\n" , i , j);
                }
            }
        }
    }
    else if (numsSize = 2)
    {
        if ( (nums[0] + nums[1]) == target )
            printf("[0,1]\n");
    }
    else
        return NULL;
}

int main()
{
    int num[]={0 , 1 , 2, 3, 4, 5, 6};
    int target = 6;
    
    twoSum(num , 7 , target );
    

    return 0;
}
