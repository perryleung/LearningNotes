template <typename comparable>
void quickSort(vector<comparable> & arr){
    quickSort(arr, 0, a.size() - 1);
}


template <typename comparable>
const comparable &median3(vector<comparable> &arr, int left, int right)
/*
执行三数中值分割方法
*/
{
    int center = (left + right) / 2;
    if(arr[center] < arr[left])
        swap(arr[left], arr[center]);
    if(arr[right] < arr[left])
        swap(arr[left], arr[right]);
    if(arr[right] < arr[center])
        swap(arr[right], arr[center]);
    swap(arr[center], arr[right - 1]);
    return arr[right - 1];
}

/**
Internal quicksort method that makes recursive calls.
Uses median-of-three partitioning and a cutoff of 10.
a is an array of Comparable items.
left is the left-most index of the subarray.
right is the right-most index of the subarray.
*/
template <typename comparable>
void quicksort(vector<comparabl> & arr, int left, int right)
{
    if(left + 10 <= right)
    {
        comparable pivot = median3(arr, left, right);
        //begin partitioning
        int i = left, j = right - 1;
        while(true){
            while (arr[++i] < pivot)
            {}
            while (pivot < arr[--j])
            {}
            if (i < j)
                swap(arr[i], arr[j]);
            else
                break;
        }
        /**OR
         * int i = left + 1, j = right - 2;
         * for(;;){
         *  while(arr[i] < pivot) i++;
         *  while(pivot < arr[j]) j--;
         *  if(i < j)
         *      swap(arr[i], arr[j]);
         *  else
         *      break;
         * }
         * 
        */
        swap(arr[i], a[right - 1]);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }else
        insertionSort(arr, left, right);
}