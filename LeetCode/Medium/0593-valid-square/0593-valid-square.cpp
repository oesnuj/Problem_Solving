class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> d = {
            dist2(p1, p2),
            dist2(p1, p3),
            dist2(p1, p4),
            dist2(p2, p3),
            dist2(p2, p4),
            dist2(p3, p4)
        };

        sort(d.begin(), d.end());

        return d[0] > 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5];
    }

    int dist2(vector <int> &a, vector<int>& b){
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
};