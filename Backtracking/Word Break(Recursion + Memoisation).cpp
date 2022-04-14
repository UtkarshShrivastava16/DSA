class Solution
{
public:
    bool fun(unordered_set<string> &words, string s, unordered_map<int, bool> &mem, int i)
    {
        if (s.length() == 0)
            return true;
        if (mem.count(i))
            return mem[i];
        for (int len = 1; len <= s.length(); len++)
        {
            mem[i] = words.count(s.substr(0, len));
            if (mem[i] && fun(words, s.substr(len), mem, i + len))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words;
        for (string word : wordDict)
        {
            words.insert(word);
        }
        unordered_map<int, bool> mem;
        return fun(words, s, mem, 0);
    }
};