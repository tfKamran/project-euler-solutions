module.exports = {
    evaluate: function(input) {
        const common = require('../common');

        const numberOfDigits = +input;

        var number = 0;

        const maxNumber = this.getMaximumNumber(numberOfDigits);
        const minNumber = this.getMinimumNumber(numberOfDigits);

        console.log('Starting with ' + maxNumber);

        const palindromes = [];

        for (var multiplicand = maxNumber; multiplicand > minNumber; multiplicand--) {
            for (var multiplier = maxNumber; multiplier > minNumber; multiplier--) {
                if (common.isPalindrome(number = (multiplicand * multiplier))) {
                    palindromes.push(number);
                }
            }
        }

        return palindromes.sort()[palindromes.length - 1];
    },
    getMaximumNumber(numberOfDigits) {
        var number = '9';

        while (number.length < numberOfDigits) number += '9';

        return +number;
    },
    getMinimumNumber(numberOfDigits) {
        var number = '1';

        while (number.length < numberOfDigits) number += '0';

        return +number;
    }
}
