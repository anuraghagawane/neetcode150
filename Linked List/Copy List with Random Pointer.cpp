/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    // map<original, copied>
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        // Node* newhead = getCopiedNode(head);
        // Node* ogNode = head;
        // Node* cpNode = newhead;

        // while(cpNode) {
        //     cpNode -> next = getCopiedNode(ogNode -> next);
        //     cpNode -> random = getCopiedNode(ogNode -> random);

        //     cpNode = cpNode -> next;
        //     ogNode = ogNode -> next;
        // }

        // return newhead;
        if(!head) return nullptr;

        Node* l1 = head;

        while(l1) {
            Node* l2 = new Node(l1 -> val);
            l2 -> next = l1 -> random;
            l1 -> random = l2;
            l1 = l1 -> next;
        }

        Node* newhead = head -> random;

        l1 = head;
        while(l1) {
            Node* l2 = l1 -> random;
            l2 -> random = l2 -> next == NULL ? NULL : l2 -> next -> random;
            l1 = l1 -> next;
        }

        l1 = head;
        while(l1) {
            Node* l2 = l1 -> random;
            l1 -> random = l2 -> next;
            l2 -> next = l1 -> next == NULL ? NULL : l1 -> next -> random;
            l1 = l1 -> next;
        }

        return newhead;
    }

private:
    Node* getCopiedNode(Node* node) {
        if(node == NULL) return NULL;
        if(mp.find(node) != mp.end()) return mp[node];
        else {
            Node* newNode = new Node(node -> val);
            mp[node] = newNode;

            return newNode;
        }
    }
};