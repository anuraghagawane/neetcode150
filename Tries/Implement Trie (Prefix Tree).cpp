struct Node {
    Node* next[26];
    bool isWord;
    bool isPre;
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto ch: word) {
            if(node -> next[ch - 'a'] == NULL) {
                node -> next[ch - 'a'] = new Node();
            }
            node = node -> next[ch - 'a'];
            node -> isPre = true;
        }
        node -> isWord = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto ch: word) {
            if(node -> next[ch - 'a'] == NULL) {
                return false;
            }
            node = node -> next[ch - 'a'];
        }
        return node -> isWord;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto ch: prefix) {
            if(node -> next[ch - 'a'] == NULL) {
                return false;
            }
            node = node -> next[ch - 'a'];
        }
        return node -> isPre;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */