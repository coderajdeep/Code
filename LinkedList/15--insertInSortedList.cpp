// geeks
// https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1/


class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node *temp = new Node(data);
        if(!head) {
            return temp;
        }
        
        // insert in first place
        if(head->data >= data) {
            temp->next = head;
            head = temp;
            return head;
        }
        
        // if linked list have only one element
        if(!head->next) {
            head->next = temp;
            return head;
        }
        
        Node *curr = head;
        
        while(curr->next) {
            if(curr->next->data >= data) {
                temp->next = curr->next;
                curr->next = temp;
                return head;
            }
            curr = curr->next;
        }
        
        // if control comes here then data must be inserted in last
        curr->next = temp;
        return head;
    }
};