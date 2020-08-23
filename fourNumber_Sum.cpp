/*  
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Average: O(n^2) time | O(n^2) space - n is length of the input array
// Worst: O(n^3) time | O(n^2) space
vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) 
{
	unordered_map<int, vector<vector<int>>> all_pairSums;
	vector<vector<int>> quadruplets{};
	
	for(int i = 1; i < array.size() - 1; i++)
	{
		for(int j = i + 1; j < array.size(); j++)
		{
			int currentSum = array[i] + array[j];
			int difference = targetSum - currentSum;
			
			if(all_pairSums.find(difference) != all_pairSums.end())
			{
				for(vector<int> pair : all_pairSums[difference])
				{
					pair.push_back(array[i]);
					pair.push_back(array[j]);
					quadruplets.push_back(pair);
				}
			}
		}
		for(int k = 0; k < i; k++)
		{
			int currentSum = array[i] + array[k];
			if(all_pairSums.find(currentSum) == all_pairSums.end())
			{
				all_pairSums[currentSum] = vector<vector<int>>{{array[k], array[i]}};
			}
			else
			{
				all_pairSums[currentSum].push_back(vector<int>{array[k], array[i]});
			}
		}
	}
  return quadruplets;
}
