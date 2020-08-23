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

/* Tests */
// This file is initialized with a code version of this
// question's sample test case. Feel free to add, edit,
// or remove test cases in this file as you see fit!

string sortAndStringify(vector<int> array) {
  sort(array.begin(), array.end());
  string s;
  for (int elem : array) {
    s += to_string(elem);
    s += ",";
  }
  return s;
}

bool isIncluded(vector<string> array, string str1) {
  for (string str2 : array) {
    if (str1 == str2) {
      return true;
    }
  }
  return false;
}

class ProgramTest : public TestSuite {
public:
  void Run() {
    RunTest("Test Case 1", []() {
      vector<vector<int>> output = fourNumberSum({7, 6, 4, -1, 1, 2}, 16);
      vector<string> output2{};
      for (vector<int> arr : output) {
        output2.push_back(sortAndStringify(arr));
      }
      vector<vector<int>> quadruplets{
          {7, 6, 4, -1},
          {7, 6, 1, 2},
      };
      assert(output2.size() == 2);
      for (vector<int> quadruplet : quadruplets) {
        string str1 = sortAndStringify(quadruplet);
        bool included = isIncluded(output2, str1);
        assert(included == true);
      }
    });
  }
};

