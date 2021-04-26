//moving the sphere is quite straightforward, tell the sphere what point to move to
//with a 3 element array representing a point in space
//then tell it to go there with api.setPositionTarget

float[3] targetPosition;

void init(){
  //array and variable initialization should be in the init block
  //remember arrays in c are 0-indiced, which means that array elements start at 0
  //in this case, the target position is (0, .2, .5)
  targetPosition[0] = 0;
  targetPosition[1] = .2;
  targetPosition[2] = .5;
}

void loop(){
  //if you wanted the target position to change at any point, you could do that in the loop with a conditional
  //once the init is finished, the loop runs until the game ends
  api.setPositionTarget(targetPosition);
}
