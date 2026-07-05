/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<bool, int> isBalancedf (TreeNode * root) {
        if (root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<int, int> left = isBalancedf(root -> left);
        pair<int, int> right = isBalancedf(root -> right);

        bool left_ans = left.first;
        bool right_ans = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if (left_ans && right_ans && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedf(root).first;
    }
};