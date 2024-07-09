class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long time = 0;
        long long waiting = 0;
        for (auto& i: customers) {
            if (time > i[0]) {
                waiting += time - i[0] + i[1];
                time += i[1];
            } else {
                waiting += i[1];
                time = i[0] + i[1];
            }
        }
        return waiting / ((int)customers.size() * 1.0);
    }
};