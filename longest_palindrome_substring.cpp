/* WAF that, given a string, returns its longest palindromic substring
   A palindromic is defined as a string that's written the same forward
	 and backward. Note that single-character strings are palindromes.
	 
	 You can assume that there will only be one longest palindromic substring.
*/

#include<iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

// O(n^3) time | O(1) space
string longestPalindromicSubstring(string str) 
{
  string longest = "";
	for(int i = 0; i < str.length(); i++)
	{
		for(int j = 0; j < str.length(); j++)
		{
			string substring = str.substr(i, j + 1 - i);
			if(substring.length() > longest.length() && isPalindrome(substring))
			{
				longest = substring;
			}
		}
	}
  return longest;
}

bool isPalindrome(string str)
{
	int leftIdx = 0;
	int rightIdx = str.length() - 1;
	while(leftIdx < rightIdx)
	{
		if(str[leftIdx] != str[rightIdx])
		{
			return false;
		}
		leftIdx++;
		rightIdx--;
	}
	return true;
}
