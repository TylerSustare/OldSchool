
/* DOM Creation functions */
// / create elements
var newTing = function (elementToAdd, content, parent, property){
    var newItem = document.createElement(elementToAdd);
    newItem.textContent = content;
    parent.appendChild(newItem);
};

// makes cells for table
var tabTastic = function (j){
    var newRow = document.createElement("tr");
    tBody.appendChild(newRow);
    for (var i = 1; i <= 4; ++i){
        newTing("td", i + ", " + j, newRow);
	}
};

// creates buttons
var makeButton = function (direction){
    var newButton = document.createElement("button");
    var t = document.createTextNode(direction);
    newButton.id = direction;
    newButton.appendChild(t);
    document.body.appendChild(newButton);
};

/* Event funcitons */
function moveRight (/*theChosenOne*/) {
    var theChosenOne = document.getElementById("chosen");
    theChosenOne.style.borderWidth = "1px";
    theChosenOne.removeAttribute("id");
    theChosenOne = theChosenOne.nextElementSibling;
    theChosenOne.style.borderWidth = "3px";
    theChosenOne.id = "chosen";
}

function moveDown (theChosenOne) {
    var theChosenOne = document.getElementById("chosen");
    theChosenOne.style.borderWidth = "1px";
    theChosenOne.removeAttribute("id");
    theChosenOne = theChosenOne.parentNode;
    theChosenOne = theChosenOne.nextElementSibling;
    theChosenOne = theChosenOne.firstElementChild;
    theChosenOne.style.borderWidth = "3px";
    theChosenOne.id = "chosen";
}

function moveLeft (theChosenOne) {
    var theChosenOne = document.getElementById("chosen");
    theChosenOne.style.borderWidth = "1px";
    theChosenOne.removeAttribute("id");
    theChosenOne = theChosenOne.previousElementSibling;
    theChosenOne.style.borderWidth = "3px";
    theChosenOne.id = "chosen";
}

function moveUp (theChosenOne) {
    var theChosenOne = document.getElementById("chosen");
    theChosenOne.style.borderWidth = "1px";
    theChosenOne.removeAttribute("id");
    theChosenOne = theChosenOne.parentNode;
    theChosenOne = theChosenOne.previousElementSibling;
    theChosenOne = theChosenOne.firstElementChild;
    theChosenOne.style.borderWidth = "3px";
    theChosenOne.id = "chosen";
}

function markIt (theChosenOne){
    var theChosenOne = document.getElementById("chosen");
    theChosenOne.style.background = "yellow";
    theChosenOne.stopPropagation();
}


/* Basically main() to you "C" faring folk */
var newTable = document.createElement("table");
newTable.border = "1px";

var tHead = document.createElement("thead");
newTable.appendChild(tHead);

for(var i = 1; i <= 4; i++){
    newTing("th", "Headder " + i, tHead);
}
var tBody = document.createElement("tbody");
newTable.appendChild(tBody);

for (var i = 1; i <= 4; i++){
    tabTastic(i);
}

document.getElementById("putYourTableHere").appendChild(newTable);

makeButton("Up"); makeButton("Down");
makeButton("Left"); makeButton("Right");
makeButton("Mark");

var theChosenOne = document.getElementsByTagName("td")[0];
theChosenOne.id = "chosen";
theChosenOne.style.borderWidth = "3px";

document.getElementById("Up").addEventListener("click", moveUp);
document.getElementById("Down").addEventListener("click", moveDown);
document.getElementById("Left").addEventListener("click", moveLeft);
document.getElementById("Right").addEventListener("click", moveRight);
document.getElementById("Mark").addEventListener("click", markIt);
