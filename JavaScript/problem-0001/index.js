module.exports = {
    evaluate: function(input) {
        return Array(+input).fill(0)
                .map((item, index) => (index % 3 == 0 || index % 5 == 0) ? index : 0)
                .reduce((total, current) => total + current);
    }
}
