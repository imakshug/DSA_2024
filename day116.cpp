// Magnetic Force Between Two Balls

#pragma GCC optimize("03")
static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxDistance(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int l=1,h=v.back()-v[0];
        while(l<h)
        {
            int m=(l+h)/2 + ((l+h)%2!=0?1:0);
            int c=1,prev=v[0];
            for(auto i:v)
            {
                if(i-prev>=m)
                {
                    c++;
                    prev=i;
                }
            }
            if(c>=k) l=m;
            else h=m-1;
        }
        return l;
    }
};
