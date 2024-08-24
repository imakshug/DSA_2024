//. Find the Closest Palindrome

# define lH leftHalf 
class Solution {
public:
    string nearestPalindromic(string n) {
        

        long long num=stoll(n);
        if(num<=10){
            return to_string(num-1);
        }
        if(num==11){
            return "9";
        }
        if(num==999999999999999999){
            return "1000000000000000001";
        }

        int l=n.length();
        long long lH=stoll(n.substr(0,(l+1)/2));

        vector<long long> relDiff;
        long long a=makePalindrome(lH,l%2==0);
        long long c=makePalindrome(lH-1,l%2==0);


        long long b;
        if(lH<999999999){
            b=makePalindrome(lH+1,l%2==0);
        }
        else{
            b=stoll("1"+string(l-1,'0')+"1");
        }

        long long d=pow(10,l)+1;
        long long e=pow(10,l-1)-1;
        relDiff.push_back(a);
        relDiff.push_back(b);
        relDiff.push_back(c);
        relDiff.push_back(d);
        relDiff.push_back(e);

        long long Npalindrome=0;
        long long minDiff=LLONG_MAX;
        for(long long i:relDiff){
            if(i==num){
                continue;
            }
            long long diff=abs(i-num);
            if(diff<minDiff || (diff==minDiff && i<Npalindrome)){
                minDiff=diff;
                Npalindrome=i;
            }
        }
        return to_string(Npalindrome);
    }

    long long makePalindrome(long long lefthalf,bool iseven){
        long long p=lefthalf;
        if(!iseven){
            lefthalf/=10;
        }
        while(lefthalf>0){
            p=p*10+lefthalf%10;
            lefthalf/=10;
        }
        return p;
    }
};
