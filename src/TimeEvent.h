#pragma once
#include "ofMain.h"
#include "TheTimer.h"

class TimeEvent : public ofEventArgs {

public:
	
	TheTimer *theTimer; 

	TimeEvent(){
		theTimer=NULL;
	}

	static ofEvent <TimeEvent> events;

};