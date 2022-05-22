// https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/


// recursive solution

bool dfs(Node *root, int level, vector<int> &ans) {
    if(!root) {
        return false;
    }
    if(level==0) {
        ans.push_back(root->data);
        return true;
    }
    
    bool l = dfs(root->left, level-1, ans);
    bool r = dfs(root->right, level-1, ans);
    
    return (l || r);
}

vector<int> Kdistance(struct Node *root, int k)
{
    if(!root) {
        return vector<int>{};
    }
    
    vector<int>ans;
    
    dfs(root, k, ans);
    
    return ans;
}

// recursive approach
// similar, just void return type

void dfs(Node *root, int level, vector<int> &arr) {
    if(!root) return;
    if(level==0) {
        arr.push_back(root->data);
        return;
    }
    dfs(root->left, level-1, arr);
    dfs(root->right, level-1, arr);
}

vector<int> Kdistance(struct Node *root, int k) {
  // Your code here
  if(!root) return {};
  vector<int> arr;
  dfs(root, k, arr);
  return arr;
}


// Iterative solution

// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
    if(!root || k<0)
        return {};
    
    int ht = 0;
    queue<Node*>q;
    q.push(root);
    vector<int> ans;
    
    while(!q.empty()) {
        int width = q.size();
        bool flag = false;
        
        while(width--) {
            
            Node *curr = q.front();
            q.pop();
            
            if(ht==k) {
                ans.push_back(curr->data);
                flag = true;
            }
            
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        if(flag)
            return ans;
        ht += 1;
    }
    
    return ans;
}