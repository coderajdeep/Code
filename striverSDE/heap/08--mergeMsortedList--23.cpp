// Merge M sorted List -- 23
// Best approach
// Time complexity O(MlogM) + O(N*M*LogM)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
    for(ListNode* list : lists) {
        if(list) {
            minHeap.push({list->val, list});
        }
    }
    ListNode* dummy = new ListNode(0);
    ListNode* head = dummy;
    while(!minHeap.empty()) {
        pair<int, ListNode*> minElement = minHeap.top();
        minHeap.pop();
        dummy->next = minElement.second;
        dummy = dummy->next;
        if(dummy->next) {
            minHeap.push({dummy->next->val, dummy->next});
        }
    }
    return head->next;
}


// Brute force approach
// Time complexity O(N*M) + O(N*M*log(N*M)) + O(N*M)
// Space complexity O(N*M)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> nums;
    for(ListNode* list : lists) {
        while(list) {
            nums.push_back(list->val);
            list = list->next;
        }
    }
    sort(nums.begin(), nums.end());
    ListNode* dummy = new ListNode(0);
    ListNode* head = dummy;
    for(int num : nums) {
        dummy->next = new ListNode(num);
        dummy = dummy->next;
    }
    return head->next;
}

// Using merge 2 list utility function
// Time complexity O(M*N*N)
// Space complexity O(1)
class Solution {
    ListNode* merge2List(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(head1 && head2) {
            if(head1->val < head2->val) {
                dummy->next = head1;
                head1 = head1->next;
            }
            else {
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
        }
        if(head1) dummy->next = head1;
        if(head2) dummy->next = head2;
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = NULL;
        for(int i=0; i<n; ++i) {
            head = merge2List(head, lists[i]);
        }
        return head;
    }
};