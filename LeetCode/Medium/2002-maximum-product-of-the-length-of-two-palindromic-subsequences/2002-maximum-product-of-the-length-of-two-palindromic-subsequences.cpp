class Solution {
public:
    int maxProduct(string s) {
        int best = 0;
        backtrack(s, 0, "", "", best);
        return best;
    }
    
private:
    void backtrack(string &s, int i, string groupA, string groupB, int &best) {
        if(i == s.length()){
            if(isPalindrome(groupA) && isPalindrome(groupB)){
                best = max(best, (int)(groupA.size() * groupB.size()));
            }
            return;
        }
        backtrack(s, i + 1, groupA + s[i], groupB, best);
        backtrack(s, i + 1, groupA, groupB + s[i], best);
        backtrack(s, i + 1, groupA, groupB, best);
    }
    
    bool isPalindrome(string &s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};