//2491. Divide Players Into Teams of Equal Skill

class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long x=arr.front()+arr.back(),ans=0;
        int i=0,j=arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]!=x) return -1;
            else ans+=arr[i]*arr[j];
            i++;
            j--;
        }
        return ans;
    }
};
