function updateBoard(board, click) {
    const [sr, sc] = click;

    if (board[sr][sc] === 'M') {
        board[sr][sc] = 'X';
        return board;
    }

    reveal(board, sr, sc);

    return board;
}

const dirs = [
    [-1, -1], [-1, 0], [-1, 1],
    [ 0, -1],          [ 0, 1],
    [ 1, -1], [ 1, 0], [ 1, 1],
];

function inRange(board, r, c) {
    const m = board.length;
    const n = board[0].length;
    return 0 <= r && r < m && 0 <= c && c < n;
}

function countMines(board, r, c) {
    let cnt = 0;

    for (const [dr, dc] of dirs) {
        const nr = r + dr;
        const nc = c + dc;

        if (!inRange(board, nr, nc)) continue;
        if (board[nr][nc] === 'M') cnt++;
    }

    return cnt;
}

function reveal(board, r, c) {
    if (!inRange(board, r, c)) return;
    if (board[r][c] !== 'E') return;

    const cnt = countMines(board, r, c);

    if (cnt > 0) {
        board[r][c] = String(cnt);
        return;
    }

    board[r][c] = 'B';

    for (const [dr, dc] of dirs) {
        reveal(board, r + dr, c + dc);
    }
}