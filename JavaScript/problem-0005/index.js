module.exports = {
    evaluate: function(input) {
        const maxDivisor = +input;
        var number = maxDivisor;

        while (!this.isDivisibleByAll(number, maxDivisor)) number += maxDivisor;

        return number;
    },
    isDivisibleByAll: function(number, maxDivisor) {
        var isDivisible = true;

        for (var divisor = 2; (divisor <= maxDivisor) && (isDivisible &= number % divisor == 0); divisor++);

        return isDivisible;
    }
}
