module.exports = {
    evaluate: function(input) {
        const limit = +input;
        var sum = 2;
        var secondLast = 2;
        var last = 3;

        while ((nextTerm = last + secondLast) < limit) {
            secondLast = last;
            last = nextTerm;

            if (last % 2 == 0) {
                sum += last;
            }
        }

        return sum;
    }
}
