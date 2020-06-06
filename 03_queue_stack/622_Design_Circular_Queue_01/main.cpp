class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : k_(k), size_(0), tail_(-1), myQueue_(k) {}
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(k_ <= size_)
            return false;
        tail_ = (tail_ + 1) % k_;
        size_++;
        myQueue_[tail_] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size_ <= 0)
            return false;
        size_--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(size_ == 0)
            return -1;
        return myQueue_[(tail_ - size_ + k_ + 1) % k_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(size_ == 0)
            return -1;
        return myQueue_[tail_];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(size_ == 0) 
            return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(size_ == k_)
            return true;
        return false;
    }

private:
    const int k_;
    int size_;
    int tail_;
    vector<int> myQueue_;
};