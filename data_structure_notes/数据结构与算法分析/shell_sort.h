template <typename comparable>
void shellSort(vector<comparable> arr)
{
	for(int gap = arr.size()/2; gap > 0; gap /= 2)
	{
		for(int i = gap; i < arr.size(); i++)
		{
			comparable tmp = arr[i];
			int j = i;
			for(; j >= gap && tmp < arr[j - gap]; j -= gap)//j >= gap , arr[gap] is the first element to see and compare 
				arr[j] = arr[j - gap];
			/*
			for(; j > 0; j -= gap)
				if(tmp < arr[j - gap])
					arr[j] = arr[j - gap];
			*/
			arr[j] = tmp;
		}
	}
}
//O(n*n)
