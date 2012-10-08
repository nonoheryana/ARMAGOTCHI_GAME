#pragma once

#include "ofMain.h"
#include "Moods.h"
#include "AlienGotchi.h"
#include "EntityNames.h"
#include "ofxTimer.h"
//#include "TimeEvent.h"
//#include "timeObject.h"

class testApp : public ofBaseApp{
public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//void timeEvent(TimeEvent &t);
		//void timeUp(timeObject &o);

		//timeObject tObject;
		mood_type currentMood;
		int mood;
		int var;

		string msg;
		string msg1;

		//ofxTimer theTime;
		//float mills;
		
		
};
