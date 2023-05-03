const fs = require("fs");
const filePath =
  process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt";

const input = fs.readFileSync(filePath).toString().trim().split("\n");
const [n, ...arr] = input;

let stack = [];

for (let i = 0; i < n; i++) {
  stack = [];
  for (let j = 0; j < arr[i].length; j++) {
    if (arr[i][j] === "(") {
      stack.push("(");
    } else {
      if (stack.length) {
        stack.pop();
      } else {
        stack.push(")");
        break;
      }
    }
  }
  if (stack.length) {
    console.log("NO");
  } else {
    console.log("YES");
  }
}
