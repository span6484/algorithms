
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeSet;
        return copyList(head, nodeSet);
    }
    Node* copyList(Node* head, unordered_map<Node*, Node*>& nodeSet) {
        if(!head) return head;
        // 如果表已经存储了直接查询返回
        if(nodeSet.find(head) != nodeSet.end()) return nodeSet[head];
        // 如果表未存储,先深拷贝这个结点然后添加入表
        Node* node = new Node(head->val);
        nodeSet[head] = node;
        // 递归连接，添加
        node->next = copyList(head->next, nodeSet);
        node->random = copyList(head->random, nodeSet);
        return node;
    }
};