const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const tests = input.map(test => test.split(' ').map(Number));
const [N, M] = tests.shift();
//console.log(N, M, tests)
const subject = Array(M).fill(0);
const subjectCnt = Array(M).fill(0);
for(let i = 0; i < N; i++){
	subject[tests[i][0] - 1] += tests[i][1]; // 각 과목에 맞는 성적 입력
	subjectCnt[tests[i][0] - 1]++;
}

//평균 구하기
for(let i = 0; i < subject.length; i++){
	if(subject[i] !== 0) subject[i] = subject[i]/subjectCnt[i];
}

let maxAvg = subject[0];
let maxIndex = 0
for(let i = 0; i < subject.length; i++){
	if(subject[i] > maxAvg){
		maxAvg = subject[i]
		maxIndex = i;
	}
}
console.log(maxIndex + 1);
