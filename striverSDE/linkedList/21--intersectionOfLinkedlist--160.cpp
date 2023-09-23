// Intersection of two linkedlist -- leetcode 160

// Time complexity O(n)
// Space complexity O(n)
// Uisng unordered_set
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) {
        return nullptr;
    }
    unordered_set<ListNode*> s;
    while(headA) {
        s.insert(headA);
        headA = headA->next;
    }
    while(headB) {
        if(s.find(headB)!=s.end()) {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
}


// Time complexity O(n)
// Space complexity O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) {
        return nullptr;
    }
    ListNode *ptrA = headA, *ptrB = headB;
    while(ptrA && ptrB) {
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    // Either this one or next while loop
    while(ptrA && headA) {
        ptrA = ptrA->next;
        headA = headA->next;
    }
    while(ptrB && headB) {
        ptrB = ptrB->next;
        headB = headB->next;
    }
    while(headA && headB) {
        if(headA==headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}


// Time complexity O(n)
// Space complexity O(1)
int getLength(ListNode *head) {
    if(!head) {
        return 0;
    }
    if(!head->next) {
        return 1;
    }
    
    ListNode *slow = head, *fast = head;
    int count = 0;
    
    while(fast and fast->next) {
        ++count;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) {
        return (2*count + 1);
    }
    return 2*count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA or !headB) {
        return nullptr;
    }
    
    int n1 = getLength(headA);
    int n2 = getLength(headB);
    
    int d;
    bool first = true;
    
    if(n1<n2) {
        d = n2-n1;
        first = false;
    }
    else {
        d = n1-n2;
    }
    
    int count = 0;
    
    if(first) {
        while(headA) {
            if(count==d) {
                break;
            }
            ++count;
            headA = headA->next;
        }
    }
    else {
        while(headB) {
            if(count==d) {
                break;
            }
            ++count;
            headB = headB->next;
        }
    }
    
    while(headA and headB) {
        if(headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}