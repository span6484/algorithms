## 622. Design Circular Queue 01

此题注意几点，为什么我们不用head 和 tail 而非要用 tail和size去推算head呢，这是因为会出现enqueue之后我们只动tail而无head的情况，然后我们去front就会出错，这样需要更多判断。如果只用tail的话我们则不需要太多去考虑维护的。

(tail_ - size_ + k_ + 1) % k_ 加个k_就不存在负数的情况了，很巧妙

