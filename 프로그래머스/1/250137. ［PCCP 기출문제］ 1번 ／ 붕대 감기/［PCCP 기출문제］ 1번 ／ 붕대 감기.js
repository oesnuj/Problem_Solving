function attack(health, damage) { 
    return health - damage;
}


function solution(bandage, health, attacks) {
    const [ t, x, y ] = bandage;
    // 치유시간 
    // 마지막 공격 시간 전까지 반복,,
    const maxHealth = health;
    let time = 0;
    let combo = 0;
    let attackIndex = 0;
    
    while(time <= attacks[attacks.length - 1][0]){
        // 공격
        if(attacks[attackIndex][0] === time){
            health -= attacks[attackIndex][1];
            attackIndex++;
            combo = 0;   
            if(health <= 0) return -1;
        }
        // 회복
        else {
            health += x;
            if(health > maxHealth) health = maxHealth;
            combo++;
            if(combo === t){
                health += y;
                if(health > maxHealth) health = maxHealth;
                combo = 0;   
            }   
        }
        time++;
    }
    
    return health;
}