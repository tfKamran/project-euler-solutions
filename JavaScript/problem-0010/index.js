module.exports = {
    evaluate: function(input) {
        const maxNumber = +input;

        var sum = 2;

        for (var index = 3; index < maxNumber; index += 2) {
            var isPrime = true;

            for (var divisor = 3; (divisor <= Math.sqrt(index)) && (isPrime &= (index % divisor != 0)); divisor += 2);

            if (isPrime) {
                sum += index;
            }
        }

        return sum;
    }
}
