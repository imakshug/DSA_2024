//1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence


class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        vector<string> words;
        string word;
        int n = searchWord.size();
        
        // Split the sentence into words
        while(ss >> word){
            words.push_back(word);
        }
        
        int m = words.size();
        
        // Check each word if it starts with the searchWord
        for(int i = 0; i < m; i++) {
            string temp = words[i].substr(0, n);
            if(temp == searchWord) {
                return i + 1;  // Return 1-based index
            }
        }
        
        return -1;  // Return -1 if no match is found
    }
};
