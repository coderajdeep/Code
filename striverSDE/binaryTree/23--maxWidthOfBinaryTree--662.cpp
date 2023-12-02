// Time complexity O(n)
// Space complexity O(maxWidth)
// https://youtu.be/ZbybYvcVLks?si=ou4d4H7yS_2949t8

int widthOfBinaryTree(TreeNode* root) {
    if(!root) {
        return 0;
    }
    
    queue<pair<TreeNode*, long long>>q;
    q.push({root, 0});
    long long ans = 0;
    
    while(!q.empty()) {
        
        int t = q.size();
        long long hi;
        // long long lo;
        bool low = true;
        long minIndex;
        
        while(t--) {
            auto curr = q.front();
            q.pop();
            TreeNode* currNode = curr.first;
            long long index = curr.second;
            
            if(low) {
                minIndex = index;
                // lo = index-minIndex;
                // lo will always be zero
                low = false;
            }
            
            index = index - minIndex;
            
            if(t==0) {
                hi = index;
            }
            
            
            if(currNode->left) {
                q.push({currNode->left, (2*index + 1)});
            }
            
            if(currNode->right) {
                q.push({currNode->right, (2*index + 2)});
            }
        }
        
        // ans = max(ans, (hi-lo+1));
        ans = max(ans, (hi+1));
    }
    return ans;
}