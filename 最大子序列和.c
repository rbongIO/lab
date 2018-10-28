#include<stdio.h>

int MaxSubsequenceSum1(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;
    MaxSum = 0;
    for(i = 0; i < N; i++){
        for(j = i; j < N; j++){
            ThisSum += A[j];
            if(ThisSum > MaxSum) MaxSum = ThisSum;
        }
    }
    return MaxSum;
}
static int MaxSub(const int A[], int left, int right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;
    if(left == right)
        if(A[left] > 0)
            return A[Left];
        else
            return 0;
    Center = (left + right) / 2;
    MaxLeftSum = (A ,left, Center);
    MaxRightSum = (A, Center, right);

    MaxLeftBorderSum = 0;
    LeftBworderSum = 0;
    for(i = Center; i >= left; i--){
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    MaxRightBorderSum = 0;
    RighrBorderSum = 0;
    for(i = Center; i <= Right; i++){
        RightBorderSum += A[i];
        if(RightBorder > MaxRightBorderSum)
            MaxRightBorder = RightBorderSum;
    }
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum2(const int A[], int N)
{
    return MaxSubSum(A[], 0, N-1);
}

int MaxSubsequenceSum3(const int A, int N)
{
    int MaxSum, ThisSum, j;
    MaxSum = 0, ThisSum = 0;
    for(j = 0; j < N; j++){
        ThisSum += A[j];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}