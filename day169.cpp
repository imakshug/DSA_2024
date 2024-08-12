//703. Kth Largest Element in a Stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int num;
    
    KthLargest(int k, vector<int>& nums) {
        num = k;
        for(int x : nums)
        {
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > num)
            pq.pop();
        return pq.top();
    }
};
