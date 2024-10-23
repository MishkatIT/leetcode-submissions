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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> a;
        a.push_back(root);
        root->val = 0;
        while (true) {
            long long sum = 0;
            vector<TreeNode*> b;
            for (int i = 0; i < a.size(); i++) {
                if (a[i]->left) {
                    sum += a[i]->left->val;
                    b.push_back(a[i]->left);
                }
                if (a[i]->right) {
                    sum += a[i]->right->val;
                    b.push_back(a[i]->right);

                }
                if (a[i]->right && a[i]->left) {
                    a[i]->left->val += a[i]->right->val;
                    a[i]->right->val += a[i]->left->val - a[i]->right->val;
                }
            }
            if (b.empty()) break;
            for (int i = 0; i < b.size(); i++) {
            cout << sum << ' ' << b[i]->val << endl;
                b[i]->val = sum - b[i]->val;
            }
            a = b;
        }
        return root;
    }
};