// Valid Anagram -- leetcode 242

// Time complexity O(n)
// Space complexity O(n)
// This solution can be handled any type of valid char in cpp
bool isAnagram(string s, string t) {
    unordered_multiset<char>ms;
    for(char& ch:s) {
        ms.insert(ch);
    }
    for(char& ch:t) {
        auto it = ms.find(ch);
        if(it!=ms.end()) {
        ms.erase(it);
        }
        else {
        return false;
        }
    }
    return ms.empty();
}

// Time complexity O(n)
// Space complexity O(n)
// This will only handle lower case english latter
bool isAnagram(string& s, string& t) {
    int freq[26] = {0};
    int index;
    for(char& ch: s) {
        index = ch - 'a';
        freq[index]++;
    }
    for(char& ch: t) {
        index = ch - 'a';
        if(freq[index]) {
        --freq[index];
        }
        else {
        return false;
        }
    }
    for(int i=0; i<26; ++i) {
        if(freq[i]) {
        return false;
        }
    }
    return true;
}

// Time complexity O(nlogn)
// Space complexity O(1)
bool isAnagram(string& s, string& t) {
    int n1 = s.size();
    int n2 = t.size();
    if(n1!=n2) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i=0; i<n1; ++i) {
        if(s[i]!=t[i]) {
            return false;
        }
    }
    return true;
}