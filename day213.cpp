// 2416. Sum of Prefix Scores of Strings

class Node{
public:
    Node* links[26];
    int count;

    Node(){
        count = 0;
        for(int iter = 0; iter < 26; iter++){
            links[iter] = NULL;
        }
    }

    bool containsKey(char character){
        return links[character - 'a'] != NULL;
    }

    void put(char character){
        links[character - 'a'] = new Node();
    }

    Node* get(char character){
        return links[character - 'a'];
    }

    void incrementCount(){
        this->count = this->count + 1;
    }

    int getCount(){
        return this->count;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
       root = new Node();
    }

    void insert(string word){
        Node* node = root;

        for(int iter = 0; iter < word.length(); iter++){
            if(!node->containsKey(word[iter])){
                node->put(word[iter]);
            }
            node = node->get(word[iter]);
            node->incrementCount();
        }
    }

    int getScore(string word){
        int score = 0;
        Node* node = root;

        for(int iter = 0; iter < word.length(); iter++){
            if(node->containsKey(word[iter])){
                node = node->get(word[iter]);
                score += node->getCount();
            }else{
                break;
            }
        }

        return score;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *trie = new Trie();

        int len = words.size();

        // Add all the strings in to the trie.
        for(int iter = 0; iter < len; iter++){
            string word = words[iter];

            trie->insert(word);
        }

        vector<int>scores(len, 0);

        // get the score from the trie
        for(int iter = 0; iter < len; iter++){
            string word = words[iter];
            cout<<trie->getScore(word)<<endl;
            scores[iter] = trie->getScore(word);
        }

        return scores;
    }
};
