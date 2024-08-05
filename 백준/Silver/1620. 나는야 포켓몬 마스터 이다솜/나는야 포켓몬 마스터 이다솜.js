const filepath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = require('fs').readFileSync(filepath).toString().trim().split('\n');
const [N, M] = input[0].split(' ').map(Number);

const cleanInput = input.map(line => line.trim());
const pokemonList = cleanInput.slice(1, 1 + N);
const testList = cleanInput.slice(1 + N);

// Pokémon 이름을 번호로 매핑하는 Map 객체
const nameToNumber = new Map();
// 번호를 Pokémon 이름으로 매핑하는 Map 객체
const numberToName = new Map();


pokemonList.forEach((pokemon, index) => {
    const number = index + 1;
    nameToNumber.set(pokemon, number);
    numberToName.set(number, pokemon);
});


testList.forEach(test => {
    const num = Number(test);
    if (!isNaN(num)) {
        // 테스트 값이 번호인 경우
        console.log(numberToName.get(num)); // 번호에 해당하는 Pokémon 이름 출력
    } else {
        // 테스트 값이 이름인 경우
        console.log(nameToNumber.get(test)); // 이름에 해당하는 Pokémon 번호 출력
    }
});
