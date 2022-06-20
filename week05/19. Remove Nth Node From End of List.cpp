//TC: O(N)
//MC: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* lastNode = head;
        ListNode* dumpNode = head;

        while(n--){
            lastNode = lastNode->next;
        }
        if(lastNode == NULL) return head->next;

        while(lastNode->next != NULL){
            lastNode = lastNode->next;
            dumpNode = dumpNode->next;
        }
        //cout<<dumpNode->val<<'\n';
        dumpNode->next = dumpNode->next->next;
        return head;
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
