//Arrays are useful because they can provide a lot of information that can be looped through or 
//keeps information that goes together together and in order, which is important when representing points or 
//vectors in space.

//To create an array, use this format: <Data Type>[<Number of Elements>] <Array Name>;

//this array has 8 elements that are of the data type boolean, which means they hold a true or false value;
bool[8] boolArray;

//this array holds 3 elements that are floating point numbers, which hold decimal numbers
//this is how we will represent points, with 3 element floating point arrays
float[3] point;

void init(){
  //this is where you can initialize the elements in the arrays
  //this sets the 4th element of boolArray to false
  boolArray[3] = false;
  
  //this sets all three of the elements in point to .3
  point[0] = .3;
  point[1] = .3;
  point[2] = .3;
}

void loop(){
  //anything can go in here, its not important to building arrays
}
