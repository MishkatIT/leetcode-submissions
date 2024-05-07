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
    ListNode* reverse(ListNode* head) {
        ListNode* curr_node = head;
        ListNode* next_node = curr_node->next;
        curr_node->next = nullptr;

        while (next_node != nullptr) {
            ListNode* next_next_node = next_node->next;
            next_node->next = curr_node;

            curr_node = next_node;
            next_node = next_next_node;
        }

        return curr_node;
    }

    ListNode* lesgoo(ListNode* head) {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* curr_node = new_head;
        int carry = 0;

        while (curr_node->next != nullptr) {
            curr_node->next->val += curr_node->next->val;
            curr_node->next->val += carry;
            carry = curr_node->next->val / 10;
            curr_node->next->val %= 10;

            curr_node = curr_node->next;
        }

        while (carry > 0) {
            curr_node->next = new ListNode(carry % 10);
            carry /= 10;
            curr_node = curr_node->next;
        }

        return new_head->next;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* headdd = reverse(head);
        return reverse(lesgoo(headdd));
    }
};
