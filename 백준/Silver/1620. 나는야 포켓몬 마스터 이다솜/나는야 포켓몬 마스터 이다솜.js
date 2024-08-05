const fs = require('fs');
const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filepath).toString().trim().split('\n');

const N = +input[0].split(' ')[0];
const pokemonList = input.slice(1, 1 + N);
const testList = input.slice(1 + N);

// 이름을 키로 하고 번호를 값으로 하는 단일 Map 객체 생성
const pokemonMap = new Map();

pokemonList.forEach((pokemon, index) => {
    const number = index + 1;
    pokemonMap.set(pokemon, number);
});

// 테스트 리스트의 Pokémon을 조회하고 출력
const output = testList.map(test => {
    const num = Number(test);
    if (!isNaN(num)) {
        // 테스트 값이 번호인 경우
        return pokemonList[num - 1]; // 번호에 해당하는 Pokémon 이름 출력
    } else {
        // 테스트 값이 이름인 경우
        return pokemonMap.get(test); // 이름에 해당하는 Pokémon 번호 출력
    }
}).join('\n');

console.log(output);