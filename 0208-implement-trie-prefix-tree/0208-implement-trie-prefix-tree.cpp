class trieNode{
public:
    bool isEnd;
    trieNode* child[26];
    trieNode() {
        isEnd = false;
        fill(begin(child), end(child), nullptr);
    }
};

class Trie {
public:
    trieNode* root;
    Trie() {    
        root = new trieNode();
    }

    int getIdx(char c) {
        return c - 'a';
    }
    
    void insert(string word) {
        trieNode* node = root;
        for (auto& c: word) {
            int idx = getIdx(c);
            if (!node->child[idx]) {
                node->child[idx] = new trieNode();
            } 
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* node = root;
        for (auto& c : word) {
            int idx = getIdx(c);
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        trieNode* node = root;
        for (auto& c: prefix) {
            int idx = getIdx(c);
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */