// Find Common Characters

#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common_letters(26, INT_MAX); // To store the minimum frequency of each letter across all words
        vector<int> current_letters(26, 0); // To store the frequency of each letter in the current word

        // Iterate through each word in the list
        for (const auto& word : words) {
            fill(current_letters.begin(), current_letters.end(), 0); // Reset current letters count for the new word

            // Count the frequency of each letter in the current word
            for (const auto& letter : word) {
                current_letters[letter - 'a']++;
            }

            // Update the common letters frequency to the minimum frequency found so far
            for (int i = 0; i < 26; ++i) {
                common_letters[i] = min(common_letters[i], current_letters[i]);
            }
        }

        vector<string> result;

        // Collect the common characters based on the minimum frequency across all words
        for (int i = 0; i < 26; ++i) {
            while (common_letters[i] > 0) {
                result.push_back(string(1, i + 'a'));
                common_letters[i]--;
            }
        }

        return result;
    }
};
