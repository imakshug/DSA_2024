// 2707. Extra Characters in a String

class Solution {
public:
    unordered_map<string,int> mp;
   int f(int idx,string& s,vector<int>& dp)
   {
    if(idx>=s.size()) return 0; //Base Case
    int ans=INT_MAX;
    if(dp[idx]!=-1) return dp[idx];
    for(int i=idx;i<s.size();i++) //trying all substrings possible
    {
        string temp=s.substr(idx,i-idx+1);
        if(mp.find(temp)==mp.end())
        ans=min(ans,(i-idx+1)+f(i+1,s,dp));
        else
        ans=min(ans,f(i+1,s,dp));
        //trying to find out which substring would give me the most optimum answer
    }
    return dp[idx]=ans; //memoizing the result
   }
    int minExtraChar(string s, vector<string>& dictionary) {
    
        for(auto word:dictionary)
        mp[word]++; //storing the words in a hash table
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp);
    }
};
