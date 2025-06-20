function solution(s, skip, index) {
    let answer = '';
    const skipSet = new Set(skip);

    for (let char of s) {
        let shift = 0;
        let current = char.charCodeAt(0) - 97;

        while (shift < index) {
            current = (current + 1) % 26;
            if (skipSet.has(String.fromCharCode(current + 97))) continue;
            shift++;
        }

        answer += String.fromCharCode(current + 97);
    }

    return answer;
}
