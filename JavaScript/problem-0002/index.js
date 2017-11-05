module.exports = {
    evaluate: function(input) {
        const limit = +input;
        const fibonacci = [1, 2];

        while ((nextTerm = this.getNextSum(fibonacci)) < limit) {
            fibonacci.push(nextTerm);
        }

        return fibonacci.reduce((total, term) => term % 2 == 0 ? total + term : total) - 1;
    },
    getNextSum(fibonacci) {
        const length = fibonacci.length;
        return fibonacci[length - 1] + fibonacci[length - 2];
    }
}
