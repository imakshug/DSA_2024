//1963. Minimum Number of Swaps to Make the String Balanced
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;  // Stack to track open brackets '['
        int imbalance_count = 0;  // Variable to count unbalanced closing brackets ']'

        // Loop through the string
        for(int i = 0; s[i] != '\0'; ++i) {
            if(s[i] == '[')   
                st.push('[');  // Push open brackets '[' onto the stack
            else {
                if(!st.empty()) 
                    st.pop();  // If there's an open bracket in the stack, pop it (i.e., match with ']')
                else            
                    imbalance_count++;  // If stack is empty, there's an unmatched closing bracket, increase imbalance count
            }
        }
        // Return the minimum swaps required to balance the string
        // (imbalance_count + 1) / 2 gives the number of swaps needed to fix half of the imbalanced brackets
        return (imbalance_count + 1) / 2;
    }
};
