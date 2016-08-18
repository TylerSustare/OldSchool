/* activities from ch 3 of elegant JS */
/* Recursion example */
function isEven(recNum){
  if (recNum == 0){
    return "even";
  }
  if (recNum == 1){
    return "odd";
  }
  if (recNum < 0){
    return isEven(-recNum);
  }
  return isEven(recNum - 2);
  /* return the function, not just call it. */
}

console.log(isEven(10));
console.log(isEven(11));
console.log(isEven(-10));

/******************0**********************/
/* Function to count the number of "B" characters
are in a given string  */
var countBs = function (string) {
  var numOfBs = 0;
  for (var i = 0; i < string.length; ++i) {
    if (string.charAt(i) == "B") {
      numOfBs++;
    }
  }
  return numOfBs;
};
console.log(countBs("BBC"));