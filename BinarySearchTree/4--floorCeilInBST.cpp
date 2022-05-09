// techiedelight
// https://techiedelight.com/practice/?id=mG1l
// https://techiedelight.com/practice/?id=E2ax


// iterative solution

class Solution
{
public:

	/*
		A BST node is defined as:

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

	pair<Node*,Node*> findFloorAndCeil(Node* root, Node* x)
	{
		// Write your code here...
		if(!root) {
			return {nullptr, nullptr};
		}
		
		// finding floor
		Node *curr = root, *floorNode = nullptr;
		int target = x->data;
		
		while(curr) {
			if(target == curr->data) {
				floorNode = curr;
				break;
			}
			else if(target > curr->data) {
				floorNode = curr;
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		
		Node *ceilNode = nullptr;
		curr = root;
		
		while(curr) {
			if(target == curr->data) {
				ceilNode = curr;
				break;
			}
			else if(target < curr->data) {
				ceilNode = curr;
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		return {floorNode, ceilNode};
	}
};

// recursive solution

class Solution
{
public:

	/*
		A BST node is defined as:

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
	
	void dfs(Node *root, Node* &fl, Node* &cl, int key) {
		if(!root) {
			return;
		}
		if(root->data == key) {
			fl = root;
			cl = root;
			return;
		}
		else if(root->data < key) {
			fl = root;
			dfs(root->right, fl, cl, key);
		}
		else {
			cl = root;
			dfs(root->left, fl, cl, key);
		}
	}

	pair<Node*,Node*> findFloorAndCeil(Node* root, Node* x)
	{
		// Write your code here...
		if(!root) {
			return {nullptr, nullptr};
		}
		Node *fl = nullptr, *cl = nullptr;
		int key = x->data;
		dfs(root, fl, cl, key);
		
		return {fl, cl};
	}
};



// codestudio

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(!root) {
        return -1;
    }
    TreeNode<int> *ans = nullptr;
    while(root) {
        if(root->val==X) {
            return root->val;
        }
        else if(X < root->val) {
            root = root->left;
        }
        else {
            ans = root;
            root = root->right;
        }
    }
    if(ans) {
        return ans->val;
    }
    return -1;
}