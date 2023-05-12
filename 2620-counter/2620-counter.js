/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) {
    var m = null
    return function() {
      if(m === null) m = n
      else  m = n + 1;
      n = m;
      return n;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */