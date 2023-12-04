// Time complexity O(h)
// Space complexity O(h)

void dfs(BinaryTreeNode<int> *node, int input, int& floor) {
	if(!node) return;
	if(node->data==input) {
		floor = input;
		return;
	}
	else if(node->data > input) {
		dfs(node->left, input, floor);
	}
	else {
		floor = node->data;
		dfs(node->right, input, floor);
	}
}

int Floor(BinaryTreeNode<int> *node, int input) {
	int floor = -1;
	dfs(node, input, floor);
	return floor;
}