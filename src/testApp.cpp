#include "testApp.h"
AlienGotchi alien(ent_AlienGotchi);
//--------------------------------------------------------------
void testApp::setup(){
	var=0;
	//theTime.setup(1000,true);
	// listen to any of the events for the game
	//ofAddListener(TimeEvent::events, this, &testApp::timeEvent);
	
}

//oid testApp::timeUp(timeObject &o){

//}

/*void testApp::timeEvent(TimeEvent &t){

	t.theTimer->update();
	
	
}*/
//--------------------------------------------------------------
void testApp::update(){
	alien.Update();
	ofSleepMillis(800);
	//static TimeEvent newEvent;
	//ofNotifyEvent(TimeEvent::events, newEvent);
	//mills=theTime.getTimeLeftInMillis();
	//cout<<mills<<endl;

	
}

//--------------------------------------------------------------
void testApp::draw(){
	msg=alien.Message();
	ofSetColor(0x000000);
	ofDrawBitmapStringHighlight(msg,50,50);
	if(var== 1) {
		
		string msg1="miammm that was delicious!!!!";
		ofDrawBitmapStringHighlight(msg1,50,100);
		var=0;
	}
	/*else if(var==2){
		string msg1="waiting for food!!!!";
		ofDrawBitmapStringHighlight(msg1,50,100);
		var=0;
	}*/
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == ' ') {
		alien.DecreaseAppetite();
		var=1;
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	/*if(key == ' ') {

		var=2;
	}*/

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}