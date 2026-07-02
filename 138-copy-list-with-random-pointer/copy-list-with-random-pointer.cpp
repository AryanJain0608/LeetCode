#include <map>
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
public:

    void insertAtTail (Node * &head, Node * &tail, int d) {

        Node * newNode = new Node (d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }

    }

    Node* copyRandomList(Node* head) {
        Node * clonehead = NULL;
        Node * clonetail = NULL;

        Node * temp = head;

        while (temp != NULL) {
            insertAtTail (clonehead, clonetail, temp -> val);
            temp = temp -> next;
        }

        unordered_map<Node *, Node *> oldToNewNode;

        Node * originalNode = head;
        Node * cloneNode = clonehead;
        while (originalNode != NULL) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        originalNode = head;
        cloneNode = clonehead;

        while (originalNode != NULL) {
            cloneNode -> random = oldToNewNode[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return clonehead;

    }
};