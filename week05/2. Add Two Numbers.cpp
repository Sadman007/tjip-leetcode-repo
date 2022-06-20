//TC: O(N)
//MC: O(N)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* tempNode = head;
        int carry = 0;
        while(l1 || l2){
            int l1_val = 0, l2_val = 0;
            if(l1){
                l1_val = l1->val;
                l1 = l1->next;
            }
            if(l2){
                l2_val = l2->val;
                l2 = l2->next;
            }
            cout<<l1_val<<"  "<<l2_val<<"   "<<carry<<'\n';
            head->val = (l1_val + l2_val + carry)%10;
            carry = (l1_val + l2_val + carry) / 10;
            if(!carry && !l1 && !l2) head->next = NULL;
            else {
                head->next = new ListNode();
                head = head->next;
            }
        }
        if(carry) head->val = carry;
        return tempNode;
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
