class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int val = 0;
        for (auto& it : boxTypes) {
            int take = min(it[0], truckSize);
            val += take * it[1];
            truckSize -= take;
            if (truckSize == 0) break;
        }

        return val;
    }
};