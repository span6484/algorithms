class CQueue {
public:
    CQueue() {}
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st1.empty()) return -1;
        // 1 --> 2
        while(!st1.empty()) {
            auto tmp = st1.top(); st1.pop();
            st2.push(tmp);
        }
        // delete and 2-->1
        auto res = st2.top(); st2.pop();
        while(!st2.empty()) {
            auto tmp = st2.top(); st2.pop();
            st1.push(tmp);
        }
        return res;
    }
private:
    stack<int> st1;
    stack<int> st2;
};
