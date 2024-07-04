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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* patineta = head;
        ListNode* samsa = head;
        int sum = 0;
        while (samsa) {
            if (samsa->val == 0) {
                patineta->val = sum;
                if (samsa->next) {
                    patineta = patineta->next;
                } else {
                    patineta->next = nullptr;
                }
                sum = 0;
            } else {
                sum += samsa->val;
            }
            samsa = samsa->next;
        }
        return head;
    }
};