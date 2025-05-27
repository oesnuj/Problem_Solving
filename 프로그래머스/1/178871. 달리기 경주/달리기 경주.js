function solution(players, callings) {
    const playerIndex = new Map();
    
    players.forEach((name, index) => {
        playerIndex.set(name, index);
    });
    for (let i = 0; i < callings.length; i++) {
        const name = callings[i];
        const index = playerIndex.get(name);
        const prevName = players[index - 1];
        
        [players[index - 1], players[index]] = [players[index], players[index - 1]];

        playerIndex.set(name, index - 1);
        playerIndex.set(prevName, index);   
    }
    return players;
}