class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<short>> m(2, vector<short>(text2.size() + 1));
        for (auto i = 1; i <= text1.size(); ++i)
            for (auto j = 1; j <= text2.size(); ++j)
                if (text1[i - 1] == text2[j - 1]) m[i % 2][j] = m[(i -1) % 2][j - 1] + 1;
                else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);
        return m[text1.size() % 2][text2.size()];
    }
};