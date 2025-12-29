class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size()-1;
        int n=obstacleGrid[0].size()-1;

        if(m==0 && n==0)return obstacleGrid[0][0]==1?0:1;//if its start: 0 means 1 and 1 obstacle is 0.

        if(obstacleGrid[m][n]==1 || obstacleGrid[0][0]==1 )return 0;//if start and end is an obstacle

        vector<vector<long long>>arr(m+1,vector<long long>(n+1,0));

        for(int i=n;i>=0;i--)//fill bottom row
        {
            if(obstacleGrid[m][i]==1)break;
            arr[m][i]=1;
        }

        for(int i=m;i>=0;i--)//fill rightmost column
        {
            if(obstacleGrid[i][n]==1)break;
            arr[i][n]=1;
        }

        for(int i=m-1;i>=0;i--)//fill each block's no. of ways
        {
            for(int j=n-1;j>=0;j--)
            {
                if(obstacleGrid[i][j]==1)continue;
                arr[i][j]=arr[i+1][j] + arr[i][j+1];
            }
        }

        return arr[0][0];
    }
};
