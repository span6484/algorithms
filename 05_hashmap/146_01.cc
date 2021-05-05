class LRUCache {
public:
    LRUCache(int capacity)
        : capacity_(capacity) {
    }
    
    int get(int key) {
        if(map_.count(key)) { // exists
            auto it = map_[key]; 
            li_.splice(li_.begin(), li_, it);  // 访问了就移动到第一个
            return it->second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map_.count(key)) { // exists, update
            auto it = map_[key];
            it->second = value;
            li_.splice(li_.begin(), li_, it);  // 访问了就移动到第一个
        } else {  // add 
            if(li_.size() == capacity_) {  // 满了就把最后一个删掉
                auto it = li_.back();
                map_.erase(it.first);
                li_.pop_back();
            }
            li_.push_front({key, value});
            map_[key] = li_.begin();
        }
    }
private:
    list<pair<int, int> > li_;
    int capacity_;
    unordered_map<int, list<pair<int, int> >::iterator> map_;
};