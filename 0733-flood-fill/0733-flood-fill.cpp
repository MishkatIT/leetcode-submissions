class Solution {
public:
    bool valid (vector<vector<int>>& image, int x, int y, int oc) {
        if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == oc) return true;
        return false;
    }

    void dfs(vector<vector<int>>& image,int dy[], int dx[], int sr, int sc, int oc, int nc) { // old color, new color
        if (!valid(image, sr, sc, oc) || image[sr][sc] == nc) return;
        image[sr][sc] = nc;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + sr;
            int ny = dy[i] + sc;
            dfs(image,dy, dx, nx, ny, oc, nc);
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dy[] = {1, -1, 0, 0};
        int dx[] = {0, 0, 1, -1};
        dfs(image, dy, dx, sr, sc, image[sr][sc], color);
        return image;
    }
};