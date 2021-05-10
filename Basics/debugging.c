//Much like everything else in c, debugging is SUPER weird, it takes some getting used to 
//but it makes sense eventually

//Debugging is used to print variables and messages to the chat
//it uses the syntax: DEBUG(("message"));
// if you want to print a variable to the chat, it's a bit different from other coding
//languages 
//you will need to use an escape character % and then a letter associated with the variable type
//floats are %f booleans are %b and ints are %d, then for each escaped character, you have to put a variable
//of the same type after the message, demarcated by commas
//like this:
float myVariable;

myVariable = 3.0f;

DEBUG(("%f", myVariable));

//this will output 3.0 to the console in the simulation since that is the value of myVariable
