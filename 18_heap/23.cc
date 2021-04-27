class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        for(auto& node: lists) {
            if(node) q.push(node);
        }
        while(!q.empty()) {
            cur->next = q.top(); q.pop();
            cur = cur->next;
            if(cur->next) q.push(cur->next);      
        }
        return dummy->next;
    }
};