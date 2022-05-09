// leetcode 199

// right view - recursive solution using hashing

class Solution {
public:
    
    void dfs(TreeNode *root, int level, unordered_map<int, int> &m) {
        if(!root) {
            return;
        }
        
        if(m.find(level)==m.end()) {
            m[level] = root->val;
        }
        
        dfs(root->right, level+1, m);
        dfs(root->left, level+1, m);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return vector<int>{};
        }
        
        unordered_map<int, int>m;
        
        dfs(root, 1, m);
        
        int n = m.size();
        
        vector<int>ans(n);
        
        for(int i=1; i<=n; ++i) {
            ans[i-1] = m[i];
        }
        
        return ans;
    }
};


// right view - iterative solution

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return vector<int>{};
        }
        
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        
        while(!q.empty()) {
            int t = q.size();
            bool flag = true;
            
            while(t--) {
                TreeNode *curr = q.front();
                q.pop();
                
                if(flag) {
                    ans.push_back(curr->val);
                    flag = false;
                }
                
                if(curr->right) {
                    q.push(curr->right);
                }
                
                if(curr->left) {
                    q.push(curr->left);
                }
            }
        }
        return ans;
    }
};


// right view
// recursive solution

class Solution {
public:
    
    void dfs(TreeNode *root,int level,int &maxLevel, vector<int> &ans) {
        if(!root) {
            return;
        }
        
        if(level==maxLevel) {
            ans.push_back(root->val);
            ++maxLevel;
        }
        
        dfs(root->right, level+1, maxLevel, ans);
        dfs(root->left, level+1, maxLevel, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return vector<int>{};
        }
        
        int maxLevel = 1;
        vector<int>ans;
        
        dfs(root, 1, maxLevel, ans);
        
        return ans;
    }
};



// left view
// iterative method
// https://techiedelight.com/practice/?id=s46V

vector<int> findLeftView(Node* root) {
    // Write your code here...
    
    if(!root) {
        return vector<int>{};
    }
    
    queue<Node*>q;
    q.push(root);
    vector<int>ans;
    
    while(!q.empty()) {
        
        int t = q.size();
        bool flag = true;
        
        while(t--) {
            Node *curr = q.front();
            q.pop();
            
            if(flag) {
                ans.push_back(curr->data);
                flag = false;
            }
            
            if(curr->left) {
                q.push(curr->left);
            }
            
            if(curr->right) {
                q.push(curr->right);
            }
        }
    }
    return ans;
}

// left view of binary tree
// recursive solution
// https://techiedelight.com/practice/?id=VbK1

void dfs(Node *root, int level, int &maxLevel, vector<int>&ans) {
		if(!root) {
			return;
		}
		
		if(level==maxLevel) {
			ans.push_back(root->data);
			++maxLevel;
		}
		
		dfs(root->left, level+1, maxLevel, ans);
		dfs(root->right, level+1, maxLevel, ans);
	}

	vector<int> findLeftView(Node* root)
	{
		// Write your code here...
		
		if(!root) {
			return vector<int>{};
		}
		
		vector<int>ans;
		int maxLevel = 1;
		dfs(root, 1, maxLevel, ans);
		
		return ans;
	}