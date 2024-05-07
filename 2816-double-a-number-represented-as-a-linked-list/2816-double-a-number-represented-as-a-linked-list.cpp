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
    
    int dbl(ListNode* head) {
        if(head == NULL) {
            return 0;
        }
        
        int a = dbl(head->next);
        int s = (head->val)*2 + a;
        
        if(s > 9) {
            head->val = s%10;
            return 1;
        } else {
            head->val = s;
            return 0;
        }
    }
    
    ListNode* doubleIt(ListNode* head) {
        int s = dbl(head);
        if(s > 0) {
            ListNode* nh = new ListNode(s);
            nh->next = head;
            return nh;
        }
        return head;
    }
};