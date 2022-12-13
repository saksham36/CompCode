class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>pattern_freq(26,0);
        vector<int>text_freq(26,0);
        string pattern = "balloon";
        for(int i = 0; i< pattern.length(); i++){
            pattern_freq[pattern[i]-'a']++;
        }
        for(int i = 0; i< text.length(); i++){
            text_freq[text[i]-'a']++;
        }
        int answer = INT_MAX;;
        for(int i=0; i<26;i++){
            if(pattern_freq[i])
                answer = min(answer, text_freq[i]/pattern_freq[i]);
        }
        return answer;
    }
};