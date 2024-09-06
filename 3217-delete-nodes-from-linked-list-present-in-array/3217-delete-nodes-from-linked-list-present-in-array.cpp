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
    map<int, bool> mp;
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for (auto& i : nums) {
            mp[i] = true;
        }
        return solve(head);
    }
    
    ListNode* solve(ListNode* head) {
        if (!head) return nullptr;
        if (mp[head->val]) {
            return solve(head->next);
        } else {
            head->next = solve(head->next);
            return head;
        }
    }
};
