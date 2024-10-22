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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<TreeNode*> a;
        a.push_back(root);
        vector<long long> all;
        while (!a.empty()) {
            vector<TreeNode*> b;
            long long sum = 0;
            for (auto& i : a) {
                sum += i->val;
                if (i->left) {
                    b.push_back(i->left);
                }
                if (i->right) {
                    b.push_back(i->right);
                }
            }
            a = b;
            all.push_back(sum);
        }
        sort(all.rbegin(), all.rend());
        return (all.size() >= k ? all[k - 1] : -1);
    }
};