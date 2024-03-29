// Sort K sorted array -- geeks
// Time complexity O(NlogK)
// Space complexity O(K) + O(N) which is used to stored/returned the answer
vector <int> nearlySorted(int arr[], int num, int K){
    vector<int> sortedArray(num);
    priority_queue<int, vector<int>, greater<int>> pq;
    // 1 ≤ k < n
    for(int i=0; i<K; ++i) {
        pq.push(arr[i]);
    }
    for(int i=0; i<num; ++i) {
        if((i+K) < num) pq.push(arr[i+K]);
        sortedArray[i] = pq.top();
        pq.pop();
    }
    return sortedArray;
}