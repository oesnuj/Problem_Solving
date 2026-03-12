function solution(n, control) {
  for(i=0; i<control.length; i++) {
      const index = control[i]
      if(index === "w") {
          n += 1;
      }
      if(index === "s") {
          n -= 1;
      }
        if(index === "d") {
          n += 10;
      }
        if(index === "a") {
          n -= 10;
      }
  }
    return n
}