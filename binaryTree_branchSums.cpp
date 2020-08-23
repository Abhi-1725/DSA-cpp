/* WAF that takes in a Binary Tree and returns a list of its branch sums ordered
   from leftmost branch sum to rightmost branch sum.
	 A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree
	 branch is a path of nodes in a tree that starts at the root node and ends 
	 at any leaf node.
	 Each BinaryTree node has an integer value, a left child node and a right child 
	 node. Children nodes can either be BinaryTree nodes themselves or None/null.
*/
#include <iostream>
#include <vector>

using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

void calculateBranchSums(BinaryTree *node, int runningSum, vector<int> &sums);

// O(n) time | O(n) space - n is the number of nodes in the Binary Tree
vector<int> branchSums(BinaryTree *root) 
{
	vector<int> sums;
	calculateBranchSums(root, 0, sums);
	return sums;
	}
  
void calculateBranchSums(BinaryTree *node, int runningSum, vector<int> &sums)
{
	if(node == NULL)
	{
		return;
	}
int newRunningSum = runningSum + node->value;
if(node->left == NULL && node->right == NULL)
{
	sums.push_back(newRunningSum);
	return;
}

calculateBranchSums(node->left, newRunningSum, sums);
calculateBranchSums(node->right, newRunningSum, sums);
}
