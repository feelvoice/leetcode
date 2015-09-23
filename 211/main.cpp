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
    
    bool match(string word) {
        return dfs(0, word, root);
    }

private:    
    bool dfs(int idx, string &word, TrieNode *root) {
        if (idx == word.length()) return root->is_done;
        if (word[idx] == '.') {
            for (int i=0; i<26; i++) {
                if (root->next[i]) {
                    if (dfs(idx+1, word, root->next[i])) return true;
                }
            }
            return false;
        }
        else {
            int key = word[idx] - 'a';
            if (root->next[key]) {
                return dfs(idx+1, word, root->next[key]);
            }
            return false;
        }
    }

private:
    TrieNode* root;
};

class WordDictionary {
public:
    Trie *trie;

    WordDictionary() {
        trie = new Trie();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        trie->insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie->match(word);
    }  
};