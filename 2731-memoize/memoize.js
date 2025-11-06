/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let memoizedSet = {};

    return function (...args) {
        let key = args.join(",");
        if (key in memoizedSet) {
            return memoizedSet[key];
        }
        else {
            memoizedSet[key] = fn(...args)
            return memoizedSet[key]
        }

    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */