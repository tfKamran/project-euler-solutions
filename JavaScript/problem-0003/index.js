module.exports = {
    evaluate: function(input) {
        var number = +input;

        for (var index = 2; index < number / 2; index++) {
            if (number % index == 0) {
                number = number / index;
            }
        }

        return number;
    }
}
