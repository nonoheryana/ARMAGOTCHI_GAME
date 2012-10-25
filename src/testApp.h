#pragma once

#include "ofMain.h"
#include "Moods.h"
#include "AlienGotchi.h"
#include "EntityNames.h"
#include "ofxTimer.h"


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


		// callback gia otan tha teleiwsei o timer
		void timer1_ended(ofEventArgs &e);
		void timer2_ended(ofEventArgs &f);
		void timer3_ended(ofEventArgs &g);

		ofxTimer myTimer_health;
		ofxTimer myTimer_hungry;
		ofxTimer myTimer_happy;

		mood_type currentMood;
		int mood;
		int var;

		string msg;

		int count_time;
		//float mills;		
};
