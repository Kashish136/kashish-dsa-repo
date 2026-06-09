class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
       vector<int>rows = {-1,1,0,0};
       vector<int>cols = {0,0,-1,1};

       int n = grid.size();
       int m = grid[0].size();

       queue<pair<pair<int,int>,int>>q;

       for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 2){
                q.push({0 , {0,0}});
            }
        }
       }

       vector<vector<int>>visited(n , vector<int>(m,0));


       int output = 0;
       while(!q.empty()){
         int time = q.front().first;
         int row = q.front().second.first;
         int col = q.front().second.second;
         q.pop();
         output = max(output , time);

         for(int i = 0 ; i < 4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                grid[nrow][ncol] = 2;
                visited[nrow][ncol] = 1;
                q.push({time+1 ,{nrow , ncol}});
            }
         }
       }

       for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
       }

       return output ;
    }
};
