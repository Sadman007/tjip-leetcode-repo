//TC: O(N)
//MC: O(N)

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> stk;
        ListNode* curNode = head;
        while(curNode){
            stk.push(curNode->val);
            curNode = curNode->next;
        }
        int mx = 0;
        while(head){
            mx = max(mx, head->val + stk.top());
            stk.pop();
            head = head->next;
        }

        return mx;
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
