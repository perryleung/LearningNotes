template<typename comparable>
void inserationSort(vector<comparable> & arr)
{
	int j;
	for(int p = 1; p < arr.size(); p++)
	{
		comparable tmp = arr[p];
		for(j = p; j > 0 && tmp < arr[j-1]; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;
	}
}//O(n*n)
 
