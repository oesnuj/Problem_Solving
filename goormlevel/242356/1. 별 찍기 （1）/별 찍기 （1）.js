const solution = (data) => {
	let star = "*";
  for(let i = 0; i< data; i++)
		{
			console.log(star);
			star += '*';
		}
};

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let data;
rl.on('line', function (line) {
  data = line;
  rl.close();
}).on('close', function () {
  solution(data);
  process.exit();
})