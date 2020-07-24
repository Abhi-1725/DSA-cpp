/*
Two Number Sum:

Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers in the input array sum up to the target sum, the function should return them in an array (in any order).  If no two numbers sum up to the target sum, the function should return an empty array. 

Note that target sum has to be obtained by summing two different integers in the array;
you can't add single integer to itself in order to  obtain the target sum. 

you can assume there will be at most one pair of integers summing up to the target sum

array = [3, 5, -4 , 8, 11, 1, -1,  6]
targetSum  =  10
*/

#include <vector>
using namespace std;

// O(n^2) time 1 | O(1) space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	for (int i = 0; i < array.size() - 1; i++)
	{
		int num1 = array[i];
		for (int j = i + 1; j < array.size(); j++)
		{
			int num2 = array[j];
			if (num1 + num2 == targetSum)
			{
				return vector<int>{num1, num2};
			}
		}
	}
  return {};
}

/*
// This file is initialized with a code version of this
// question's sample test case. Feel free to add, edit,
// or remove test cases in this file as you see fit!

using namespace std;

class ProgramTest : public TestSuite {
public
	
	
  void Run() {
    RunTest("Test Case 1", []() {
      vector<int> output = twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 10);
      assert(output.size() == 2);
      assert(count(output.begin(), output.end(), -1));
      assert(count(output.begin(), output.end(), 11));
    });
  }
};
*/
