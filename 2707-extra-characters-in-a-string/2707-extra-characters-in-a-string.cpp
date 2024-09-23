class trieNode{
public:
    bool isEnd;
    trieNode* child[26];
    trieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class trie{
public:
    trieNode* root;
    trie() {
        root = new trieNode();
    }

    int getIdx(char c) {
        return c - 'a';
    }

    void insert(const string& str) {
        trieNode* node = root;
        for (auto& c : str) {
            int idx = getIdx(c);
            if (!node->child[idx]) {
                node->child[idx] = new trieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }
};


class Solution {
public:
    trie tr;
    vector<int> dp;
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        for (auto& i : dictionary) {
            tr.insert(i);
        }
        dp.assign(n + 5, -1);
        return solve(0, s); 
    }
    int solve(int i, string& str) {
          if (i == str.size()) return 0;
          if (dp[i] != -1) return dp[i];
          int ans = 1 + solve(i + 1, str);
          trieNode* node = tr.root;
          for (int j = i; j < str.size(); j++) {
            if (!node->child[str[j] - 'a']) break;
            node = node->child[str[j] - 'a']; 
            if (node->isEnd) {
                ans = min(ans, solve(j + 1, str));
            }
          }
          return dp[i] = ans;
    }
};