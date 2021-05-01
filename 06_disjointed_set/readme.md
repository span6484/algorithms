## Disjointed set 
 	128 	
	130 	
	200 	
	261 	
	305 	
	323 	
	399 	
	547 	
	684 	
	685 	
	721 	
	737 	
	765 	
	778 	
	803 	
	839 	
	924 	
	928 	
	947 	
	952 	
	959 	
	990 	

## 

https://blog.csdn.net/violet_echo_0908/article/details/47377415

https://labuladong.gitee.io/algo/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/UnionFind%E7%AE%97%E6%B3%95%E8%AF%A6%E8%A7%A3.html

## 模板

```cpp
class UF {
public:
    UF(int num) 
        : parent(num), 
        size(num) {
        for(int i = 0; i < num; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if(x != parent[x]) {
            x = find(parent[x]);
        }
        return parent[x]; // why not x?
    } 
    bool merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return false;
        if(size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
        return true;
    }
private:
    vector<int> parent;
    vector<int> size;
};

```


## 128. Longest Consecutive Sequence 01 Union find simplest 

很明显嵌套肯定不满足O(N)的条件，但是这里主要是熟悉下并查集的模板。如果是能在set里找到num +/- 1(连续)，那么就连接起来，然后每次找到root来更新这个连续数列的个数。

## 200. Number of Islands 03 UNION FIND

我们只关注岛屿，用棋盘去初始化UF,然后再外部，走到1的地方就去判断下方和右方是否需要去merge

O(M*N)

O(M*N)


## 803. Bricks Falling When Hit 01 

## 547. Number of Provinces 01 UnionFind

## 684. Redundant Connection 01
