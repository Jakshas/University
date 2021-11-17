var fs = require('fs');

fs.readFile('1.txt', bar)

function bar (err, data)
  {
  err ? Function("error","throw error")(err) : console.log(data.toString('utf8'));
  };