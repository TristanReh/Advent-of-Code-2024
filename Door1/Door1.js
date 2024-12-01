const fs = require('node:fs');

var array = fs.readFileSync('inputdoor1.txt', 'utf8').split(/\s+/).map(Number);
var leftColumn = array.filter((_, i) => i % 2 === 0)
var rightColumn = array.filter((_, i) => i % 2 === 1)

leftColumn.sort();
rightColumn.sort();

var result = 0;

for (let i = 0; i < leftColumn.length; i++) {
    if (leftColumn[i] >= rightColumn[i]) {
        result += leftColumn[i] - rightColumn[i]
    } else result += rightColumn[i] - leftColumn[i]
} 

console.log(result)

result = 0;

for (let i = 0; i < leftColumn.length; i++) {
    var rightColumnFiltered = rightColumn.filter((elem) => elem == leftColumn[i])
    
    result += leftColumn[i] * rightColumnFiltered.length;
    
}

console.log(result)
