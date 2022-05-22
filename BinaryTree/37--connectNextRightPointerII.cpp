// leetcode 117

// Best iterative solution
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()) {
            int t = q.size();
            Node *prevNode = NULL;
            while(t--) {
                Node *curr = q.front();
                q.pop();
                if(prevNode) {
                    curr->next = prevNode;
                }
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
                prevNode = curr;
            }
        }
        return root; 
    }
};

// Iterative solution
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()) {
            int t = q.size();
            vector<Node*>arr(t);
            for(int i=0; i<t; ++i) {
                Node *curr = q.front();
                q.pop();
                arr[i] = curr;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            for(int i=0; i<t-1; ++i) {
                arr[i]->next = arr[i+1];
            }
        }
        return root;
    }
};