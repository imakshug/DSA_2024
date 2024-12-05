//2337. Move Pieces to Obtain a String

class Solution {
public:
    bool canChange(string start, string target) {
    // Step 1: Check if `start` and `target` are structurally compatible
    string filteredStart, filteredTarget;
    for (char ch : start) {
        if (ch != '_') filteredStart += ch;
    }
    for (char ch : target) {
        if (ch != '_') filteredTarget += ch;
    }
    if (filteredStart != filteredTarget) return false;

    // Step 2: Two-pointer logic to validate movements
    int i = 0, j = 0; // Pointers for start and target
    while (i < start.size() && j < target.size()) {
        // Skip `_` in both strings
        while (i < start.size() && start[i] == '_') i++;
        while (j < target.size() && target[j] == '_') j++;

        // If both pointers reach the end, the transformation is valid
        if (i == start.size() && j == target.size()) return true;

        // If one pointer reaches the end before the other, it's invalid
        if (i == start.size() || j == target.size()) return false;

        // Ensure the characters match
        if (start[i] != target[j]) return false;

        // Check movement constraints
        if (start[i] == 'R' && i > j) return false; // `R` cannot move left
        if (start[i] == 'L' && i < j) return false; // `L` cannot move right

        // Move to the next character
        i++;
        j++;
    }

    return true;
    }
};
