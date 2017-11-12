module.exports = {
    evaluate: function(input) {
        const maxNumber = +input;

        const emptyArray = new Array(maxNumber).fill(0);

        const sumOfNumbers = emptyArray.map((item, index) => index + 1).reduce((item, total) => total + item);
        const sumOfSquares = emptyArray.map((item, index) => (index + 1) * (index + 1)).reduce((item, total) => total + item);

        return (sumOfNumbers * sumOfNumbers) - sumOfSquares;
    }
}
