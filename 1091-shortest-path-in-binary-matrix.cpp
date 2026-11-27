class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> disS(n , vector<int>(n , 1e9)) , disD(n , vector<int>(n, 1e9));

        queue<pair<int,int>> qS, qD;

        qS.push({0,0});
        disS[0][0] = 1;

        vector<vector<int>> dir = {
            {-1,-1} , {-1,0} , {-1, 1},
            {0, -1} ,   {0, 1},
            {1 ,-1} , {1, 0} , {1 , 1}
        };

        qD.push({n-1, n- 1});
        disD[n-1][n-1] = 1;

        while(!qS.empty() && !qD.empty()){
            bool preferSource = qS.size() <= qD.size();

            queue<pair<int,int>>& q = preferSource ? qS : qD;
            vector<vector<int>> &dis = preferSource ? disS: disD; 
            vector<vector<int>> &other = preferSource ? disD: disS;
            int sz = q.size();

            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(other[x][y] != 1e9){
                    return dis[x][y] + other[x][y] - 1;
                }

                for(auto &d: dir){
                    int dx = x + d[0];
                    int dy = y + d[1];

                    if(dx >= 0 && dx < n && dy >= 0 && dy < n && grid[dx][dy] == 0){
                        if(dis[dx][dy] == 1e9){
                            dis[dx][dy] = dis[x][y] + 1;
                            q.push({dx , dy});
                        }

                        if(other[dx][dy] != 1e9){
                            return other[dx][dy] + dis[dx][dy] - 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};