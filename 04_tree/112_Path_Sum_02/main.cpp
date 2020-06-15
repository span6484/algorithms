class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack<TreeNode*> sn;
        stack<int> ss;
        sn.push(root);
        ss.push(sum - root->val);
        while(!sn.empty()) {
            root = sn.top();
            sum = ss.top();
            sn.pop();
            ss.pop();
            if(!root->left && !root->right && sum == 0) return true;
            if(root->right) {
                sn.push(root->right);
                ss.push(sum - root->right->val);
            }
            if(root->left) {
                sn.push(root->left);
                ss.push(sum - root->left->val);
            }
        }
        return false;
    }
};