class trieNode {
public:
    int cnt;
    trieNode* child[26];
    trieNode() {
        cnt = 0;
        fill(begin(child), end(child), nullptr);
    }
};

class trie {
public:
    trieNode* root;
    trie() {
        root = new trieNode();
    }

    int getIdx (char c) {
        return c - 'a';
    }

    void insert(string& str) {
        trieNode* node = root;
        for (auto& i : str) {
            int idx = getIdx(i);
            if (!node->child[idx]) {
                node->child[idx] = new trieNode();
            }
            node = node->child[idx];
            node->cnt++;
        }
    }

    int prefix(string& str) {
        trieNode* node = root;
        int cnt = 0;
        for (auto& i : str) {
            int idx = getIdx(i);
            if (!node->child[idx]) return cnt;
            node = node->child[idx];
            cnt += node->cnt;
        }
        return cnt;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        trie tr;
        for (auto& i : words) {
            tr.insert(i);
        }

        int n = words.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = tr.prefix(words[i]);
        }
        return ans;
    }
};