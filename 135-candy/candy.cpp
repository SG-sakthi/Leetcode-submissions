class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // create a array with candies 1
        vector<int> candies(n, 1);
        // left to right travarsal
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        // right to left traversal
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        // calculate total number of candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }
        return total;
    }
};