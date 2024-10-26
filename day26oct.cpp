//2458. Height of Binary Tree After Subtree Removal Queries

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,bool> dir;
        for(int i=0;i<folder.size();i++)
        {
            dir[folder[i]];
        }
        vector<string> ans;
        for(int i=0;i<folder.size();i++)
        {
            bool yes=false;
            string s="";
            for(int j=0;j<folder[i].size();j++)
            {
                if(folder[i][j]=='/' && !s.empty())
                {
                    if(dir.count(s)) 
                    {
                        yes=true;
                        break;
                    }
                }
                s+=folder[i][j];
            }
            if(yes==false)
                ans.push_back(s);
        }
        return ans;
    }
};
