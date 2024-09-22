// 440. K-th Smallest in Lexicographical Order

class Solution 
{
    int numOfChildren(long long int i, int n)
    {
        int childs = 0;
        long long int lower = i * 10;
        long long int upper = i * 10 + 9;
        while (lower <= n)
        {
            childs += min((long long int)n, upper) - lower + 1;
            lower *= 10;
            upper = upper * 10 + 9;
        }
        return childs;
    }
    void dfs(long long int i, int n, int& l, int& elem)
    {
        if(i>n)
            return;
        if(l==0)
        {
            elem = i;
            return;
        }
        for(int j = 0; j <= 9; j++)
        {
            long long int k = i*10 + j;
            if(k<=n)
            {
                int c = numOfChildren(k,n) + 1;
                if(l - c > 0)
                {
                    l -= c;
                    continue;
                }
                else
                {
                    l--;
                    dfs(k,n,l,elem);
                    break;
                }
            }
            else
                break;
        }
    }
public:
    int findKthNumber(int n, int k)
    {
        int elem, childs = 0;
        for(int i = 1; i <= 9; i++)
        {
            int c = numOfChildren(i,n) + 1;
            if(c + childs < k)
            {
                childs += c;
                continue;
            } 
            else
            {
                k = k - childs - 1;
                dfs(i,n,k,elem);
                break;
            }
        }
        return elem;
    }
};
