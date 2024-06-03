#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct AdjacentSeats {
    int emptySeats; // 인접한 빈자리 수
    int likedSeats; // 좋아하는 사람이 있는 인접한 자리 수
};

struct Point {
    int r; // 행
    int c; // 열
};

struct Seat {
    AdjacentSeats info;
    Point p;
};

void choiceSeat(int n, int studentNum);
void getAdjacentSeats(int studentNum, int n, const vector<int>& prefer);
AdjacentSeats checkAdjacent(int r, int c, int n, const vector<int>& prefer);
int calculateSatisfaction(int n); // 학생의 만족도를 계산하는 함수

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[20][20] = { 0 };
vector<Seat> v;
map<int, vector<int>> preferMap;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

     // 각 학생이 좋아하는 사람의 정보를 저장하는 map
    for (int i = 0; i < n * n; i++) {
        int studentNum;
        cin >> studentNum;
        vector<int> prefer(4);
        for (auto& k : prefer) {
            cin >> k;
        }
        preferMap[studentNum] = prefer; // 해당 학생이 좋아하는 사람들의 목록 저장
        if (i == 0) {
            board[1][1] = studentNum;
            continue;
        }
        getAdjacentSeats(studentNum, n, preferMap[studentNum]);
    }

    // 총 만족도 계산
    int totalSatisfaction = calculateSatisfaction(n);
    cout << totalSatisfaction;

    return 0;
}

void getAdjacentSeats(int studentNum, int n, const vector<int>& prefer) {
    v.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0) // 이미 앉은 자리는 패스
                continue;
            AdjacentSeats info = checkAdjacent(i, j, n, prefer);
            Point currentPoint = { i, j };
            v.push_back({ info, currentPoint });
        }
    }
    choiceSeat(n, studentNum);
}

void choiceSeat(int n, int studentNum) {
    sort(v.begin(), v.end(), [](const Seat& a, const Seat& b) {
        if (a.info.likedSeats != b.info.likedSeats)
            return a.info.likedSeats > b.info.likedSeats;
        if (a.info.emptySeats != b.info.emptySeats)
            return a.info.emptySeats > b.info.emptySeats;
        if (a.p.r != b.p.r)
            return a.p.r < b.p.r;
        return a.p.c < b.p.c;
        });

    Point chosenSeat = v[0].p;
    board[chosenSeat.r][chosenSeat.c] = studentNum;
}

AdjacentSeats checkAdjacent(int r, int c, int n, const vector<int>& prefer) {
    AdjacentSeats seatInfo = { 0, 0 };
    for (int i = 0; i < 4; i++) {
        int dr = r + dx[i];
        int dc = c + dy[i];
        if (dr < 0 || dr >= n || dc < 0 || dc >= n) // 범위를 벗어나면 continue
            continue;
        if (board[dr][dc] == 0) // 빈자리라면
            seatInfo.emptySeats++;
        else if (find(prefer.begin(), prefer.end(), board[dr][dc]) != prefer.end())
            seatInfo.likedSeats++;
    }
    return seatInfo;
}

int calculateSatisfaction(int n) {
    int totalSatisfaction = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) // 빈자리인 경우
                continue;
            int currentStudent = board[i][j];
            AdjacentSeats info = checkAdjacent(i, j, n, preferMap[currentStudent]);
            // 만족도 계산: 좋아하는 사람이 있는 인접한 자리 수에 따라 만족도 부여
            if (info.likedSeats == 0)
                totalSatisfaction += 0;
            else
                totalSatisfaction += pow(10, info.likedSeats - 1);
        }
    }
    return totalSatisfaction;
}
