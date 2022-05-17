class Solution {
public:
    
    long long getHash(string s, int start, int len){
        long long hash = 0, mul = len-1;
        for(int i = start ; i<start+len; i++){
            // cout<<s[i]<<" "<<pow(10, mul)<<endl;
            hash = hash + s[i]*pow(10, mul--);
        }
        return hash;
    }
    
    bool rabinKarpMatch(long long hashReq,long long &prevHash, string a, string b, int start){
        // Avoid out of bounds.    
        int m = a.length(), n = b.length();    
        if(start+m>n) return false;
    
        long long currHash; 
        
        // For the time when prevHash is not defined.
        if(start == 0)
            currHash = getHash(b, start, m);
        else
            currHash = (prevHash - (pow(10, m-1)*b[start-1]))*10 +b[start+m-1];
        
        // cout<<start<<" ---- "<<currHash<<"----"<< prevHash<<endl;
         
        // Set the prev hash for future use.
        prevHash = currHash;
        
        if(currHash != hashReq) return false;
        
        // If hash matches match the strings
        int j = 0;
        for(int i = start; i<start+m; i++)
            if(a[j++] != b[i]) return false;
        
        
        return true;
    }
    
    int repeatedStringMatch(string a, string b) {
        int m = a.length(), n = b.length();
        
        long long hashReq = getHash(a, 0, m), prevHash = 0;
        int count = 0, lastStart = 0;
        bool noCommon = true;
        for(int i = 0; i<n; i++){
            if(rabinKarpMatch(hashReq, prevHash, a, b, i)){
                count++;
                lastStart = i;
                noCommon = false;
            }
            // for an extra appearance at the start of string
            // in case it doesnt match
            else if(i==0)
                count++;
        }
        // cout<<count<<" "<<lastStart;
        // return -1 if there is no sub string
        if(noCommon) return -1;
        
        if(lastStart!=(n-m))
            count++;
        
        return count;
    }
};