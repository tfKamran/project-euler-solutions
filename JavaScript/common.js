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

        for (var index = 2; (index <= number / 2) && (isPrime &= (number % index != 0)); index++);

        return isPrime;
    },
    getPrimeNumbers: function(count) {
        const primeNumbers = [];

        for (var index = 2; primeNumbers.length < count; index++) {
            if (primeNumbers.filter(prime => index % prime == 0).length == 0) {
                primeNumbers.push(index);
            }
        }

        return primeNumbers;
    }
}
