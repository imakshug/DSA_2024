// Maximum Score From Removing Substrings

template<typename T>
void printVector(vector<T>& V)
{
    cout << "[ "; 
    for(auto& elem: V)
        cout << elem << " "; 
    cout << "]" << endl; 
}

class Solution 
{
    vector<char> St;
    int ans{};

public:
    int helper(string s, string tmp, int val)
    {
        char p1 = tmp[0], p2 = tmp[1];
        for(auto c: s)
        {
            if(St.size() > 0 and c == tmp[1] and St.back() == tmp[0])
            {
                St.pop_back(); 
                ans += val; 
            }
            else
            {
              St.push_back(c);           
            }
        }        
        return ans; 
    }
    int maximumGain(string s, int x, int y) 
    {
        int n = static_cast<int>(s.size());
        if(x >= y)
        {
            int result = helper(s, "ab", x); 
            string s2{}; 
            for(auto c: St)
                s2 += c;
            St.clear(); 
            int result2 = helper(s2, "ba", y); 
        } 
        else
        {
            int result = helper(s, "ba", y); 
            string s2{}; 
            for(auto c: St)
                s2 += c;
            St.clear(); 
            int result2 = helper(s2, "ab", x); 
        }   
        return ans; 
    }
};
