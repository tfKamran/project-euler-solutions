module.exports = {
    evaluate: function(input) {
        const maxNumber = +input;

        var sum = 2;
        const primeNumbers = [2];

        for (var index = 3; index < maxNumber; index += 2) {
            var primeIndex = 0;

            for (; primeIndex < primeNumbers.length && index % primeNumbers[primeIndex] != 0; primeIndex++);

            if (primeIndex == primeNumbers.length) {
                primeNumbers.push(index);
                sum += index;
            }
        }

        return sum;
    }
}
