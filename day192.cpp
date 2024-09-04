// walking robot simulation 

class Solution {
public:
    // direction : {direction on turning left, direction on turning right}
    unordered_map<char,pair<char,char>> directions {
        {'N',{'W','E'}},
        {'E',{'N','S'}},
        {'S',{'E','W'}},
        {'W',{'S','N'}}
    };

    // direction : {change in x, change in y}
    unordered_map<char,vector<int>> nextStep {
        {'N',{0,1}},
        {'W',{-1,0}},
        {'S',{0,-1}},
        {'E',{1,0}}
    };

    char getNewDirection(int x, char direction) {
        return (x == -2) ? directions[direction].first: directions[direction].second;
    }

    vector<int> getNextCoordinate(int x, int y, char direction) {
        return {x+nextStep[direction][0], y+nextStep[direction][1]};
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i = 0, j = 0, c = 0, ans = 0;
        char direction = 'N';
        set<pair<int,int>> s;

        // store obstacles in a set for a faster lookup later
        for(auto obstacle: obstacles)
            s.insert(make_pair(obstacle[0], obstacle[1]));

        while(c < commands.size()) {
            // get the new direction if there is turn
            if(commands[c] < 0) {
                direction = getNewDirection(commands[c], direction);
                c++;
                continue;
            }

            int steps = commands[c];

            // go one step at a time until you complete the steps or hit an obstacle
            while(steps > 0) {
                vector<int> nextCoordinate = getNextCoordinate(i, j, direction);
                int nexti = nextCoordinate[0], nextj = nextCoordinate[1];
                if(s.find(make_pair(nexti, nextj)) != s.end())
                    break;
                i = nexti, j = nextj;
                ans = max(ans, (i*i) + (j*j));
                steps--;
            }

            c++;
        }

        return ans;
    }
};
