// leetcode - 21

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Space O(1)
// Later i will return new list
// then space will be O(n+m) 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }
        if(!list2) {
            return list1;
        }
        
        ListNode *temp = new ListNode(0);
        ListNode *last = temp;
        
        while(list1 and list2) {
            if((list1->val) < (list2->val)) {
                last->next = list1;
                last = list1;
                list1 = list1->next;
            }
            else {
                last->next = list2;
                last = list2;
                list2 = list2->next;
            }
        }
        
        if(list1) {
            last->next = list1;
        }
        else if(list2) {
            last->next = list2;
        }
        
        return temp->next;
    }
};


// simple solution
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    
    if(NULL == l1) return l2;
    if(NULL == l2) return l1;
    
    ListNode* head=NULL;    // head of the list to return
    
    // find first element (can use dummy node to put this part inside of the loop)
    if(l1->val < l2->val)       { head = l1; l1 = l1->next; }
    else                        { head = l2; l2 = l2->next; }
    
    ListNode* p = head;     // pointer to form new list
    
    // I use && to remove extra IF from the loop
    while(l1 && l2){
        if(l1->val < l2->val)   { p->next = l1; l1 = l1->next; }
        else                    { p->next = l2; l2 = l2->next; }
        p=p->next;
    }
    
    // add the rest of the tail, done!
    if(l1)  p->next=l1;
    else    p->next=l2;
    
    return head;
}