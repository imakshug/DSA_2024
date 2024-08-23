//592. Fraction Addition and Subtraction

class Solution {
public:
    string fractionAddition(string expression) {
        unordered_map<int, vector<pair<int, int>>> denoToSignNumMp;
        int size = expression.length();
        vector<char> expChrs(expression.begin(), expression.end());
        int indx = 0;
        int sign = 1;

        while (indx < size) {
            char currChar = expChrs[indx];
            if (currChar == '-') {
                sign = -1;
                indx++;
            } else if (currChar == '+') {
                sign = 1;
                indx++;
            }

            int num = 0, deno = 0;
            bool slashFound = false;

            while (indx < size && expChrs[indx] != '+' && expChrs[indx] != '-') {
                if (expChrs[indx] == '/') {
                    slashFound = true;
                    indx++;
                    continue;
                }

                if (!slashFound) {
                    num = num * 10 + (expChrs[indx] - '0');
                } else {
                    deno = deno * 10 + (expChrs[indx] - '0');
                }

                indx++;
            }

            if (deno == 0) deno = 1;
            denoToSignNumMp[deno].emplace_back(num, sign);
        }

        int lcm = 1;
        for (const auto& denoEntry : denoToSignNumMp) {
            lcm = getLcm(lcm, denoEntry.first);
        }

        int totalNum = 0;
        for (const auto& entry : denoToSignNumMp) {
            int deno = entry.first;
            for (const auto& numEntry : entry.second) {
                int num = numEntry.first, numSign = numEntry.second;
                totalNum += (numSign * num * (lcm / deno));
            }
        }
        int gcdValue = gcd(abs(totalNum), lcm);
        totalNum /= gcdValue;
        lcm /= gcdValue;

        if (lcm == 1) return to_string(totalNum) + "/1";
        return to_string(totalNum) + "/" + to_string(lcm);
    }

private:
    int getLcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
