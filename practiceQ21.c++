#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    vector<vector<int>> type = {
        {},                 
        {0,1},              
        {2,3},              
        {1,2},              
        {0,2},              
        {1,3},             
        {0,3}               
    };
    
    bool isValid(int dir, int nextType) {
        
        if (dir == 0 && (nextType == 1 || nextType == 3 || nextType == 5)) return true; 
        if (dir == 1 && (nextType == 1 || nextType == 4 || nextType == 6)) return true; 
        if (dir == 2 && (nextType == 2 || nextType == 5 || nextType == 6)) return true; 
        if (dir == 3 && (nextType == 2 || nextType == 3 || nextType == 4)) return true; 
        
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        
        q.push({0,0});
        vis[0][0] = 1;
        
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            if (x == m-1 && y == n-1) return true;
            
            int t = grid[x][y];
            
            for (int d : type[t]) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (vis[nx][ny]) continue;
                
                if (isValid(d, grid[nx][ny])) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return false;
    }
};