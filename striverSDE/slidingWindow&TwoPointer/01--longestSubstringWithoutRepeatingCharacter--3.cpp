// Longest substring without repeating character -- leetcode 3

// Time complexity O(2*n)
// Space complexity O(n)
// abcdefghii
// For this input, we need to traverse the entire string twice
int lengthOfLongestSubstring(string s) {
    int len = s.size(), low = 0, high = 0, maxLen = 0;
    unordered_set<char> uset;
    while(high < len) {
        if(uset.find(s[high]) == uset.end()) {
            maxLen = max(maxLen, high - low + 1);
            uset.insert(s[high]);
            ++high;
        }
        else {
            uset.erase(s[low]);
            ++low;
        }
    }
    return maxLen;
}

// Best solution -- single traversal for any input
// Time complexity O(n)
// Space complexity O(n)
int lengthOfLongestSubstring(string s) {
    int low = 0, high = 0, length = s.size(), maxLength = 0;
    unordered_map<char, int> umap;
    while(high < length) {
        auto it = umap.find(s[high]);
        if(it == umap.end() || it->second < low) {
            maxLength = max(maxLength, high - low + 1);
            umap[s[high]] = high;
            ++high;
        }
        else {
            low = it->second + 1;
        }
    }
    return maxLength;
}

// Time complexity O(n*n)
// Space complexity O(n)
int lengthOfLongestSubstring(string s) {
    int n = s.size(), len = 0;
    for(int i=0; i<n; ++i) {
        bool flag = true;
        unordered_set<char> uset;
        for(int j=i; j<n; ++j) {
            if(uset.find(s[j]) != uset.end()) {
                len = max(len, j - i);
                flag = false;
                break;
            }
            else {
                uset.insert(s[j]);
            }
        }
        if(flag) {
            len = max(len, n - i);
        }
    }
    return len;
}