/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int a = 0, b = 0;
        int x = 0;

        while (true) {
    
            if (!head) return ans;
            for (int j = b; j < n - x; j++) {
                if (!head) return ans;
                ans[a][j] = head->val;
                head = head->next;
                b++;
            }
            b--;
            a++;
            for (int i = a; i < m - x; i++) {
                if (!head) return ans;
                ans[i][b] = head->val;
                head = head->next;
                a++;
            }
            a--;
            b--;
            for (int j = b; j >= x; j--) {
                if (!head) return ans;
                ans[a][j] = head->val;
                head = head->next;
                b--;
            }
            b++;
            a--;
            for (int i = a; i >= x + 1; i--) {
                if (!head) return ans;
                ans[i][b] = head->val;
                head = head->next;
                a--;
            }
            a++;
            x++;
            b++;
        }
        return ans;
    }
};