class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(26);
        
        for(int i = 0; i < magazine.size(); i++) a[magazine[i] - 'a']++;
        
        for(int j = 0; j < ransomNote.size(); j++) {
            
            if(a[ransomNote[j] - 'a'] > 0) a[ransomNote[j] - 'a']--;
            else return false;
        }
        return true;
    }
};