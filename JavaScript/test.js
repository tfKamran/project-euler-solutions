const assert = require('assert');
const fs = require('fs');
const specifiedProblem = require('yargs').argv.problem;

const common = require('./common');

if (specifiedProblem) {
    test(specifiedProblem);
} else {
    console.log("\nYou can test a particular solution by specifying the directory:\n\n\t Example: mocha test.js --problem problem-0001");

    testAllProblems();

    testCommon();
}

function testAllProblems() {
    fs.readdirSync('./').filter(item => item.startsWith('problem-')).forEach(test);
}

function testCommon() {
    describe('# Common functions', function() {
        describe('## isPalindrome', function() {
            it('should return true for Palindrome', function() {
                assert.equal(true, common.isPalindrome(9009));
            });

            it('should return false for non Palindrome', function() {
                assert.equal(false, common.isPalindrome(9609));
            });
        });

        describe('## isPrimeNumber', function() {
            it('should return true for prime number', function() {
                assert.equal(true, common.isPrimeNumber(7));
            });

            it('should return false for non prime number', function() {
                assert.equal(false, common.isPrimeNumber(15));
            });
        });

        describe('## getPrimeNumbers', function() {
            it('should return first prime number', function() {
                assert.deepEqual([2], common.getPrimeNumbers(primeNumbers => primeNumbers.length < 1));
            });

            it('should return first five prime numbers', function() {
                assert.deepEqual([2, 3, 5, 7, 11], common.getPrimeNumbers(primeNumbers => primeNumbers.length < 5));
            });

            it('should return prime numbers lesser than 10', function() {
                assert.deepEqual([2, 3, 5, 7], common.getPrimeNumbers((primeNumbers, currentNumber) => currentNumber < 10));
            });
        });
    });
}

function test(problemDir) {
    describe('# Problem number: ' + problemDir.split('-')[1], function() {
        describe('## With sample input', function() {
            const sampleExpectedOutput = fs.readFileSync(problemDir + '/sample-output.txt', 'utf-8');

            it('should return ' + sampleExpectedOutput, function() {
                assert.equal(sampleExpectedOutput,
                    require('./' + problemDir + '/index.js').evaluate(fs.readFileSync(problemDir + '/sample-input.txt', 'utf-8')));
            });
        });

        describe('## With test input', function() {
            const startTime = getTimeInMicroSeconds();
            const testResult = require('./' + problemDir + '/index.js').evaluate(fs.readFileSync(problemDir + '/test-input.txt', 'utf-8'));
            const timeTaken = getTimeInMicroSeconds() - startTime;

            if (fs.existsSync(problemDir + '/test-output.txt')) {
                const testExpectedOutput = fs.readFileSync(problemDir + '/test-output.txt', 'utf-8');

                it('should return ' + testExpectedOutput, function() {
                    assert.equal(testExpectedOutput, testResult);
                    console.log('      Took ' + timeTaken + ' micros');
                });
            } else {
                it('does it pass?', function() {
                    console.log('      Nothing to judge yet, the test result is ' + testResult + ' in ' + timeTaken + ' micros');
                });
            }
        });
    });
}

function getTimeInMicroSeconds() {
  var hrTime = process.hrtime();

  return hrTime[0] * 1000000 + parseInt(hrTime[1] / 1000);
}
