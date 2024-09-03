//  945. Sum of Digits of String After Convert

class Solution {
public:
    int getLucky(string s, int k) {
        string p;
        for (char ch : s) {
            int c = (ch - 'a') + 1;
            p += to_string(c);
        }
        cout << p << endl;

        while (k > 0) {
            long long sum = 0;
            for (char i : p) {
                sum += i - '0';
            }
            p = to_string(sum);
            k--;

            // cout<<sum<<endl;
        }
        int number = stoi(p);
         return number;
    }
};
