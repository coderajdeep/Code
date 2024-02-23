// Longest Repeating character replacement -- leetcode 424

// Time complexity O(26*n)
// Space complexity O(26)
int characterReplacement(string s, int k) {
    int low = 0, high = 0, maxLength = 0, maxFreq, windowLength, n = s.size();
    unordered_map<char, int> freq;

    while(high < n) {
        windowLength = high - low + 1;
        freq[s[high++]]++;
        maxFreq = 0;
        for(pair<char, int>p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        if((windowLength - maxFreq) <= k) {
            maxLength = max(maxLength, windowLength);
        }
        else {
            freq[s[low++]]--;
        }
    }
    return maxLength;
}