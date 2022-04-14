class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words;
        for (string word : wordDict)
        {
            words.insert(word);
        }
        vector<unsigned int> dp(s.length(), 0);
        for (unsigned int end = 0; end < s.length(); end++)
        {
            for (unsigned int start = 0; start <= end; start++)
            {
                string sub = s.substr(start, end - start + 1);
                // cout<<start<<" "<<end <<" "<<sub<<endl;
                if (words.count(sub))
                {
                    // cout<<sub<<endl;
                    if (start == 0)
                    {
                        dp[end] += 1;
                    }
                    else
                    {
                        dp[end] += (dp[start - 1]);
                    }
                }
            }
        }

        // for(int i : dp) cout<<i<<" ";

        return dp[s.length() - 1];
    }
};