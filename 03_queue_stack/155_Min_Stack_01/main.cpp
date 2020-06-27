class MinStack {
public:
    MinStack() {};
    
    void push(int x) {
        data.push_back(x);
        if(!min.size() || x <= min.back()) {
            min.push_back(x);
        }
    }
    
    void pop() {
        if(data.size() <= 0) return;
        if(data.back() == min.back()) {
            min.pop_back();
        }
        data.pop_back();
    }
    
    int top() {
        if(data.size() <= 0) return 0;
        return data.back();
    }
    
    int getMin() {
        if(min.size() <= 0) return 0;
        return min.back();
    }
private: 
    vector<int> data;
    vector<int> min;
};
