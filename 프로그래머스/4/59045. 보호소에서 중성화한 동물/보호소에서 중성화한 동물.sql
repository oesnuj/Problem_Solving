SELECT ai.ANIMAL_ID, ai.ANIMAL_TYPE, ai.NAME
FROM ANIMAL_INS ai JOIN ANIMAL_OUTS ao on ai.ANIMAL_ID = ao.ANIMAL_ID
WHERE ai.SEX_UPON_INTAKE like 'Intact %ale'
and (ao.SEX_UPON_OUTCOME like 'Spayed %ale' or ao.SEX_UPON_OUTCOME like 'Neutered %ale')
ORDER BY ai.ANIMAL_ID;