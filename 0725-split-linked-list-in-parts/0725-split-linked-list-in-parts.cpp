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
    int sz = 0;
    ListNode* curHead;

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        curHead = head;
        getSize(head);
        int mx = sz / k;
        int rem = sz % k;
        
        for (int i = 0; i < k && curHead; i++) {
            ans[i] = curHead;
            int partSize = mx + (rem > 0 ? 1 : 0);
            rem--;
            curHead = solve(partSize);
        }
        return ans;
    }

    ListNode* solve(int goTill) {
        if (!curHead) return nullptr;
        
        ListNode* prev = nullptr;
        while (goTill-- && curHead) {
            prev = curHead;
            curHead = curHead->next;
        }
        
        if (prev) prev->next = nullptr;
        return curHead;
    }

    void getSize(ListNode* head) {
        while (head) {
            sz++;
            head = head->next;
        }
    }
};
