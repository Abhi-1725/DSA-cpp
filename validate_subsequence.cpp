/*
Given two non-empty sets of arrays of integers, write a function that determines the second array is the subsequence of first array. 

A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but are of the same order as they appear in the array.  

Sample :
array = [5, 1, 22, 25, 6, -1, 8, 10]
sequence = [1, 6, -1, 10]
*/

//Solution1
using namespace std;

// O(n) time | O(1) space - where n is the length of the array 
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	int arrIndex = 0;
	int seqIndex = 0;
	while (arrIndex < array.size() && seqIndex < sequence.size())
	{
		if (array[arrIndex] == sequence[seqIndex])
		{
			seqIndex++;
		}
		arrIndex++;
	}
  return seqIndex == sequence.size();
}

// Solution 2
using namespace std;

// O(n) time | O(1) space - where n is the length of the array 
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	int arrIndex = 0;
	int seqIndex = 0;
	while (arrIndex < array.size() && seqIndex < sequence.size())
	{
		if (array[arrIndex] == sequence[seqIndex])
		{
			seqIndex++;
		}
		arrIndex++;
	}
  return seqIndex == sequence.size();
}

// Solution 3

// This file is initialized with a code version of this
// question's sample test case. Feel free to add, edit,
// or remove test cases in this file as you see fit!

class ProgramTest : public TestSuite {
public:
  void Run() {
    RunTest("Test Case 1", []() {
      vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
      vector<int> sequence = {1, 6, -1, 10};
      assert(isValidSubsequence(array, sequence));
    });
  }
