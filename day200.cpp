//1684. Count the Number of Consistent Strings

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        for(auto it:allowed){
            mp[it]++;
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            bool flag=true;
            for(int j=0;j<words[i].size();j++){
                if(mp.find(words[i][j])==mp.end()){
                    flag=false;
                }
            }
            if(flag==true){
                cnt++;
            }

        }
        return cnt;
    }
};
