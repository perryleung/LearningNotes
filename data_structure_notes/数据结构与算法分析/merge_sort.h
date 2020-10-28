template <typename comparable>
void mergeSort(vector<comparable> &arr)
{
    vector<comparabel> tmpArr(arr.size());
    mergeSort(arr, tmpArr, 0, arr.size() - 1);
}

template <typename comparable>
void mergeSort(vector<comparable> &arr, vector < comparable & tmpArr, int left, int right)
{
    if(left < right)
    {
        int center = (left + right) / 2;
        mergeSort(a, tmpArr, left, center);
        mergeSort(a, tmpArr, center + 1, right);
        merge(a, tmpArr, left, center + 1, right);
    }
}

template <typename comparable>
void merge(vector<comparable> & arr, vector<comparable> & tmpArr, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while(leftPos <= leftEnd && rightPos <= rightEnd)
        if(arr[leftPos] <= arr[rightPos])
            tmpArr[tmpPos++] = arr[leftPos++];
        else
            tmpArr[tmpPos++] = arr[rightPos++];
    while(leftPos <= leftEnd)
        tmpArr[tmpPos++] = arr[rightPos++];
    while(rightPos <= rightEnd)
        tmpArray[tmpPos++] = arr[rightPos++];
    for (int i = 0; i < numElements; i++, rightEnd--)
        arr[rightEnd] = tmpArr[rightEnd];
}
