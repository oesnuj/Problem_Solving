function updateBoard(board, click) {
    const [sr, sc] = click;

    const m = board.length;
    const n = board[0].length;

    const dirs = [
        [-1, -1], [-1, 0], [-1, 1],
        [ 0, -1],          [ 0, 1],
        [ 1, -1], [ 1, 0], [ 1, 1],
    ];

    function inRange(r, c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    function dfs(r, c) {
        if (!inRange(r, c) || board[r][c] !== 'E') return;

        let cnt = 0;

        for (const [dr, dc] of dirs) {
            const nr = r + dr;
            const nc = c + dc;

            if (!inRange(nr, nc)) continue;
            if (board[nr][nc] === 'M') cnt++;
        }

        if (cnt > 0) {
            board[r][c] = String(cnt);
            return;
        }

        board[r][c] = 'B';

        for (const [dr, dc] of dirs) {
            dfs(r + dr, c + dc);
        }
    }

    if (board[sr][sc] === 'M') {
        board[sr][sc] = 'X';
    } else {
        dfs(sr, sc);
    }

    return board;
}