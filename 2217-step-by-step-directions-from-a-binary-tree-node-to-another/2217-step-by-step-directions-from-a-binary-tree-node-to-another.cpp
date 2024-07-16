/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *      if (root->left) return func(root->left, val);.5int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include<bits/stdc++.h>
class Solution {
public:
    string start, end;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string temp;
        dfs(root, startValue, destValue, temp);
        int i = 0;
        int lena = start.size(), lenb = end.size();
        while (i < min(lena, lenb) && start[i] == end[i]) i++;
        return string(lena - i, 'U') + end.substr(i);
        
    }

    void dfs (TreeNode* root, int s, int e, string& str) {
        if (!root) return;
        if (root->val == s) start = str;
        if (root->val == e) end = str;
        str += 'L';
        dfs(root->left, s, e, str);
        str.pop_back();
        str += 'R';
        dfs(root->right, s, e, str);
        str.pop_back();
        return;
    }
   
};