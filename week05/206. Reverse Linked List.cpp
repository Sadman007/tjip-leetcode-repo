//TC: O(n)
//MC: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev = NULL) {
        if(head == NULL) return prev;
        auto nextNode = head->next;
        head->next = prev;

        return reverseList(nextNode, head);

    }
};

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
