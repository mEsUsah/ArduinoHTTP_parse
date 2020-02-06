/*
    Arduino Ehternet HTTP request parser.

    Call the function with parseRequest(firstLineOfRequest, variableYouWantTheValueOf);


    Function returns a String object with the variable content if variable is found.
    If not found, wil return a String object that is "-1"

    Example requestString = "GET /?led01=1&led02=0 HTTP/1.1"
    Example variable we want the value of = "led01"
    Example function call = parseRequest(requestString, "led01");
    Example return valie = "1"

    Read psudo code below for in debth explenation.

*/


//
String parseRequest(String requestString, String variableName){
	// If the first line of the HTTP request contains the variable we are looking for, find the value of it. 
    if(requestString.indexOf(variableName)>0){
		// Check where the variable value starts =
        // beginning of variable name + number of characters in the variable + the "=" symbol.
        unsigned int keyStart = readString.indexOf(variableName) + variableName.length()+1; 
		unsigned int keyEnds;
        // Check if there are other variables after the target variable.
        // If there is, the variable value stops before & symbol
		if(readString.indexOf("&", keyStart)>0) {				
			keyEnds = readString.indexOf("&", keyStart);
        // If no other variables after the variable we are looking for, there is a empty space before the "HTTP/1.1""
		} else {
			keyEnds = readString.indexOf(" ", keyStart);
		}
        // Return the value of the variable we are searching for
		return requestString.substring(keyStart, keyEnds);
	} else {
        // If there is no variable by the name we are looking for, return "-1"
		return "-1";
	}
}