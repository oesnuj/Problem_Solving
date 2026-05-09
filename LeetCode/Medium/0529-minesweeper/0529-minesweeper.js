/**
 * @param {character[][]} board
 * @param {number[]} click
 * @return {character[][]}
 */
function updateBoard(board, click) {
    const [sr, sc] = click;

    if (board[sr][sc] === 'M') board[sr][sc] = 'X';
    else if (board[sr][sc] === 'E') reveal(board, sr, sc);

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

function reveal(board, sr, sc) {
    const queue = [[sr, sc]];
    let head = 0;

    while (head < queue.length) {
        const [r, c] = queue[head++];

        if (board[r][c] !== 'E') continue;

        let mineCount = 0;
        const candidates = [];

        for (const [dr, dc] of dirs) {
            const nr = r + dr;
            const nc = c + dc;
            if (!inRange(board, nr, nc)) continue;

            if (board[nr][nc] === 'M') 
                mineCount++;
            else if (board[nr][nc] === 'E') 
                candidates.push([nr, nc]);
        }

        if (mineCount > 0) {
            board[r][c] = String(mineCount);
            continue;
        }

        board[r][c] = 'B';

        for (const [nr, nc] of candidates) {
            queue.push([nr, nc]);
        }
    }
}