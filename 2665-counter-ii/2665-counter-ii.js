/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let m = init;
    function increment(){
        return ++m;
    } 
    function decrement(){
        return --m;
    }
    
    function reset(){
        return (m = init);
    }
    
    return { increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */