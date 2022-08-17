class Solution {
private:
    string solve(string s, string m[]){
        string temp = "";
        for(int i=0;i<s.length();i++){
            temp += m[s[i]-'a'];
        }
        
        return temp;
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        string m[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto it: words){
            s.insert(solve(it, m));
        }
        
        return s.size();
    }
};