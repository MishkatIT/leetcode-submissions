/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> depth, level;
    map<int, vector<int>> lmx;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        getLevel(root, 0);
        for (auto& i : level) {
            lmx[i.second].push_back(depth[i.first]);
        }
        for (auto& i : lmx) {
            sort(i.second.rbegin(), i.second.rend());
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int cur = queries[i];
            int lvl = level[cur];
            if (lmx[lvl].size() == 1) {
                ans[i] = lvl - 1;
            } else if (lmx[lvl][0] == depth[cur]) {
                ans[i] = lmx[lvl][1] + lvl;
            } else {
                ans[i] = lmx[lvl][0] + lvl;
            }
        }
        return ans;
    }
    int dfs(TreeNode* root) {
        if (!root) return -1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return depth[root->val] = max(l, r) + 1;
    }
    void getLevel(TreeNode* root, int l) {
        if (!root) return;
        getLevel(root->left, l + 1);
        getLevel(root->right, l + 1);
        level[root->val] = l;
    }
};