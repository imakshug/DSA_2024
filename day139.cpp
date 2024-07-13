// robote collisions


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> vect;
        stack<int> st;
        vector<int> ans;

        // Collect positions and indices
        for (int i = 0; i < n; i++) {
            vect.push_back({positions[i], i});
        }

        // Sort based on positions
        sort(vect.begin(), vect.end());

        // Process each robot based on sorted positions
        for (int i = 0; i < n; i++) {
            int idx = vect[i][1];

            // Check for collision conditions
            if (!st.empty() && directions[idx] == 'L' && directions[st.top()] == 'R') {
                int topIdx = st.top();

                // If both robots have the same health, both are destroyed
                if (healths[idx] == healths[topIdx]) {
                    healths[st.top()] = 0;
                    healths[idx] = 0;
                    st.pop();
                } 
                // If current robot has less health, it is destroyed, and the health of the robot in the stack is decremented
                else if (healths[idx] < healths[topIdx]) {
                    healths[topIdx]--;
                    healths[idx] = 0;
                } 
                // If current robot has more health, decrement its health, destroy the robot in the stack, and reprocess the current robot
                else {
                    healths[topIdx] = 0;
                    healths[idx]--;
                    st.pop();
                    i--; // Reprocess the current robot since it still needs to be checked for further collisions
                }
            } 
            // If no collision, push the current robot to the stack
            else {
                st.push(idx);
            }
        }

        // Collect health of surviving robots
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
