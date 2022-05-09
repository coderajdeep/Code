// tricky
// Insert and delete in doubly linked list
// Insert and delete (delete O(1) is not possible) beginning and end of circular linked list in Time Complexity O(1) 


// 1
// Count node of linked list

// recursive
class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        //Code here
        if(!head) {
            return 0;
        }
        
        return (1 + getCount(head->next));
    }
};

// iterative 
class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        //Code here
        if(!head) {
            return 0;
        }
        int count = 0;
        while(head) {
            ++count;
            head = head->next;
        }
        return count;
    }
};

// count using slow and fast pointer

class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        //Code here
        if(!head) {
            return 0;
        }
        int count = 0;
        Node *slow = head, *fast = head;
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
};




// (b)
// insert at beginning and end of linked list

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node *temp = new Node(x);
       if(!head) {
           head = temp;
       }
       else {
           temp->next = head;
           head = temp;
       }
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       Node *temp = new Node(x);
       if(!head) {
           head = temp;
       }
       else {
           Node *curr = head;
           while(curr->next) {
               curr = curr->next;
           }
           curr->next = temp;
       }
       return head;
    }
};

// (c)
// delete in linkedlist (given position)
// https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1/

Node* deleteNode(Node *head,int x) {
    
    // if given node is NULL
    if(!head) {
        return head;
    }
    
    // delete first node
    if(x==1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    int count = 2;
    
    Node *curr = head;
    
    while(curr and curr->next) {
        if(count==x) {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return head;
        }
        ++count;
        curr = curr->next;
    }
    
    return head;
}

// (d)
// doubly linked list insert at given pos (except head)

void addNode(Node *head, int pos, int data)
{
   // Your code here
   if(!head) {
       return;
   }
   Node *temp = new Node(data);
   int count = 0;
   Node *curr = head;
   
   while(curr) {
       if(count==pos) {
           
           temp->next = curr->next;
           
           if(curr->next){
                curr->next->prev = temp;
           }
           
           temp->prev = curr;
           curr->next = temp;
           break;
       }
       ++count;
       curr = curr->next;
   }
   
}


// (e)
// circular linkedlist traversal

// iterative traversal

void printList(struct Node *head) {
    // code here
    if(!head) {
        return;
    }
    
    Node *curr = head;
    
    do {
        cout<<curr->data<<" ";
        curr = curr->next;

    } while(curr!=head);
    
}

// recursive traversal

void helper(Node *curr, Node *head) {
    if(!curr) {
        return;
    }
    
    cout<<curr->data<<" ";
    
    if(curr->next!=head) {
        helper(curr->next, head);
    }
}

void printList(struct Node *head)
{
    // code here
    if(!head) {
        return;
    }
    
    helper(head, head);
}


// (f)
// insert beginning of circular linked list
// O(1) solution

Node *insertBegin(Node * head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}

// (g)
// insert end of circular linked list
// O(1) solution

Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return temp;
    }
}