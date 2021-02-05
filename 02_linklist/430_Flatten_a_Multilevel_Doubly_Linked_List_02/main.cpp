class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
private:
    Node* prev_;
    void dfs(Node* head) {
        if(!head) return;
        if(prev_) {
            prev_->next = head;
            head->prev = prev_;
        }
        prev_ = head;
        auto next = head->next;
        dfs(head->child);
        head->child = nullptr;
        dfs(next);
    }
};

