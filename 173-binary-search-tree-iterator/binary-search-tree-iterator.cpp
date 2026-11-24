
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        int ans = node->val;

        if (node->right != nullptr) {
            pushLeft(node->right);
        }

        return ans;
    }

    bool hasNext() {
        return !st.empty();
    }
};
