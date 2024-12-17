//2182. Construct String With Repeat Limit

class Solution {
public:
    int findNearest(vector<int>&freq, int &k){//finds just lesser available character than char('a'+k)
        for(int i=k-1;i>=0;i--)
            if(freq[i]!=0) return i;
        return -1;
    }
    string repeatLimitedString(string s, int repeatLimit) {
        string newS="";
        vector<int> freq(26);
        for(auto ch: s) freq[ch-'a']++;//store the frequency for each character
        for(int i=25;i>=0;i--){//traverse from end
            for(int j=0;j<freq[i];j++){
                if (j>=repeatLimit && j % repeatLimit == 0) {//track repeat limit
                    int idx = findNearest(freq, i);
                    if (idx == -1) return newS;//return the string if no characters could be found to make the string longer
                    newS += ('a' + idx);//add the character char('a'+idx) that is just lesser than current character char('a'+i)
                    freq[idx]--;//decrement the frequency for the smaller character as we made use of it
                }
                newS += ('a' + i);//add each currently visited character
            }
        }
        return newS;
    }
};
