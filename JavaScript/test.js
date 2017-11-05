const assert = require('assert');
const fs = require('fs');
const specifiedProblem = require('yargs').argv.problem;

const problems = fs.readdirSync('./').filter(item => item.startsWith('problem-'));

if (specifiedProblem) {
    test(specifiedProblem);
} else {
    console.log("\nYou can test a particular solution by specifying the directory:\n\n\t Example: mocha test.js --problem problem-0001");

    problems.forEach(test);
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
            const testResult = require('./' + problemDir + '/index.js').evaluate(fs.readFileSync(problemDir + '/test-input.txt', 'utf-8'));

            if (fs.existsSync(problemDir + '/test-output.txt')) {
                const testExpectedOutput = fs.readFileSync(problemDir + '/test-output.txt', 'utf-8');

                it('should return ' + testExpectedOutput, function() {
                    assert.equal(testExpectedOutput, testResult);
                });
            } else {
                it('does it pass?', function() {
                    console.log('      Nothing to judge yet, the test result is ' + testResult);
                });
            }
        });
    });
}
