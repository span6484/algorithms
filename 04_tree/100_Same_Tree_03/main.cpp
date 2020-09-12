class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p == q;
        queue<TreeNode*> p_que;
        queue<TreeNode*> q_que;
        if(p->val == q->val) {
            p_que.push(p);
            q_que.push(q);
        }else {
            return false;
        }

        while(!p_que.empty() && !q_que.empty()) {
            p = p_que.front();
            p_que.pop();
            q = q_que.front();
            q_que.pop();
            if(p->left && q->left){
                if(p->left->val == q->left->val) {
                    p_que.push(p->left);
                    q_que.push(q->left);
                }else {
                    return false;
                }
            }else if(p->left != q->left) {
                return false;
            }
            if(p->right && q->right){
                if(p->right->val == q->right->val) {
                    p_que.push(p->right);
                    q_que.push(q->right);
                }else {
                    return false;
                }
            }else if(p->right != q->right) {
                return false;
            }
        }
        return true;
    }
};