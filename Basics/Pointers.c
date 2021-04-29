// Here we are talking about a special way to use less RAM, as well as make it easier to look at specific elements in an array called pointers
// Pointers are defined: #define (name) (&(where to point to))
//for example

#define myPosition (&myState[0])

//note that you don't need a semicolon
//this points to the array myState, which is going to be a 12 element array that defines a variety of information about 
//your sphere, and the first 3 elements of this (0-2) are your position
//instead of creating an array for your position and updating the array each time the loop runs,
//you can tell the program that whenever you reference that term, look at the other array

//tldr; myPosition will always be equal to the first 3 elements of myState

//define myState
float myState;

void init(){
  
}

void loop(){
  //store your information in myState, which will also 
  api.getMyZRState(myState);
  
  //this will print your position to the debug menu
  DEBUG(("%f, %f, %f", myPosition[0], myPosition[1], myPosition[2]));
}
