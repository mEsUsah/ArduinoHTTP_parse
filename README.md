# Arduino Ehternet HTTP request parser.

Call the function with parseRequest(firstLineOfRequest, variableYouWantTheValueOf);


Function returns a String object with the variable content if variable is found.
If not found, wil return a String object that is "-1"

Example requestString = "GET /?led01=1&led02=0 HTTP/1.1"
Example variable we want the value of = "led01"
Example function call = parseRequest(requestString, "led01");
Example return valie = "1"

Read psudo code for in scetch for in debth explenation.