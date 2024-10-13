//632. Smallest Range Covering Elements from K Lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using Element = tuple<int,int,int>; // value,list no, element index
        priority_queue<Element,vector<Element>,greater<Element>>pq;

        int currentMax= numeric_limits<int>::lowest();
        int smallestRange = numeric_limits<int>::max();
        vector<int>ans(2);

        // heap with first elemnt of each list
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],i,0}); // val,listNo,eleIdx
            currentMax=max(nums[i][0],currentMax);
        }

        while(!pq.empty()){
            auto[currentMin,listIndex,elementIndex]=pq.top();
            pq.pop();

            if(currentMax-currentMin < smallestRange){
                smallestRange=currentMax-currentMin;
                ans[0]=currentMin;
                ans[1]=currentMax;
            }

            if(elementIndex+1==nums[listIndex].size()){
                break;
            }

            int nextvalue=nums[listIndex][elementIndex+1];
            pq.push({nextvalue,listIndex,elementIndex+1});

            currentMax=max(nextvalue,currentMax);
        }
        return ans;
    }
};
