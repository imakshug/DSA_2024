//  Sort an Array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }
private:
    void heapify(std::vector<int>& v, int size, int i){
        int left = 2*i+1, right = 2*i+2, largest=i;

        if(left<size&&v[left]>v[largest])
            largest = left;
        if(right<size&&v[right]>v[largest])
            largest = right;

        if(largest==i) return;

        std::swap(v[largest], v[i]);
        heapify(v, size, largest);
    }
    void heapsort(std::vector<int>& v){
        int size = static_cast<int>(v.size());
        for(int i = size; i>=0; --i)
            heapify(v, size, i);
        for(int i = size-1; i>=0; --i){
            std::swap(v[i], v[0]);
            heapify(v, i, 0);
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
