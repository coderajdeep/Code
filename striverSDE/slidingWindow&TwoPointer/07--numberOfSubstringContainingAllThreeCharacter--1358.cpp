// Number of substring containing all three characters -- leetcode 1358
// Time complexity O(n)
// Time complexity O(1)
int numberOfSubstrings(string s) {
    int n = s.size(), low = 0, high = 0, count = 0;
    unordered_map<char, int> umap;
    while(high < n) {
        umap[s[high]]++;
        while(umap['a'] && umap['b'] && umap['c']) {
            count += (n - high);
            umap[s[low]]--;
            ++low;
        }
        ++high;
    }
    return count;
}