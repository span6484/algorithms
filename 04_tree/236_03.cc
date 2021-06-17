TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;           //递归边界
        if(root == p || root == q) return root;

        //分解为求左子树的子问题和右子树的子问题,注意是后序遍历
        TreeNode* left_have = lowestCommonAncestor(root->left,p,q);     
        TreeNode* right_have = lowestCommonAncestor(root->right,p,q);   
        if(left_have && right_have) return root;        //左右子树都有则返回root
        else return left_have ? left_have : right_have;     //如果左右子树中有一个子问题没得到结果，则返回得到结果的子问题.
}