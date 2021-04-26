//our two arrays to subtract, and the array that will recieve the subtraction.

float[3] aVec;
float[3] bVec;
float[3] targetVec;

void init(){
  aVec[0] = .3;
  aVec[1] = .4;
  aVec[2] = .2;
  
  bVec[0] = .7;
  bVec[1] = .2;
  bVec[2] = .3;
}

void loop(){
  mathVecSubtract(targetVec, bVec, aVec, 3);
}
