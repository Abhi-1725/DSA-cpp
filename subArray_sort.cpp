/* WAF that takes in an array of at least two integers and that returns an array
	 of the starting and ending indices of the smallest subarray in the input array
	 that needs to be sorted in place in order for the entire input array to be
	 sorted in ascending order. 
	 
	 if the input array is already sorted, the function should return [-1, -1]
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool is_Out_Of_Order(int i, int num, vector<int> array);
vector<int> subarraySort(vector<int> array) {
  int min_Out_Of_Order = INT_MAX;
	int max_Out_Of_Order = INT_MIN;
	
	for(int i = 0; i < array.size(); i++)
	{
		int num = array[i];
		if(is_Out_Of_Order(i, num, array))
		{
			min_Out_Of_Order = min(min_Out_Of_Order, num);
			max_Out_Of_Order = max(max_Out_Of_Order, num);
		}
	}
	if(min_Out_Of_Order == INT_MAX)
	{
		return vector<int>{-1, -1};
	}
	int subarray_Left_Indx = 0;
	while(min_Out_Of_Order >= array[subarray_Left_Indx])
	{
		subarray_Left_Indx++;
	}
	int subarray_Right_Indx = array.size() - 1;
	while(max_Out_Of_Order <= array[subarray_Right_Indx])
	{
		subarray_Right_Indx--;
	}
	return vector<int>{subarray_Left_Indx, subarray_Right_Indx};
}

bool is_Out_Of_Order(int i, int num, vector<int> array)
{
	if(i == 0)
		 {
			 return num > array[i + 1];
		 }
	if(i == array.size() - 1)
	{
		return num < array[i - 1];
	}
	return (num > array[i + 1]) || (num < array[i - 1]);
}
