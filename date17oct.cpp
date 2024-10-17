//670. Maximum Swap

class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string ans=s;
        int n=s.size();
        for(int i=0;i<n;i++){ // try all combinations of i and j and swap
            for(int j=i+1;j<n;j++){
                string tmp=s;
                swap(tmp[i],tmp[j]);
                if(tmp>ans)
                    ans=tmp;
            }
        }
        return stoi(ans);
    }
};
