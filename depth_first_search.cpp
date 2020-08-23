/* Given a Node class that has a name and an array of optinal children nodes.
	 When put together, nodes form an acyclic tree-like structure.
	 
	 Implement the depthFirstSearch method on the Node class, which takes in an
	 empty array, traverses the tree using the Depth-first Search approach
	 (specifically navigating the tree from left to right), stores all of the 
	 nodes' names in the input array, and returns it.
	 
	 If you're unfamiliar with Depth-first Search, we recommend watching the
	 Conceptual Overview section of this question's video explanation before 
	 starting to code.
*/

#include <vector>

using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;
  
	Node(string name) 
	{ 
		this->name = name; 
	}
  //Node(string str) { name = str; }
	
	//O(v +e) time | O(v) space
  vector<string> depthFirstSearch(vector<string> *array) 
	{
    array->push_back(this->name);
		for(int i = 0; i < this->children.size(); i++)
		{
			children[i]->depthFirstSearch(array);
		}
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
