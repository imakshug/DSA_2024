//3043. Find the Length of the Longest Common Prefix

class Solution {
public:
    class Node {
        public:
        char c;
        unordered_map<char, Node*>next;
        bool f1, f2;
        Node(char x, bool is1) {
            c = x;
            f1 = false;
            f2 = false;
            if(is1) {
                f1=true;
            } else {
                f2= true;
            }
        }
        Node() {
            c = '$';
            f1 = true;
            f2 = true;
        }
    };
    class Trie {
        public:
        Node* head;
        Trie() {
            head = new Node();
        }
        void insert(string s, bool is1) {
            Node* p = head;
            for(int i=0;i<s.length();i++) {
                if(p -> next[s[i]] == nullptr) {
                    p -> next[s[i]] = new Node(s[i], is1);
                }
                p = p -> next[s[i]];
                if(is1) p -> f1 = true;
                if(!is1) p -> f2 = true;
            }
        }
        int dfs(Node* p) {
            if(p == nullptr) return 0;
            int ans = -1;
            if((p -> f1) && (p -> f2)) {
                // ans++;
            } else {
                return 0;
            }
            for(const auto &x:p -> next) {
                ans = max(ans, dfs(x.second));
            }
            int x = 1;
            if(p -> c == '$') x = 0;
            if(ans == -1) return x;
            return ans + x;
        }
    };
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t = new Trie();
        for(const auto &x:arr1) 
        {
            t -> insert(to_string(x), true);
        }
        for(const auto &x:arr2) 
        {
            t -> insert(to_string(x), false);
        }
        return t -> dfs(t -> head) ;
    }
};



