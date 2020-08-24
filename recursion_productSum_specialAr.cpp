/* 
   WAF that takes in a "special" array and returns its product sum.
*/
#include <iostream>
#include <any>
#include <vector>

using namespace std;

// O(n) time | O(d) space - where n is the total number of elements in the 
// array, including sub-elements, and d is the greatest depth of "special"
// arrays in the array

int productSum(vector<any> array, int multiplier = 1) 
{
  int sum = 0;
	for(auto ele : array)
	{
		if(ele.type() == typeid(vector<any>))
		{
			sum += productSum(any_cast<vector<any>>(ele), multiplier + 1);
		}
		else
		{
			sum += any_cast<int>(ele);
		}
	}
	return sum * multiplier;
}
