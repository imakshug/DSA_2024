//1460. Make Two Arrays Equal by Reversing Subarrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()==1 && arr.size()==1)
        {
            if(arr[0]==target[0])
            return true;
        }
        if(arr.size()!=target.size())
        return false;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        for(int i=0;i<target.size();i++)
        {
            if(arr[i]!=target[i])
            return false;
        }


        return  true;
    }
};
