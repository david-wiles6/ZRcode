//This time we will try to get the sphere to aim at a point, note it is not necessary to be moving in the direction the
//sphere is facing because the thrusters are omnidirectional

#define myPos (&myState[0])
#define myAtt (&myState[6])

float myState[12];

float targetAttitude[3];

void init(){
  //we are going to try to make the sphere look at the point (0, .4, .3)
  targetAttitude[0] = 0;
  targetAttitude[1] = .4;
  targetAttitude[2] = .3;
}
