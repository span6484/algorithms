class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top())/2.0;
    }
private:
    priority_queue<int> lo;   // max heap
    priority_queue<int, vector<int>, greater<int> > hi;
};


"top","reset","reset","addScore","reset"]
[1],[3],[4],[2,70],[2]]

[3,76],[4,68],[5,89],[6,31],[7,7],[8,1],[9,98],[10,42]