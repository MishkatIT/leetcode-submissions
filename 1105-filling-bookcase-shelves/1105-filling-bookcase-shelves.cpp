class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        sort(books.begin(), books.end(), [&](auto& a, auto& b) {
            return (a[1] > b[1] || (a[1] == b[1] && a[0] < b[0]));
        });
        int ans = 0;
        int n = books.size();
        for (int i = 0; i < n; ) {
            ans += books[i][1];
            int w = 0;
            while (i < n && w + books[i][0] <= shelfWidth) {
                w += books[i][0];
                i++;
            }
        }
        return ans;
    }
};