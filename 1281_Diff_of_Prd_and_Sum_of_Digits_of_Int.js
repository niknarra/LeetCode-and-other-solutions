/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    var n_sum = 0;
    var n_prd = 1;

    while(n>0){
        let digit = n%10;
        n_sum += digit;
        n_prd *= digit;

        n = Math.floor(n/10);
    }

    return n_prd - n_sum;
};
