class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> s;
        string x;
        function<void(int)> check = [&](int i) {
            if (i == tiles.size()) {
                if (!x.empty()) s.insert(x);
                return;
            }
            x += tiles[i];
            check(i + 1);
            x.pop_back();
            check(i + 1);
        };

        sort(tiles.begin(), tiles.end());

        do {
            x.clear();
            check(0);
        } while (next_permutation(tiles.begin(), tiles. end()));

        return s.size();
    }
};