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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        return dfs(root, ans);
    }

    vector<int> dfs(TreeNode* root, vector<int>& ans) {
        if (!root) return ans;
        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->val);
        return ans;
    }

};