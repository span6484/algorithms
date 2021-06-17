class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left && root->right) 
            root->left->next = root->right;

        if(root->left && !root->right) 
            root->left->next = getNext(root->next);
        if(root->right) 
            root->right->next = getNext(root->next);
        connect(root->right);   
        connect(root->left);

        return root;
        
    }
    Node* getNext(Node* root) {
        if(!root) return root;
        if(root->left) return root->left;
        if(root->right) return root->right;
        return getNext(root->next);
    } 
};

