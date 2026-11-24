
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> st(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;

        while (temp->next != nullptr) {

            if (st.find(temp->next->val) != st.end()) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};
