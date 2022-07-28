const fs = require('fs');
process.argv.forEach(function (val, index, array) {
  console.log(index + ': ' + val);
});

const dirName = process.argv[2];

fs.mkdirSync(dirName);

const cppFiles = ["A", "B", "C", "D", "E", "F"];

for(var i = 0; i < cppFiles.length; i++) {
	fs.writeFileSync(dirName + "/" + cppFiles[i] + ".cpp", "");
}

fs.writeFileSync(dirName + "/" + "input.txt", "");
fs.writeFileSync(dirName + "/" + "output.txt", "");

