String.prototype.reverse = function() {
    return this.split('').reverse().join('');
};

module.exports = {
    isPalindrome: function(number) {
        const numberInString = '' + number;
        const length = numberInString.length;
        
        return numberInString.substr(0, length / 2) == numberInString.substr(length / 2).reverse();
    }
}
