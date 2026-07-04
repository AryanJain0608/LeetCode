/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp = headA;
        int cntA = 0;

        while (temp != NULL) {
            cntA++;
            temp = temp -> next;
        }

        temp = headB;
        int cntB = 0;

        while (temp != NULL) {
            cntB++;
            temp = temp -> next;
        }

        if (cntA > cntB) {
            while (cntA != cntB) {
                cntA--;
                headA = headA -> next;
            }
        }

        if (cntB > cntA) {
            while (cntB != cntA) {
                cntB--;
                headB = headB -> next;
            }
        }

        while (headA != headB && headA != NULL && headB != NULL) {
            headA = headA -> next;
            headB = headB -> next;
        }

        if (headA == headB) {
            return headA;
        }
        else {
            return NULL;
        }
    }
};