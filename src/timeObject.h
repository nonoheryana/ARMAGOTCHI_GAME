#ifndef OFXEVENTSADDON_H_
#define OFXEVENTSADDON_H_

#include "ofMain.h"
#include "ofEvents.h"
#include "ofxTimer.h"

class timeObject{

public:
	
	ofxTimer myTime;

	timeObject(){
		mills=0;
	}
	void setup(){
		
		myTime.setup(1000,true);
	}


	void update(ofEventArgs & args){
		ofNotifyEvent(timeOutEvent,this,this);
	}

	 static ofEvent <timeObject> timeOutEvent;

private:
	float mills;
};



#endif /* OFXEVENTSADDON_H_ */