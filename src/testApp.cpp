#include "testApp.h"
AlienGotchi alien(ent_AlienGotchi);
//--------------------------------------------------------------
void testApp::setup(){
	var=0;
	ofBackground(155,125,205,0);
	// prepei na stamathsoume gt alliws den doulevei swsta
	myTimer_health.stopTimer();
	myTimer_hungry.stopTimer();
	myTimer_happy.stopTimer();

	count_time=0;
	myTimer_health.setup(3500,false);
	myTimer_hungry.setup(3000,false);
	myTimer_happy.setup(2000,false);

	// listen to any of the events for the game
	ofAddListener(myTimer_health.TIMER_REACHED,this,&testApp::timer1_ended);
	ofAddListener(myTimer_hungry.TIMER_REACHED,this,&testApp::timer2_ended);
	ofAddListener(myTimer_happy.TIMER_REACHED,this,&testApp::timer3_ended);
}

//--------------------------------------------------------------
void testApp::update(){
	alien.Update();
	//ofSleepMillis(800);
	//static TimeEvent newEvent;
	//ofNotifyEvent(TimeEvent::events, newEvent);
	//mills=theTime.getTimeLeftInMillis();
	//cout<<mills<<endl;
}

//--------------------------------------------------------------
void testApp::timer1_ended(ofEventArgs& e)
{
	if (myTimer_health.isTimerFinished())
	{
		currentMood=alien.Mood();
		if (currentMood==ill){
			//myTimer.stopTimer();
			//cout << "\n" <<  ": " << ++count_time << endl;
			alien.DecreaseFitness();
			//myTimer.setup(1000,false);
			
		}
		myTimer_health.startTimer();
	}

}
void testApp::timer2_ended(ofEventArgs& f)
{
	if (myTimer_hungry.isTimerFinished())
	{
		//myTimer.stopTimer();
		//cout << "\n" <<  ": " << ++count_time << endl;
		alien.IncreaseAppetite();
		//myTimer.setup(1000,false);
		myTimer_hungry.startTimer();
	}
}
void testApp::timer3_ended(ofEventArgs& g)
{
	if (myTimer_happy.isTimerFinished())
	{
		//myTimer.stopTimer();
		//cout << "\n" <<  ": " << ++count_time << endl;
		alien.DecreaseHappiness();
		//myTimer.setup(1000,false);
		myTimer_happy.startTimer();
	}
}
//--------------------------------------------------------------
void testApp::draw(){
	msg=alien.Message();
	ofSetColor(0x000000);
	ofDrawBitmapString("Hungry Timer: "+ofToString(myTimer_hungry.getTimeLeftInSeconds()),10,20+10);
	ofDrawBitmapString("Happy Timer: "+ofToString(myTimer_happy.getTimeLeftInSeconds()),10,40+10);
	ofDrawBitmapString("Happy Timer: "+ofToString(myTimer_health.getTimeLeftInSeconds()),10,60+10);
	//ofDrawBitmapStringHighlight(msg,50,50);
	ofDrawBitmapString(msg,ofGetWidth()/2,ofGetHeight()/2);
	/*if(var== 1) {
		
		//ofDrawBitmapStringHighlight("Miammm that was delicious!!!!",50,100);
		ofDrawBitmapString("Miammm that was delicious!!!!",ofGetWidth()/2,ofGetHeight()/2);
		var=0;
	}
	else if(var==2){

		ofDrawBitmapString("Sorry I am not hungry!!!!",ofGetWidth()/2,ofGetHeight()/2);
		var=0;
	}

	if (var==3)
	{
		ofDrawBitmapString("Yeees nice flying saucer... :D!!!!",ofGetWidth()/2,ofGetHeight()/2);
		var=0;
	} 
	else if(var==4)
	{
		ofDrawBitmapString("Not in a play mood...:((",ofGetWidth()/2,ofGetHeight()/2);
		var=0;
	}

	if (var==5)
	{
		ofDrawBitmapString("I am feeling sick... Please Help!!!! :(",ofGetWidth()/2,ofGetHeight()/2);
		var=0;
	} 
	else if(var==6)
	{
		ofDrawBitmapString("I am feeling fine!!! :))",ofGetWidth()/2,ofGetHeight()/2);
		var=0;
	}*/
	
	float barWidth = 200;
//------------------------------------------------------------------------------------------------------
	ofDrawBitmapString("AlienGotchi Hungry Level: ",ofGetWidth()-barWidth-300,20+10);

	// the background to the progress bar
	ofSetColor(100);
	ofRect(ofGetWidth()-barWidth-40, 20, barWidth, 10);

	if (alien.HungryLevel()<=Hungry_Thres_Down)
	{
		// get the percantage of the timer

		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 20, 4*alien.HungryLevel(), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HungryLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 20+10);  
	} 
	else if (alien.HungryLevel()>Hungry_Thres_Down && alien.HungryLevel()<=Hungry_Thres_Up)
	{
		// get the percantage of the timer
		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 20, 4*Hungry_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Hungry_Thres_Down), 20, (4*alien.HungryLevel())-(4*Hungry_Thres_Down), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HungryLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 20+10);  
	}
	else if (alien.HungryLevel()>Hungry_Thres_Up && alien.HungryLevel()<Hungry_MAX)
	{
		// get the percantage of the timer
		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 20, 4*Hungry_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Hungry_Thres_Down), 20, 4*(Hungry_Thres_Up - Hungry_Thres_Down), 10);
		ofSetHexColor(0xff0000);
		ofRect(ofGetWidth()-barWidth-40+(4*Hungry_Thres_Up), 20, (4*alien.HungryLevel())-(4*Hungry_Thres_Up), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HungryLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 20+10);  
	}
	else
	{
		// get the percantage of the timer

		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 20, 4*Hungry_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Hungry_Thres_Down), 20, 4*(Hungry_Thres_Up - Hungry_Thres_Down), 10);
		ofSetHexColor(0xff0000);
		ofRect(ofGetWidth()-barWidth-40+(4*Hungry_Thres_Up), 20, 4*(Hungry_MAX - Hungry_Thres_Up), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*50*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 20+10);
	}
//------------------------------------------------------------------------------------------------------
	ofDrawBitmapString("AlienGotchi Happy Level: ",ofGetWidth()-barWidth-300,40+10);

	// the background to the progress bar
	ofSetColor(100);
	ofRect(ofGetWidth()-barWidth-40, 40, barWidth, 10);

	if (alien.HappyLevel()<=Happy_Thres_Down)
	{
		// get the percantage of the timer

		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 40, 4*alien.HappyLevel(), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HappyLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 40+10);  
	} 
	else if (alien.HappyLevel()>Happy_Thres_Down && alien.HappyLevel()<=Happy_Thres_Up)
	{
		// get the percantage of the timer
		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 40, 4*Happy_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Happy_Thres_Down), 40, (4*alien.HappyLevel())-(4*Happy_Thres_Down), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HappyLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 40+10);  
	}
	else if (alien.HappyLevel()>Happy_Thres_Up && alien.HappyLevel()<Happy_MAX)
	{
		// get the percantage of the timer
		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 40, 4*Happy_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Happy_Thres_Down), 40, 4*(Happy_Thres_Up - Happy_Thres_Down), 10);
		ofSetHexColor(0xff0000);
		ofRect(ofGetWidth()-barWidth-40+(4*Happy_Thres_Up), 40, (4*alien.HappyLevel())-(4*Happy_Thres_Up), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HappyLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 40+10);  
	}
	else
	{
		// get the percantage of the timer

		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 40, 4*Happy_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Happy_Thres_Down), 40, 4*(Happy_Thres_Up - Happy_Thres_Down), 10);
		ofSetHexColor(0xff0000);
		ofRect(ofGetWidth()-barWidth-40+(4*Happy_Thres_Up), 40, 4*(Happy_MAX - Happy_Thres_Up), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*50*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 40+10);
	}
//------------------------------------------------------------------------------------------------------------------------
	ofDrawBitmapString("AlienGotchi Healthy Level: ",ofGetWidth()-barWidth-300,60+10);

	// the background to the progress bar
	ofSetColor(100);
	ofRect(ofGetWidth()-barWidth-40, 60, barWidth, 10);

	if (alien.HealthyLevel()<= Health_Thres_Down)
	{
		// get the percantage of the timer

		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 60, 4*alien.HealthyLevel(), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HealthyLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 60+10);  
	} 
	else if (alien.HealthyLevel()>Health_Thres_Down && alien.HealthyLevel()<=Health_Thres_Up)
	{
		// get the percantage of the timer
		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 60, 4*Health_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Health_Thres_Down), 60, (4*alien.HealthyLevel())-(4*Health_Thres_Down), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HealthyLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 60+10);  
	}
	else if (alien.HealthyLevel()>Health_Thres_Up && alien.HealthyLevel()<Healthy_MAX)
	{
		// get the percantage of the timer
		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 60, 4*Health_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Health_Thres_Down), 60, 4*(Health_Thres_Up - Health_Thres_Down), 10);
		ofSetHexColor(0xff0000);
		ofRect(ofGetWidth()-barWidth-40+(4*Health_Thres_Up), 60, (4*alien.HealthyLevel())-(4*Health_Thres_Up), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*alien.HealthyLevel()*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 60+10);  
	}
	else
	{
		// get the percantage of the timer

		ofSetHexColor(0x00ff00);
		ofRect(ofGetWidth()-barWidth-40, 60, 4*Health_Thres_Down, 10);
		ofSetHexColor(0x0000ff);
		ofRect(ofGetWidth()-barWidth-40+(4*Health_Thres_Down), 60, 4*(Health_Thres_Up - Health_Thres_Down), 10);
		ofSetHexColor(0xff0000);
		ofRect(ofGetWidth()-barWidth-40+(4*Health_Thres_Up), 60, 4*(Healthy_MAX - Health_Thres_Up), 10);

		// draw the percantage
		ofSetColor(20);
		ofDrawBitmapString(ofToString((4*50*100)/barWidth, 0)+"%", ofGetWidth()-40+10, 60+10);
	}
//------------------------------------------------------------------------------------------------------------------------
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	currentMood=alien.Mood();
	if(key =='f'){

		if (currentMood==hungry)
		{
			alien.DecreaseAppetite();
			//var=1;
		}
		else
		{
			//var=2;
		}
	}

	if(key =='p') {

		if (currentMood==playful)
		{
			alien.IncreaseHappiness();
			//var=3;
		}
		else
		{
			//var=4;
		}
	}

	if(key =='h') {

		if (currentMood==ill)
		{
			alien.IncreaseFitness();
			//var=5;
		}
		else
		{
			//var=6;
		}
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