struct Node {
    Node* next[26];
    bool isWord;
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto ch: word) {
            if(node -> next[ch - 'a'] == NULL) {
                node -> next[ch - 'a'] = new Node();
            }
            node = node -> next[ch - 'a'];
        }

        node -> isWord = true;
    }
    
    bool search(string word) {
        Node* node = root;
        return fuzzySearch(0, word, node);
    }

private:
    bool fuzzySearch(int i, string word, Node* node) {
        if(i == word.length()) return node -> isWord;
        char ch = word[i];
        if(ch == '.') {
            for(auto nd : node -> next) {
                if(nd != NULL && fuzzySearch(i + 1, word, nd)) {
                    return true;
                }
            }
            return false;
        }
        else {
            if(node -> next [ch - 'a'] == NULL) {
                return false;
            }
            return fuzzySearch(i + 1, word, node -> next [ch - 'a']);
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */