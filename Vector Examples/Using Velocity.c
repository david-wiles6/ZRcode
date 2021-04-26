//Sometimes you want to set your velocity instead of setting your position so that you have more precise control over your speed
//in that case you have to find the direction that you want to go and use api.setVelocityTarget(float[3] target velocity) to set that
#define myVel (&myState[3])
#define myPos (&myState[0])

float myState[12];
float targPos[3];
float targVel[3];


float velModifier;
void init(){
  //velModifier defines what the velocity should be based on the distance from the object, in this case
  //velocity will be 10% of the distance, if the distance was 10 meters, the velocity would be 1 meter/second
  velModifier = .1;
  targPos[0] = 0;
  targPos[1] = .5;
  targPos[2] = .5;
  
}

void loop(){
  api.getMyZRState(myState);
  //get direction of correct velocity by getting the vector between your position
  //and the target position using vector subtraction
  mathVecSubtract(targVel, targPos, myPos, 3);
  //multiply the velocity by the modifier so it doesn't go too fast
  targVel[0] *= velModifier;
  targVel[1] *= velModifier;
  targVel[2] *= velModifier;
}
