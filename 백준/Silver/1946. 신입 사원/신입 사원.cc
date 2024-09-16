#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Applicant {
    int docRank;
    int intvRank;

    bool operator<(const Applicant& other) const {
        return docRank < other.docRank;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Applicant> v(n);
        for (auto& i : v) {
            cin >> i.docRank >> i.intvRank;
        }

        sort(v.begin(), v.end());

        int top = v[0].intvRank;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (v[i].intvRank < top) {
                top = v[i].intvRank;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}