class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 1;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto node = que.front(); que.pop();
                if(!node->right && !node->left) return depth;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right); 
            }
            depth++;
        }
        return depth;
    }
};