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