#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void fun(string &s, 
             unordered_set<string> &words,
             int startInd,
             vector<string> &ans, 
             string curr){
        if(startInd==s.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int endInd = startInd; endInd<s.length(); endInd++){
            string sub = s.substr(startInd, endInd-startInd+1);
            if(words.count(sub)){
                if(endInd==s.length()-1){
                    fun(s,words,endInd+1, ans, curr+sub);
                    continue;
                }
                fun(s,words,endInd+1, ans, curr+sub+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string word : wordDict)
            words.insert(word);
        for(auto word: words)cout<<words.count(word)<<" ";
        vector<string> ans = {};
        fun(s,words,0, ans, "");
        return ans;
    }
    
};