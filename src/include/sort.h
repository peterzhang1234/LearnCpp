
#ifdef __cplusplus
extern "C"
{
#endif
    void HeadAdjustForMaxHeap(int arry[], int k, int len);
    void BuildMaxHeap(int arry[], int len);
    void HeapSortUp(int arry[], int len);

    void HeadAdjustForMinHeap(int arry[], int k, int len);
    void BuildMinHeap(int arry[], int len);
    void HeapSortDown(int arry[], int len);

    void InsertSortUp(int arry[], int n);
    void InsertSortUpWithGuard(int arry[], int n);
    void HalfInsertSortUp(int arry[], int len);

    void QuickSort(int arry[], int low, int high);

    void MergeSort(int arry[], int low,int high);
#ifdef __cplusplus
}
#endif