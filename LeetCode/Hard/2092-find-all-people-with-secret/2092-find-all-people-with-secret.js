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

        const graph = new Map();
        let j = i;
        while (j < meetings.length && meetings[j][2] === curTime) {
            const [x, y] = meetings[j];
            if (!graph.has(x)) graph.set(x, []);
            if (!graph.has(y)) graph.set(y, []);
            graph.get(x).push(y);
            graph.get(y).push(x);
            j++;
        }

        const queue = [];
        let head = 0;
        for (const node of graph.keys()) {
            if (knows[node]) queue.push(node);
        }

        while (head < queue.length) {
            const cur = queue[head++];
            for (const next of graph.get(cur)) {
                if (!knows[next]) {
                    knows[next] = true;
                    queue.push(next);
                }
            }
        }
        i = j;
    }

    return knows.reduce((acc, val, idx) => {
        if (val) acc.push(idx);
        return acc;
    }, []);
};