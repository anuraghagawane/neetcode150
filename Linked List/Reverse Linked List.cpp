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
    ListNode* reverseList(ListNode* head) {
        // return reverse(head, NULL);
        ListNode* root = head;
        ListNode* prev = NULL;
        while(root) {
            ListNode* next = root -> next;
            root -> next = prev;
            prev = root;
            root = next;
        }

        return prev;
    }

    ListNode* reverse(ListNode* root, ListNode* prev) {
        if(root == NULL) return prev;

        ListNode* head = reverse(root -> next, root);
        root -> next = prev;
        return head;
    }
};