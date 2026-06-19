class Solution {
public:
    int maxProduct(string s) {
        int best = 0;
        string groupA, groupB;
        backtrack(s, 0, groupA, groupB, best);
        return best;
    }

private:
    void backtrack(string& s, int i, string& groupA, string& groupB, int& best) {
        if (i == s.size()) {
            if (isPalindrome(groupA) && isPalindrome(groupB)) {
                best = max(best, (int)(groupA.size() * groupB.size()));
            }
            return;
        }

        groupA.push_back(s[i]);
        backtrack(s, i + 1, groupA, groupB, best);
        groupA.pop_back();

        groupB.push_back(s[i]);
        backtrack(s, i + 1, groupA, groupB, best);
        groupB.pop_back();

        backtrack(s, i + 1, groupA, groupB, best);
    }

    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};