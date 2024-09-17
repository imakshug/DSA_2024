//884. Uncommon Words from Two Sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> wordList;
        stringstream ss1(s1), ss2(s2);
        string word;  
        while (ss1 >> word) 
            wordList[word]++;

        while (ss2 >> word) 
            wordList[word]++;

        unordered_map<string, int>:: iterator p; 
        for (p = wordList.begin(); p != wordList.end(); p++)
        {
            if (p->second == 1)
                ans.push_back(p->first);
        }

        return ans;
    }
};
