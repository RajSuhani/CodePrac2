#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++) {
            int empty = n - 1;
            
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j - 1;
                }
                else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        vector<vector<char>> result(n, vector<char>(m));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        return result;
    }
};

int main() {
    int m, n;
    
    cout << "Enter rows (m) and columns (n): ";
    cin >> m >> n;
    
    vector<vector<char>> boxGrid(m, vector<char>(n));
    
    cout << "Enter grid (use #, *, .):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> boxGrid[i][j];
        }
    }
    
    Solution obj;
    vector<vector<char>> result = obj.rotateTheBox(boxGrid);
    
    cout << "\nRotated Box:\n";
    for (auto &row : result) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
    
    return 0;
}