/**
 * Internal selection method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 * k is the desired rank (1 is minimum)in the entire array.
*/
template <typename comparable>
void quickSelect(vector<comparable>& arr, int left, int right, int k)
{
    if(left + 10 <= right)
    {
        comparable pivot = median3(arr, left, right);
        //begin partitioning
        int i = left, j = right - 1;
        for (;;)
        {
            while(arr[++i] < pivot){}
            while(pivot < arr[--j]){}
            if(i < j)
                swap(arr[i], arr[j]);
            else
                break;
        }
        swap(arr[i], arr[right - 1]);
        if (k <= i)
            quickSelect(arr, left, i - 1, k);
        else if(k > i + 1)
            quickSelect(arr, i + 1, right, k);
    }else
        insertionSort(arr, left, right);
}

template <typename comparable>
class Pointer
{
public:
    Pointer(comparable *rhs = nullptr):pointee(rhs){}
    bool operator<(const Pointer & rhs) const
    {
        return *pointee < *rhs.pointee;
    }
    operator comparable *() const
    {
        return pointee;
    }

private:
    comparable *pointee;
};

template<typename comparable>
void largeObjectSort( vector<comparable> & arr)
{
    vector<Pointer<comparable>> p(arr.size());
    int i, j, nextj;
    for (i = 0; i < arr.size(); i++)
        p[i] = &arr[i];//p[i]得到 arr[i]的每个地址
    quickSort(p);
    for (i = 0; i < arr.size(); i++)
    {
        if(p[i] != & arr[i])
        {
            comparable tmp = arr[i];
            for (j = i; p[j] != &arr[i]; j = nextj)
            {
                nextj = p[j] - &arr[0];
                arr[j] = *p[j];
                p[j] = &arr[j];
            }
            arr[j] = tmp;
            p[j] = &arr[j];
        }
    }
}