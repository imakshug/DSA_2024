// sort array by increasing order

class mycomparison{
public:
    mycomparison(){}
    bool operator() (const pair<int,int>& lhs, const pair<int,int> &rhs) const{
        if(lhs.first == rhs.first) return lhs.second < rhs.second;
        return lhs.first > rhs.first;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        priority_queue<pair<int,int> , vector<pair<int,int>>, mycomparison > pq;
        for(int i=0; i<nums.size(); ){
            int counting = 0 , value = nums[i];
            while(i<nums.size() and nums[i] == value) i++, counting++;
            pq.push({counting , value});
        }
        vector<int> result;
        while(pq.size()){
            auto it = pq.top();
            pq.pop();
            for(int i=0; i<it.first; i++) result.push_back(it.second);
        }
        return result;
    }
};
