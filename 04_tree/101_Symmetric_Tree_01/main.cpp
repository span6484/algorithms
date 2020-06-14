class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        deque<TreeNode*> dq;
        int len = -1;
        dq.push_front(root);
        while(!dq.empty()) {
            if(len == -1) {  
                root = dq.front();
                dq.pop_front();
                dq.push_front(root->left);
                dq.push_back(root->right);
                len = 0;
            }else { 
                if(!dq.front() && !dq.back()) {
                    dq.pop_front();
                    dq.pop_back();
                }else if((dq.front() == NULL) !=  (dq.back() == NULL)) {
                    return false;
                }else {
                    if(dq.front()->val != dq.back()->val) {
                        return false;
                    }else {
                        root = dq.front();
                        dq.pop_front();
                        dq.push_front(root->right);
                        dq.push_front(root->left);
                        root = dq.back();
                        dq.pop_back();
                        dq.push_back(root->left);
                        dq.push_back(root->right);
                    }
                }
            }
        }
        return true;
    }
};