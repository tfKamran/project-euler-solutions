module.exports = {
    evaluate: function(input) {
        const count = +input;

        const primeNumbers = [];

        for (var index = 2; primeNumbers.length < count; index++) {
            var primeIndex = 0;

            for (; primeIndex < primeNumbers.length; primeIndex++) {
                if (index % primeNumbers[primeIndex] == 0) {
                    break;
                }
            }

            if (primeIndex == primeNumbers.length) {
                primeNumbers.push(index);
            }
        }

        return primeNumbers[primeNumbers.length - 1];
    }
}
