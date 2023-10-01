// Find Pair in doubly linkedlist for a given sum -- coding ninjas

// Time complexity O(n)
// Space complexity O(1)
// Use Two pointer method
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> ans;
    Node *tail = head;
    while(tail && tail->next) {
        tail = tail->next;
    }
    while(head && tail && (head->data < tail->data)) {
        int sum = head->data + tail->data;
        if(sum < k) {
            head = head->next;
        }
        else if(sum > k) {
            tail = tail->prev;
        }
        else {
            ans.push_back(make_pair(head->data, tail->data));
            head = head->next;
            tail = tail->prev;
        }
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
// using hasing method
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> ans;
    unordered_set<int> st;
    while(head) {
        int prevNum = (k - (head->data));
        if(st.find(prevNum) != st.end()) {
            ans.push_back(make_pair(prevNum, head->data));
        }
        st.insert(head->data);
        head = head->next;
    }
    return ans;
}