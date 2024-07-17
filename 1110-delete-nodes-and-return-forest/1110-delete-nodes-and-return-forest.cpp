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
    set <TreeNode*> s;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        s.insert(root);
        map<int, bool> mp;
        for (auto& i : to_delete) {
            mp[i] = true;
        }
        solve(root, mp);
        vector<TreeNode*> ans (s.begin(), s.end());
        return ans;
    }

    void solve(TreeNode*& root, map<int, bool>& mp) {
        if (!root) return;
        if (mp[root->val]) {
            if (root->left) {
                s.insert(root->left);
                solve(root->left, mp);
            }
            if (root->right) {
                s.insert(root->right);
                solve(root->right, mp);
            }
            s.erase(root);
            root = nullptr;
        } else {
            solve(root->left, mp);
            solve(root->right, mp);
        }
    }
};