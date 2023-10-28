class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pxor = arr;
        pxor.insert(pxor.begin(), 0);
        vector<int> ans;
            for (int i = 0; i < pxor.size() - 1; i++){
                pxor[i + 1] = pxor[i] ^ pxor[i + 1];
            }
            for(vector<int> &q: queries){
                ans.push_back(pxor[q[0]] ^ pxor[q[1] + 1]);
            }
        return ans;
    }
};