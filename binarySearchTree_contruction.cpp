/*Write a BST class for a Binary Search Tree. The class should support;
	-inserting values with the insert method.
	-Removing values with the remove method; 
	 this method should only remove the first instance of a given value.
	-Searching for values with the contains method.
	 
 Note that you can't remove values from a single-node tree. In other words, 
 calling the remove method on a single-node tree should simply not do anything.
 
 Each BST node has an integer value, a left child node, and a right child node.
 A node is said to be a valid BST node if and only if it satisfies the BST 
 properties: its value is strictly greater than the values of every node to its
 left; its value is less than or equal to the values of every node to its right;
 and its children nodes are either valid BST nodes themselves or None/null.
*/
#include <iostream>
#include <vector>

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  BST &insert(int val) 
	{
		if(val < value)
		{
			if(left == NULL)
			{
				BST *newBST = new BST(val);
				left = newBST;
			}
			else
			{
				left->insert(val);
			}
		}
		else
		{
			if(right == NULL)
			{
				BST *newBST = new BST(val);
				right = newBST;
			}
			else
			{
				right->insert(val);
			}
		}
    return *this;
  }

  bool contains(int val) 
	{
		if(val < value)
		{
			if(left == NULL)
			{
				return false;
			}
			else
			{
				return left->contains(val);
			}
		}
		else if(val > value)
		{
			if(right == NULL)
			{
				return false;
			}
			else
			{
				return right->contains(val);
			}
		}
		else
		{
			return true;
		}
  }

  BST &remove(int val, BST *parent = NULL) 
	{
		if(val < value)
		{
			if(left != NULL)
			{
				left->remove(val, this);
			}
		}
		else if(val > value)
		{
			if(right != NULL)
			{
				right->remove(val, this);
			}
		}
		else
		{
			if(left != NULL && right != NULL)
			{
				value = right->getMinValue();
				right->remove(value, this);
			}
			else if(parent == NULL)
			{
				if(left != NULL)
				{
					value = left->value;
					right = left->right;
					left = left->left;
				}
				else if(right != NULL)
				{
					value = right->value;
					left = right->left;
					right = right->right;
				}
				else
				{
					// As this is a single node tree; we do nothing;
				}
			}
			else if(parent->left == this)
			{
				parent->left = left != NULL ? left : right;
			}
			else if(parent->right == this)
			{
				parent->right = left != NULL ? left : right;
			}
		}
    return *this;
  }
	
	int getMinValue()
	{
		if(left == NULL)
		{
			return value;
		}
		else
		{
			return left->getMinValue();
		}
	}
};
