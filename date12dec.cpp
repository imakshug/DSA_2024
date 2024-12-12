//2558. Take Gifts From the Richest Pile

class Solution {
public:
    long long int pickGifts(
        std::vector<int> & gifts,
        int seconds
    ) const {
        auto heap{std::priority_queue{std::less(), std::move(gifts)}};
        while(seconds-- > 0) {
            heap.push(std::floor(std::sqrt(heap.top())));
            heap.pop();
        }
        auto sum{0LL};
        while(!heap.empty()) {
            sum += heap.top();
            heap.pop();
        }
        return sum;
    }
};
