class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode **next;
    bool is_done;
    TrieNode() {
        next = new TrieNode*[26];
        for (int i=0; i<26; i++) next[i] = NULL;
        is_done = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int key;
        TrieNode *cur = root;
        for (int i=0; i<word.length(); i++) {
            key = word[i] - 'a';
            if (cur->next[key] == NULL) {
                cur->next[key] = new TrieNode();
            }
            cur = cur->next[key];
        }
        cur->is_done = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int key;
        TrieNode *cur = root;
        for (int i=0; i<word.length(); i++) {
            key = word[i] - 'a';
            if (cur->next[key] == NULL) return false;
            cur = cur->next[key];
        }
        return cur->is_done;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int key;
        TrieNode *cur = root;
        for (int i=0; i<prefix.length(); i++) {
            key = prefix[i] - 'a';
            if (cur->next[key] == NULL) return false;
            cur = cur->next[key];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");