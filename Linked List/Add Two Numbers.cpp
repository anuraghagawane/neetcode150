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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* ansnode = ans;
        int carry = 0;

        while(l1 && l2) {
            int addVal = l1 -> val + l2 -> val + carry;
            carry = addVal / 10;
            addVal = addVal % 10;

            ListNode* newNode = new ListNode(addVal);
            ansnode -> next = newNode;
            ansnode = ansnode -> next;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1) {
            int addVal = l1 -> val + carry;
            carry = addVal / 10;
            addVal = addVal % 10;

            ListNode* newNode = new ListNode(addVal);
            ansnode -> next = newNode;
            ansnode = ansnode -> next;

            l1 = l1 -> next;
        }

        while(l2) {
            int addVal = l2 -> val + carry;
            carry = addVal / 10;
            addVal = addVal % 10;

            ListNode* newNode = new ListNode(addVal);
            ansnode -> next = newNode;
            ansnode = ansnode -> next;

            l2 = l2 -> next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            ansnode -> next = newNode;
        }

        return  ans -> next;
    }
};