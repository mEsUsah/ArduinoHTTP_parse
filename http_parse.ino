/**********************************************************************************************
    --- Arduino Ehternet HTTP request parser ---
    Written by Stanley Skarshaug, 06.02.2020 - Norway.
    Free to use - if credit is given to author.

    Call the function with parseRequest(firstLineOfRequest, variableYouWantTheValueOf);

    Function returns a String object with the variable content if variable is found.
    If not found, wil return a String object that is "-1"

    Example requestString = "GET /?led01=1&led02=0 HTTP/1.1"
    Example variable we want the value of = "led01"
    Example function call = parseRequest(requestString, "led01");
    Example return value = "1"
    
**********************************************************************************************/

String parseRequest(String requestString, String variableName){ 
    if(requestString.indexOf(variableName)>0){
        unsigned int varStarts = readString.indexOf(variableName) + variableName.length()+1; 
		unsigned int varEnds;

		if(readString.indexOf("&", varStarts)>0) {				
			varEnds = readString.indexOf("&", varStarts);
		} else {
			varEnds = readString.indexOf(" ", varStarts);
		}

		return requestString.substring(varStarts, varEnds);
	} else {
		return "-1";
	}
}