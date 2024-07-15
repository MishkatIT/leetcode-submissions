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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, vector<array<int, 2>>> adj;
        map<int, bool> child;
        for (auto& i : descriptions) {
            adj[i[0]].push_back({i[1], i[2]});
            child[i[1]] = true;
        }
        int parent;
        for (auto& i : descriptions) {
            if (child.find(i[0]) == child.end()) {
                parent = i[0];
                break;
            }
        }

        function<TreeNode*(int)> create = [&](int p) {
            TreeNode* root = new TreeNode(p);
            for (auto& child : adj[p]) {
                if (child[1]) {
                    root->left = create(child[0]);
                } else {
                    root->right = create(child[0]);
                }
            }
            return root;
        };

        return create(parent);
    }
};