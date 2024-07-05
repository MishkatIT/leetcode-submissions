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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prv = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        vector<int> cPoints;
        int pos = 0;
        while (nxt) {
            if (prv && nxt) {
                if (prv->val < cur->val && cur->val > nxt->val) {
                    cPoints.push_back(pos);
                }
                if (prv->val > cur->val && cur->val < nxt->val) {
                    cPoints.push_back(pos);
                }
            }
            prv = cur;
            cur = nxt;
            nxt = nxt->next;
            pos++;
        }
        vector<int> ans{-1, -1};
        if (cPoints.size() < 2) return ans;
        ans[0] = 1e9;
        for (int i = 0; i + 1 < cPoints.size(); i++) {
            ans[0] = min(ans[0], cPoints[i + 1] - cPoints[i]);
        }
        ans[1] = cPoints.back() - cPoints.front();
        return ans;
    }
};