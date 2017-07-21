#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	player.load("sounds/alarm.wav");
	player.setLoop(false);

	negativeEffect.load("shaders/negative");

	ofxDiderotApp::setup();

	string settingsPath = "settings/settings.xml";
	gui.setup("gui", settingsPath);
	gui.add(exposure.set("Exposure (s)", 30, 1, 600));
	gui.add(playing.set("Playing", false));
	gui.add(percent.set("Percent", 0, 0, 100));
	gui.add(negative.set("Negative", false));
	// Do the Supplements
	for (int i = 1; i < 6; i++) {
		ofParameter<bool> p;
		p.set("SUP" + ofToString(i) + "/", false);
		foldersGroup.add(p);
	}
	// Do the Volumes
	for (int i = 1; i < 29; i++) {
		ofParameter<bool> p;
		p.set("V" + ofToString(i) + "/", false);
		foldersGroup.add(p);
	}
	gui.add(foldersGroup);
	gui.loadFromFile(settingsPath);

	exposure.addListener(this, &ofApp::exposureChanged);
	playing.addListener(this, &ofApp::playingChanged);
	ofAddListener(foldersGroup.parameterChangedE(), this, &ofApp::onFolderChanged);

	numFiles = imagePaths.size();
	fps = numFiles / exposure;

	ofSetBackgroundAuto(false);

	drawGui = true;

	timeOfLastStep = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (playing) {
		playDuration += ofGetLastFrameTime();
		if (index >= numFiles - 1) {
			cout << "Time to stop playing!" << endl;
			playing = false;
			player.play();
		}
		if (playDuration - timeOfLastStep >= (1.0 / fps)) {
			stepRight();
			timeOfLastStep = playDuration;
			percent = ofMap(index, 0, numFiles, 0, percent.getMax());
		}
	}
	else {
		timeOfLastStep = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255);
	ofPushMatrix();
	if (negative) {
		negativeEffect.begin();
		ofxDiderotApp::draw();
		negativeEffect.end();
	}
	else {
		ofxDiderotApp::draw();
	}
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
		ofDrawBitmapStringHighlight("Play Duration: " + ofToString(playDuration), x, y);
		y += 20;
		ofDrawBitmapStringHighlight("Time Between Swaps: " + ofToString((1.0 / fps * 1000.0)), x, y);
		y += 20;
	}

}

//--------------------------------------------------------------
void ofApp::exposureChanged(int & val) {
	fps = (float)numFiles / (float)val; // This is frames per second
}

//--------------------------------------------------------------
void ofApp::playingChanged(bool & val) {
	index = 0;
	percent = 0;
	if (val) {
		ofHideCursor();
		playDuration = 0;
		drawGui = false;
	}
	else {
		ofShowCursor();
		drawGui = true;
	}
}

//--------------------------------------------------------------
void ofApp::onFolderChanged(ofAbstractParameter &p) {
	string name = p.getName();
	for (auto it = foldersGroup.begin(); it != foldersGroup.end(); it++) {
		if (it->get()->getName() != name) {
			foldersGroup.getBool(it->get()->getName()).setWithoutEventNotifications(false);
			//it->get()->setWithoutEventNotification(false);
		}
		else {
			foldersGroup.getBool(it->get()->getName()).setWithoutEventNotifications(true);
		}
	}
	loadImages(name);
	index = 0;
	numFiles = imagePaths.size();
	fps = (float)numFiles / (float)exposure;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGui = !drawGui;
		ofShowCursor();
	}
	if (key == 'f') {
		ofToggleFullscreen();
	}
	ofxDiderotApp::keyPressed(key);
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
