/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
*/

class Solution{
    public:
    vector<string> result;
    void solve(vector<vector<int>> m, int r, int c, int n, string path){
        
        if(r<0||c<0||r>=n||c>=n)
            return;
            
        if(m[r][c]==0)
            return;
            
        if(r==n-1&&c==n-1){
            result.push_back(path);
            return;
        }
        
        m[r][c]=0;
        solve(m, r+1,c, n, path+'D');
        solve(m, r-1,c, n, path+'U');
        solve(m, r,c-1, n, path+'L');
        solve(m, r,c+1, n, path+'R');
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string path = "";
        solve(m, 0, 0, n, path);
        return result;
    }
};