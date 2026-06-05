/**
 * @param {number} n
 * @param {number[][]} meetings
 * @param {number} firstPerson
 * @return {number[]}
 */
var findAllPeople = function(n, meetings, firstPerson) {
    meetings.sort((a, b) => a[2] - b[2]);

    const knows = new Array(n).fill(false);
    knows[0] = true;
    knows[firstPerson] = true;

    let i = 0;
    while (i < meetings.length) {
        const curTime = meetings[i][2];

        const graph = Array.from({ length: n }, () => []);
        let j = i;
        while (j < meetings.length && meetings[j][2] === curTime) {
            const [x, y] = meetings[j];
            graph[x].push(y);
            graph[y].push(x);
            j++;
        }

        const queue = [];
        let head = 0;
        for (let k = 0; k < n; k++) {
            if (graph[k].length && knows[k]) queue.push(k);
        }

        while (head < queue.length) {
            const cur = queue[head++];
            for (const next of graph[cur]) {
                if (!knows[next]) {
                    knows[next] = true;
                    queue.push(next);
                }
            }
        }

        i = j;
    }

    const result = [];
    for (let i = 0; i < n; i++) {
        if (knows[i]) result.push(i);
    }
    return result;
};