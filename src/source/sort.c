#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

/*
    堆排序
    不稳定
    空间复杂度O(n)
    时间复杂度O(nlog2 n)
    大根堆 => 递增序列;小根堆 => 递减序列

*/

//建立大根堆
void BuildMaxHeap(int arry[], int len)
{
    for(int i = len/2; i > 0; i--) //从后往前调整所有非终端结点(有子叶的结点)
    {
        HeadAdjustForMaxHeap(arry, i, len);
    }
}

//将以k为根的子树调整为大根堆
void HeadAdjustForMaxHeap(int arry[], int k, int len)
{
    arry[0] = arry[k];//暂存子树的根结点,arry数组0元素不存数据
    for (int i= 2*k; i <= len; i *= 2)//沿key较大的子结点向下筛选
    {
        if(i < len && arry[i] < arry[i+1]) i++;//取key较大的子结点下标

        if(arry[0] >= arry[i]) break; //符合大根堆，筛选结束
        else
        {
            arry[k] = arry[i];       //将子叶调整至双亲结点上
            k = i;                   //修改k值，继续向下
        }
    }
    arry[k] = arry[0];             //筛选结点的值放入最终位置
}


void HeapSortUp(int arry[], int len)
{
    BuildMaxHeap(arry, len); //建立大根堆
    for(int i=len; i>0; i--)
    {
        int tmp = arry[i];
        arry[i] = arry[1];
        arry[1] = tmp;
        HeadAdjustForMaxHeap(arry, 1, i-1);
    }
    arry[0] = 0;
}

//建立小根堆
void BuildMinHeap(int arry[], int len)
{
    for(int i = len/2; i > 0; i--) //从后往前调整所有非终端结点(有子叶的结点)
    {
        HeadAdjustForMinHeap(arry, i, len);
    }
}

//将以k为根的子树调整为小根堆
void HeadAdjustForMinHeap(int arry[], int k, int len)
{
    arry[0] = arry[k];//暂存子树的根结点,arry数组0元素不存数据
    for (int i= 2*k; i <= len; i *= 2)//沿key较大的子结点向下筛选
    {
        if(i < len && arry[i] > arry[i+1]) i++;//取key较小的子结点下标

        if(arry[0] <= arry[i]) break; //符合小根堆，筛选结束
        else
        {
            arry[k] = arry[i];       //将子叶调整至双亲结点上
            k = i;                   //修改k值，继续向下
        }
    }
    arry[k] = arry[0];             //筛选结点的值放入最终位置
}


void HeapSortDown(int arry[], int len)
{
    BuildMinHeap(arry, len); //建立小根堆
    for(int i=len; i>0; i--)
    {
        int tmp = arry[i];
        arry[i] = arry[1];
        arry[1] = tmp;
        HeadAdjustForMinHeap(arry, 1, i-1);
    }
    arry[0] = 0;
}

/* 
    插入排序 
    稳定 
    空间复杂度O(1)
    时间复杂度O(n^2) 最好O(n)~最坏O(n^2)
*/

void InsertSortUp(int arry[], int n)
{
    int i,j,tmp;
    for (i = 1; i < n; i++)
    {
        if(arry[i] < arry[i-1])  //arry[i]小于前一个元素
        {
            tmp = arry[i];      //暂存arry[i],空出i位置
            for(j = i-1; j >= 0 && arry[j] > tmp; --j) //检查i位置已排序好的元素
                arry[j+1] = arry[j];  //所有大于tmp的往后移动
            arry[j+1] = tmp;         //将原arry[i]填到插入位置
        }
    }
}

void InsertSortUpWithGuard(int arry[], int n)
{
    int i,j;
    for (i = 1; i < n; i++)
    {
        if(arry[i] < arry[i-1])  //arry[i]小于前一个元素
        {
            arry[0] = arry[i];      //暂存arry[i],空出i位置
            for(j = i-1; arry[j] > arry[0]; --j) //检查i位置已排序好的元素
                arry[j+1] = arry[j];  //所有大于tmp的往后移动
            arry[j+1] = arry[0];         //将原arry[i]填到插入位置
        }
    }
}

void HalfInsertSortUp(int arry[], int n)
{
    int i,j,low,high,mid;
    for (i = 2; i < n; i++)
    {
        arry[0] = arry[i];
        low = 1;
        high = i-1;
        while (low <= high)
        {
            mid = (low + high)/2;
            if(arry[mid] > arry[0])
                high = mid - 1;   //查左半部分
            else
                low = mid + 1;   //查右半部分
        }
        for(j = i-1; j >= high+1; --j)
            arry[j+1] = arry[j];      //所有大于tmp的往后移动
        arry[high+1] = arry[0];         //将原arry[i]填到插入位置
    }
}

/* 
    快速排序
    不稳定
    空间复杂度 n     最好log2 n 最坏n
    平均时间复杂度nlog2 n   最好nlog2 n 最坏n^2

*/

//用第一个元素将待排序队列划分成左右两个部分
int Partition(int arry[], int low, int high)
{
    int pivot = arry[low];     //第一个元素作为枢轴
    while (low < high)
    {
        while (low < high && arry[high] >= pivot) --high;
        arry[low] = arry[high];
        while (low < high && arry[low] <= pivot) ++low;
        arry[high] = arry[low];
    }
    arry[low] = pivot;
    return low;
}

void QuickSort(int arry[], int low, int high)
{
    if(low < high)
    {
        int pivotPos = Partition(arry, low, high); //划分
        QuickSort(arry, low, pivotPos-1);  //划分左子表
        QuickSort(arry, pivotPos+1, high);   //划分右子表
    }
    
}

/* 
    归并排序
    稳定
    空间复杂度O(n)
    时间复杂度O(nlog2 n)
 */


int tmpArry[100]={0};

void MergeArry(int arry[], int low, int mid, int high)
{
    int i,j,k;
    for(k=low; k<=high; k++)
    {
        tmpArry[k] = arry[k];
    }
    for (i=low,j=mid+1,k=i; i<=mid && j<=high; k++)
    {
        if(tmpArry[i] <= tmpArry[j])  //比较[low,mid],[mid+1,high]将较小值存入arry
            arry[k] = tmpArry[i++];
        else
            arry[k] = tmpArry[j++]; 
    }
    while (i<=mid) arry[k++] = tmpArry[i++];
    while (j<=mid) arry[k++] = tmpArry[j++];
}

void MergeSort(int arry[], int low,int high)
{
    if( low < high)
    {
        int mid = (low+high)/2;    //中间划分
        MergeSort(arry, low, mid); //左半部分归并
        MergeSort(arry, mid+1, high); //右半部分归并
        MergeArry(arry, low, mid,high); //左右归并
    }
}

/* 
    基数排序
    稳定
*/