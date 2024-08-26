/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;


        function<void(Node*)> dfs = [&](Node* root) {
            if (!root) return;
            for (auto& v : root->children) {
                dfs(v);
            }
            ans.push_back(root->val);
        };

        dfs(root);
        return ans;
    }
};