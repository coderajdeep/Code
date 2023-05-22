// https://www.codingninjas.com/codestudio/problems/implement-trie_631356

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {
    
private:

Trie* arr[26];
bool isEnd;

public:

    /** Initialize your data structure here. */
    Trie() {
        for(int i=0; i<26; ++i) {
            arr[i] = nullptr;
            isEnd = false;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string &word) {
        Trie* node = this;
        int n = word.size();
        for(int i=0; i<n; ++i) {
            int index = word[i] - 'a';
            if(node->arr[index]!=nullptr) {
                node = node->arr[index];
            }
            else {
                node->arr[index] = new Trie();
                node = node->arr[index];
            }
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string &word) {
        Trie* node = this;
        int n = word.size();
        for(int i=0; i<n; ++i) {
            int index = word[i] - 'a';
            if(node->arr[index]!=nullptr) {
                node = node->arr[index];
            }
            else {
                return false;
            }
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string &prefix) {
        Trie* node = this;
        int n = prefix.size();
        for(int i=0; i<n; ++i) {
            int index = prefix[i] - 'a';
            if(node->arr[index]!=nullptr) {
                node = node->arr[index];
            }
            else {
                return false;
            }
        }
        return true;
    }
};