#pragma once
#include "ofMain.h"
#include "ofxTimer.h"

class TheTimer{

public:
	float mills;

	ofxTimer myTime;

	TheTimer(){
		myTime.setup(1000,true);
		mills = 0;
	}

	void update(){
		
		if (myTime.isTimerFinished())
		{
			cout<<"time's up"<<endl;
		}

	}
};