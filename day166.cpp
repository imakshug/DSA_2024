// magic squares in grid

class Solution {
public:

    bool isSquareMagic(vector<vector<int>>& grid, int i , int j)
    {
        int row = grid.size()-1;
        int col = grid[0].size()-1;

        if(i+2 > row && j+2 > col)
        {
            return false;
        }

        int arr[10] = {0};
        // Fist checking if the 3*3 sqaure has numbers between 1 to 9
        for(int rowi = i; rowi <= i+2; rowi++)
        {
            for(int coli = j ; coli <= j+2; coli++)
            {
                if(grid[rowi][coli] >9 || grid[rowi][coli] == 0)
                 return false;
                
                if(grid[rowi][coli] <=9)
                {
                   if(arr[grid[rowi][coli]] != 0)
                     return false;
                    else 
                    arr[grid[rowi][coli]] = 1;
                }
            
            }
        }
         
         int requiredSum = 0;
         requiredSum += grid[i][j] + grid[i+1][j] + grid[i+2][j];
        //row sums
        for(int rowi = i; rowi<=i+2;  rowi++)
        {
            int sum = 0;
            for(int coli = j; coli <= j+2; coli++)
            {
                sum += grid[rowi][coli];
            }

            if(sum != requiredSum)
              return false;
        }
        
         // col sums
         for(int coli = j; coli<=j+2;  coli++)
        {
            int sum = 0;
            for(int rowi = i; rowi <= i+2; rowi++)
            {
                sum += grid[rowi][coli];
            }

            if(sum != requiredSum)
              return false;
        }
     
        int sum = 0;
        //diagonal sum
        sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        if(sum != requiredSum)
            return false;

        sum = 0;
        //diagonal2 sum
        sum = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
        if(sum != requiredSum)
          return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      

      int r = grid.size();
      int c = grid[0].size();

      int ans = 0;

      for(int i = 0; i <= r-3; i++)
      {
        for(int j = 0; j <= c-3; j++)
        {
            if(isSquareMagic(grid,i,j))
             ans++;
        }
      }

        return ans;
    }
};
