/*
Write a function that takes in a non-empty array of distinct integers and an integer representing the target sum.  The function should find all triplets in the array  that sum up to the target sum and return a two-dimensional array of all these triplets.  The numbers in each triplets should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. 

If no three numbers sum up to the target sum , the function should return an empty array.  

input:
{"array": [12, 3, 1, 2, -6, 5, -8, 6], "targetSum": 0}

output:
[[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]
*/

#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	sort(array.begin(), array.end());
	vector<vector<int>> triplets;
	
	/*
	 left pointer is 1 + the current value pointed out by 'for loop' index
   right pointer points towards the last element of the array
	 hence we are using array.size() - 2 in the for loop to iterate
	 We also need 2 elements for left and right pointer after the element
	 pointed out by array index. 
	  array = [12, 3, 1, 2, -6, 5, -8, 6]
		targetSum = 0
		
	 */
	for (int i = 0; i < array.size() - 2; i++) 
	{
		int left = i + 1;
		int right = array.size() - 1; // last element of the array
		while (left < right)
		{
			int currentSum = array[i] + array[left] + array[right];
			if (currentSum == targetSum) 
			{
				triplets.push_back({array[i], array[left], array[right]});
				left++;
				right--;
			}
			else if (currentSum < targetSum)
			{
				left++;
			}
			else if (currentSum > targetSum)
			{
				right--;
			}
		}
	}
  return triplets;
}

// This file is initialized with a code version of this
// question's sample test case. Feel free to add, edit,
// or remove test cases in this file as you see fit!

class ProgramTest : public TestSuite {
public:
  void Run() {
    RunTest("Test Case 1", []() {
      vector<vector<int>> expected{{-8, 2, 6}, {-8, 3, 5}, {-6, 1, 5}};
      assert(threeNumberSum({12, 3, 1, 2, -6, 5, -8, 6}, 0) == expected);
    });
  }
};
