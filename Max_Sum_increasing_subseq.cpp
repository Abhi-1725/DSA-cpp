/* WAF that takes in a non-empty array of integers and returns the greatest 
   sum that can be generated from a strictly-increasing subsequence in the
	 array as well as an array of the numbers in that subsequence.
	 
	 A subsequence of an array is a set of numbers that aren't necessarily 
	 adjacent in the array but that are in the same order as they appear in the 
	 array but that are in the same order as they appear in the array. For instance,
	 the numbers [1, 2, 3] from a subsequence of the array[1, 2, 3, 4], and so do 
	 the numbers [2, 4]. Note that a single number in an array and the array itself
	 are both valid subsequences of the array.
	 
	 Assuming that there will be only one increasing subsequence with the greatest
	 sum. 
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum);

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array)
{
	vector<int> sequences(array.size(), INT_MIN);
	vector<int> sums = array;
  int maxSumIdx = 0;
	
	for(int i = 0; i < array.size(); i++)
	{
		int currentNum = array[i];
		for(int j = 0; j < i; j++)
		{
			int otherNum = array[j];
			if(otherNum < currentNum & sums[j] + currentNum >= sums[i])
			{
				sums[i] = sums[j] + currentNum;
				sequences[i] = j;
			}
		}
		if(sums[i] >= sums[maxSumIdx])
		{
			maxSumIdx = i;
		}
	}
	return buildSequence(array, sequences, maxSumIdx, sums[maxSumIdx]);
}

vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum)
{
	vector<vector<int>> sequence = {{}, {}};
	sequence[0].push_back(sum); 

	while(currentIdx != INT_MIN)
	{
		sequence[1].insert(sequence[1].begin(), array[currentIdx]);
		currentIdx = sequences[currentIdx];
	}
	return sequence;
}
