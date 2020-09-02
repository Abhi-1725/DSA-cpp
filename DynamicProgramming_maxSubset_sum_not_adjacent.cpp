/* WAF that takes in an array of positive integers and returns the 
   maximum sum of non-adjacent elements in the array.
	 
	 If a sum can't be generated , the function should return 0.
*/
#include <iostream>
#include <vector>

using namespace std;

// O(n) time | O(n) space
int maxSubsetSumNoAdjacent(vector<int> array) {
  if(array.size() == 0)
	{
		return 0;
	}
	else if(array.size() == 1)
	{
		return array[0];
	}
	vector<int> maxSums = array;
	maxSums[1] = max(array[0], array[1]);
	for(int i = 2; i < array.size(); i++)
	{
		maxSums[i] = max(maxSums[i - 1], maxSums[i - 2] + array[i]);
	}
  return maxSums[array.size() - 1];
}
