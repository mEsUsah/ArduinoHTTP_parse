# Arduino Ehternet HTTP request parser.

Call the function with parseRequest(firstLineOfRequest, variableYouWantTheValueOf);


Function returns a String object with the variable content if variable is found.
If not found, wil return a String object that is "-1"

* Example requestString = "GET /?led01=1&led02=0 HTTP/1.1"
* Example variable we want the value of = "led01"
* Example function call = parseRequest(requestString, "led01");
* Example return valie = "1"

Code Explanation

* If the first line of the HTTP request contains the variable we are looking for, find the value of it. If the variable is not found, return "-1".
* Check where the variable value starts.
* beginning of variable name + number of characters in the variable + the "=" symbol.
* Check if there are other variables after the target variable.
* If there is, the variable value stops before & symbol.
* If no other variables after the variable we are looking for, there is a empty space before the "HTTP/1.1".
* Return the value of the variable we are searching for as a Sting object.