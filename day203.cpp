// 1371. Find the Longest Substring Containing Vowels in Even Counts

#include <unordered_map>
#include <set>
#include <string>

class Solution {

private:
    std::set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    std::vector<bool> vowel_mapping = std::vector<bool>(5, false);
    std::map<std::vector<bool>, int> prev_location_map{};

    void updateVowelMapping(char c) {
        if(vowels.contains(c)) {
            switch(c) {
                case 'a':
                    vowel_mapping[0] = !vowel_mapping[0];
                    break;
                case 'e':
                    vowel_mapping[1] = !vowel_mapping[1];
                    break;
                case 'i':
                    vowel_mapping[2] = !vowel_mapping[2];
                    break;
                case 'o':
                    vowel_mapping[3] = !vowel_mapping[3];
                    break;
                case 'u':
                    vowel_mapping[4] = !vowel_mapping[4];
                    break;
                default:
                    break;
            }
        }

    }

public:
    int findTheLongestSubstring(string s) {
        int longest_substr = 0;
        prev_location_map[{false, false, false, false, false}] = -1;
        for(int i = 0; i < s.size(); i++) {
            updateVowelMapping(s.at(i));
            if(!prev_location_map.contains(vowel_mapping)) {
                prev_location_map[vowel_mapping] = i;
            }
            longest_substr = std::max(longest_substr, i - prev_location_map[vowel_mapping]);
        }
        return longest_substr;
    }
};
