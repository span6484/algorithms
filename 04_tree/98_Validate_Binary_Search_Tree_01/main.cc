class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return flag;
        isValidBST(root->left);
        if(preval >= root->val && cnt != 0) {
            flag = false;
            return flag;
        } 
        preval = root->val;
        if(!cnt)
            cnt++;
        isValidBST(root->right);
        return flag;
    }
private:
    int preval = INT_MIN;
    int cnt = 0;
    bool flag = true;
};