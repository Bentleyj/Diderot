#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofxDiderotApp::setup();

	string settingsPath = "settings/settings.xml";
	gui.setup("gui", settingsPath);
	gui.add(exposure.set("Exposure (s)", 30, 1, 600));
	gui.add(playing.set("Playing", false));
	gui.add(percent.set("Percent", 0, 0, 100));
	gui.loadFromFile(settingsPath);

	exposure.addListener(this, &ofApp::exposureChanged);
	playing.addListener(this, &ofApp::playingChanged);

	numFiles = imagePaths.size();
	fps = numFiles / exposure;

	ofSetBackgroundAuto(false);

	drawGui = true;

	timeOfLastStepMillis = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (playing) {
		if (index > numFiles - 1) {
			cout << "Time to stop playing!" << endl;
			playing = false;
		}
		cout << (1.0 / fps * 1000.0) << endl;
		if (ofGetElapsedTimeMillis() - timeOfLastStepMillis >= (1.0 / fps * 1000.0)) {
			stepRight();
			timeOfLastStepMillis = ofGetElapsedTimeMillis();
			percent = ofMap(index, 0, numFiles, 0, 100);
		}

	}
	else {
		timeOfLastStepMillis = ofGetElapsedTimeMillis();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255);
	ofPushMatrix();
	ofxDiderotApp::draw();
	ofPopMatrix();

	if (drawGui) {
		gui.draw();
		ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), ofGetWidth() - 100, ofGetHeight() - 100);
		int y = 20;
		int x = gui.getPosition().x + gui.getWidth() + 10;
		ofDrawBitmapStringHighlight("FPS: " + ofToString(fps), x, y);
		y += 20;
		ofDrawBitmapStringHighlight("Num Files: " + ofToString(numFiles), x, y);
		y += 20;

	}

}

//--------------------------------------------------------------
void ofApp::exposureChanged(int & val) {
	cout << "Changing!" << endl;
	fps = (float)numFiles / (float)val; // This is frames per second
}

//--------------------------------------------------------------
void ofApp::playingChanged(bool & val) {
	index = 0;
	percent = 0;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGui = !drawGui;
	}
	if (key == 'f') {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
