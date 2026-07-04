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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        ListNode * temp = head;
        int cnt = 0;
        while (temp != NULL) {
            temp = temp -> next;
            cnt++;
        }

        if (n == cnt) {
            ListNode * head1 = head -> next;
            delete head;
            return head1;
        }

        temp = head;
        for (int i = 1; i < cnt-n; i++) {
            temp = temp -> next;
        }

        ListNode * nodeToDelete = temp -> next;
        temp -> next = nodeToDelete -> next;
        nodeToDelete -> next = NULL;
        delete nodeToDelete;

        return head;
    }
};