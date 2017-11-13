module.exports = {
    evaluate: function(input) {
        const sum = +input;

        for (var c = 3; c < sum; c++) {
            for (var b = 2; b < c; b++) {
                for (var a = 1; a < b; a++) {
                    if ((a + b + c) == sum && (a * a) + (b * b) == (c * c)) {
                        return a * b * c;
                    }
                }   
            }
        }
    }
}
