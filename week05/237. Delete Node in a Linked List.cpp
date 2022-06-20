//TC: O(1)
//MC: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* dumpNode = node->next;
        node->val = node->next->val;
        node->next = node->next->next;

        delete(dumpNode);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
