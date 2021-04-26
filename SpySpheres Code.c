//Declare any variables shared between functions here



#define otherPos (&otherState[0])
#define otherVel (&otherState[3])
#define otherAtt (&otherState[6])

#define myPos (&myState[0])
#define myVel (&myState[3])
#define myAtt (&myState[6])
#define myAttRate (&myState[9])

float attTarget[3];

float myState[12];
float otherState[12];

float zeroVec[3];
float earthVec[3];

float targPos[3];
int attCase;
int scoreItem;
int energyItem;
float modifier;
int posCase;


void init(){
	zeroVec[0] = 0;
	zeroVec[1] = 0;
	zeroVec[2] = 0;
	earthVec[0] = 0;
	earthVec[1] = 0;
	earthVec[2] = 1;
	attCase = 0;
	scoreItem = 3;
	energyItem = 0;
	modifier = 0;
	posCase = 0;
}

void loop(){
    api.getOtherZRState(otherState);
	api.getMyZRState(myState);
	//switch for pos
	
	switch(posCase){
	    case 0:
	        if(game.hasItem(scoreItem) != -1 and scoreItem<6){
	            scoreItem++;
	        }
	        game.getItemLoc(targPos, scoreItem);
	        if(game.getEnergy()<2){
	            posCase = 1;
	        }
	        break;
	    case 1:
	        if(game.hasItem(energyItem) != -1 and energyItem<2){
	            energyItem++;
	        }
	        else{
	            if(game.getLightGreyBoundary()<0){
    	            modifier = -.1;
    	        }
    	        else{
    	            modifier = .1;
    	        }
    	        targPos[0] = myPos[0];
    	        targPos[1] = game.getLightGreyBoundary()+modifier;
    	        targPos[2] = myPos[2];
	        }
	        game.getItemLoc(targPos, energyItem);
	        if(game.getEnergy()>2){
	            posCase = 0;
	        }
	        break;
	} 
	
	//switch for attitude
	switch(attCase){
	
    	//taking pictures case
    	case 0:
    	//check if it can take a picture
    	    mathVecSubtract(attTarget, otherPos, myPos, 3);
    	    if(game.isFacingOther() and game.posInLight(otherPos) and game.getMemoryFilled() < 2 and game.getEnergy()>3){
    	        game.takePic();
    	    }
    	    //if memory is full, go to the uploading case
    	    if(game.getMemoryFilled() == 2){
    	        attCase = 1;
    	    }
    	    break;
    	//uploading to earth case
    	case 1:
    	    //point at earth
    	    memcpy(attTarget, earthVec, 12);
    	    if(acos(mathVecInner(earthVec, myAtt, 3)/mathVecMagnitude(myAtt, 3))<.25 and game.getEnergy()>3 and mathVecMagnitude(myAttRate, 3)<.05){
    	        game.uploadPics();
    	    }
    	    if(game.getMemoryFilled()<2){
    	        attCase = 0;
    	    }
    	    break;
	//checking if it wants to take a picture

	
	}
	//memcpy(targPos, myPos, 12);
	api.setPositionTarget(targPos);
	api.setAttitudeTarget(attTarget);
	//This function is called once per second.  Use it to control the satellite.
}

