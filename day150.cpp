// 2191. Sort the Jumbled Numbers

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mapNums(nums.size());
        int sum = 0;
        //Change the number
        for(int i = 0; i < nums.size(); i++){
            int j = 0;
            int numb = nums[i];
            if(numb == 0){
                numb = mapping[0];
                mapNums[i] = {numb,i};
                continue;
            }
            while(numb > 0){
                int n = numb % 10;
                int num = mapping[n];
                sum = sum + num*pow(10,j);
                numb /= 10;
                j++;
            }
            mapNums[i] = {sum,i};
            cout << mapNums[i].first << endl;
            sum = 0;
        }

        sort(mapNums.begin(), mapNums.end());

        vector<int>result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            result[i] =  nums[mapNums[i].second];
        }
        
    return result;
    }
};
