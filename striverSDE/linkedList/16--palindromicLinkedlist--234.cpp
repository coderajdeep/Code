// Check if a linkedlist is palindrom or not -- leetcode 234
// Will do it by using recursion

// Fast and slow pointer approach
// Time complexity O(n)
// Space complexity O(1)
ListNode* reverseLinkedList(ListNode* root) {
    if(!root || !root->next) {
        return root;
    }
    ListNode *curr = root, *prev = nullptr, *nxt = nullptr;
    while(curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {
    if(!head || !head->next) {
        return true;
    }
    ListNode *slow = head, *fast = head, *prev = head;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    if(fast) {
        slow = slow->next;
    }
    slow = reverseLinkedList(slow);
    while(head && slow) {
        if(head->val!=slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

// Time complexity O(n)
// Space complexity O(n)
// Using stack
bool isPalindrome(ListNode* head) {
        
    if(!head or !head->next) {
        return true;
    }
    
    stack<int>st;
    
    ListNode *curr = head;
    
    while(curr) {
        st.push(curr->val);
        curr = curr->next;
    }
    
    curr = head;
    
    while(curr) {
        if(curr->val != st.top()) {
            return false;
        }
        st.pop();
        curr = curr->next;
    }

    return true;
}