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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        solve(head);
        return head;
    }
    void solve(ListNode* head) {
    if (!head || !head->next) return;
        int g = __gcd(head->val, head->next->val);
        ListNode* temp = new ListNode(g);
        temp->next = head->next;
        head->next = temp;
        solve(head->next->next);
    } 
};