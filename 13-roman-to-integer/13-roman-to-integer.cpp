class Solution {
public:
    int romanToInt(string s) {
        int newValue = 0;
        int oldValue = 0;
        int result = 0;
        for (size_t i = 0; i < s.size(); i++){
            switch (s[i]){
                case 'I':
                    newValue = 1;
                    break;
                case 'V':
                    newValue = 5;
                    break;
                case 'X':
                    newValue = 10;
                    break;
                case 'L':
                    newValue = 50;
                    break;
                case 'C':
                    newValue = 100;
                    break;
                case 'D':
                    newValue = 500;
                    break;
                case 'M':
                    newValue = 1000;
                    break;
            }
            if (newValue > oldValue)
                result += newValue - 2 * oldValue;
            else
                result += newValue;
            
            oldValue = newValue;
        }
        return result;
    }
};