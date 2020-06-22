class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        if(!root) return res + "]";
        queue<TreeNode*> que;
        que.push(root);
        int islevel = 1;
        while(!que.empty()) {
            int len = que.size();
            if(islevel == 0) {
                break;
            }
            islevel = 0;
            for(int i = 0; i < len; i++) {
                root = que.front();
                que.pop();
                if(!root) {
                    res += "null";
                }else {
                    if(root->left || root->right) islevel = 1;
                    res += to_string(root->val);
                    que.push(root->left);
                    que.push(root->right);
                }
                res += ","; 
            }
        }
        res[res.size() - 1] = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") return nullptr;
        queue<TreeNode*> que;
        int cur = 1;

        while(cur < data.size() - 1) {
            if(data[cur] == 'n') {
                cur += 5; // null,
                que.push(NULL);
            }else if(data[cur] == ',') {
                cur++;
            }else {
                string num = "";
                while(isNum(data[cur]) || data[cur] == '-') {
                    num += data[cur++];
                }
                cout << num << endl;
                cout << stoi(num) << endl;
                TreeNode* tmp = new TreeNode(stoi(num));
                que.push(tmp);
            }
        }

        queue<TreeNode*> parent;
        TreeNode* root = que.front();

        parent.push(root);
        que.pop();
        while(!que.empty()) {
            TreeNode* node = parent.front();
            parent.pop();
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();
            if(left) {
                parent.push(left);
                node->left = left;
            }
            if(right) {
                parent.push(right);
                node->right = right;
            }
        }
        return root;
    }
    
private:
    bool isNum(char ch) {
        return ch <= '9' && ch >= '0';
    }
};
