class trieNode {
public:
    bool isEnd;
    trieNode* child[10];
    trieNode() {
        isEnd = false;
        fill(begin(child), end(child), nullptr);
    }
};

class trie {
public:
    trieNode* root;
    trie() {
        root = new trieNode;
    }

    void insert(string str) {
        trieNode* node = root;
        for (auto& c : str) {
            if (!node->child[c - '0']) {
                node->child[c - '0'] = new trieNode();
            }
            node = node->child[c - '0'];
        }
        node->isEnd = true;
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie tr;
        for (auto& i : arr1) {
            tr.insert(to_string(i));
        }
        int mx = 0;
        for (auto& i : arr2) {
            trieNode* node = tr.root;
            int cnt = 0;
            string cur = to_string(i);
            for (auto& x : cur) {
                if (!node->child[x - '0']) break;
                cnt++;
                mx = max(mx, cnt);
                node = node->child[x - '0'];
            }
        }
        return mx;
    }
};