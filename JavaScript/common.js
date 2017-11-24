String.prototype.reverse = function() {
    return this.split('').reverse().join('');
};

module.exports = {
    isPalindrome: function(number) {
        const numberInString = '' + number;
        const length = numberInString.length;
        
        return numberInString.substr(0, length / 2) == numberInString.substr(length / 2).reverse();
    },
    isPrimeNumber: function(number) {
        var isPrime = true;

        for (var index = 3; (index <= Math.sqrt(number)) && (isPrime &= (number % index != 0)); index += 2);

        return isPrime;
    },
    getPrimeNumbers: function(condition) {
        const primeNumbers = [2];

        for (var index = 3; condition(primeNumbers, index); index += 2) {
            if (this.isPrimeNumber(index)) {
                primeNumbers.push(index);
            }
        }

        return primeNumbers;
    }
}
