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
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;

        ListNode* maxNode = head;
        current = head;
        
        while (current && current->next) {
            if (current->next->val < maxNode->val) {
                current->next = current->next->next;
            } else {
                maxNode = current->next;
                current = current->next;
            }
        }
        
        prev = nullptr;
        current = head;
        
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        
        return head;
    }
};
