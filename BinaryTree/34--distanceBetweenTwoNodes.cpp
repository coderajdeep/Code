// there is one only traversal solution in geeks
// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/


// Time O(n) ; Space O(1)

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    Node* getLCA(Node *root, int a, int b) {
        if(!root) {
            return nullptr;
        }
        if(root->data==a or root->data==b) {
            return root;
        }
        Node *l = getLCA(root->left, a, b);
        Node *r = getLCA(root->right, a, b);
        
        if(l and r) {
            return root;
        }
        if(l) {
            return l;
        }
        if(r) {
            return r;
        }
        return nullptr;
    }
    
    int getLevel(Node *root, int level, int target) {
        if(!root) {
            return -1;
        }
        if(root->data==target) {
            return level;
        }
        int l = getLevel(root->left, level+1, target);
        if(l!=-1) {
            return l;
        }
        return getLevel(root->right, level+1, target);
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        if(!root or a==b) {
            return 0;
        }
        
        // if a or b not exist
        if(getLevel(root, 0, a)==-1 or getLevel(root, 0, b)==-1) {
            return 0;
        }
        
        Node *lca = getLCA(root, a, b);
        
        return getLevel(lca, 0, a) + getLevel(lca, 0, b);
    }
};


// techidelight

/*
https://www.techiedelight.com/distance-between-given-pairs-of-nodes-binary-tree/

Given the root of a binary tree and two tree nodes, x and y, return the distance between x and y in the binary tree. The distance between two nodes is defined as the total number of edges in the shortest path from one node to other.

For example, consider the following binary tree.

		  1
		/   \
	   /	 \
	  2		  3
	   \	 / \
		4   5   6
		   /	 \
		  7		  8

Input: x = Node 7, y = Node 6
Output: 3

Input: x = Node 4, y = Node 8
Output: 5

Input: x = Node 5, y = Node 5
Output: 0

Note: The solution should return a negative value if either x or y is not the actual node in the tree.

*/

// Time O(n); space O(n)
// Space can be optimized

class Solution
{
public:

	/*
		A binary tree node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/
	
	bool dfs(Node *root,Node *target, vector<Node*> &arr) {
		if(!root) {
			return false;
		}
		if((root==target) or dfs(root->left, target, arr) or dfs(root->right, target, arr)) {
			arr.push_back(root);
			return true;
		}
		return false;
	}

	int findDistance(Node* root, Node* x, Node* y)
	{
		// Write your code here...
		if(!root) {
			return -1;
		}
		vector<Node*> arr1, arr2;
		
		if(dfs(root, x, arr1) and dfs(root, y, arr2)) {
			int n1 = arr1.size();
			int n2 = arr2.size();
			
			int count = 0, i = n1-1, j = n2-1;
			
			while(i>=0 and j>=0) {
				if(arr1[i--]==arr2[j--]) {
					++count;
				}
			}
			
			if(min(n1, n2)==count) {
				return abs(n1-n2);
			}
			return (n1+n2 - (2*count));
		}
		return -1;
	}
};
