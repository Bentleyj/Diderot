#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	player.load("sounds/alarm.wav");
	player.setLoop(false);

	negativeEffect.load("shaders/negative");

	ofxDiderotApp::setup();

	numFiles = imagePaths.size();
	fps = numFiles / exposure;

	ofSetBackgroundAuto(false);

	timeOfLastStep = ofGetElapsedTimef();

	buff.allocate(ofGetWidth(), ofGetHeight());
    
    index = 0;
    
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::setupGui() {
	string settingsPath = "settings.xml";
	gui.setup("gui", settingsPath);
	gui.add(exposure.set("Exposure (s)", 300, 1, 600));
	gui.add(playing.set("Playing", false));
	gui.add(percent.set("Percent", 0, 0, 100));
	gui.add(negative.set("Negative", false));
	gui.add(scale.set("Scale", 1.26, 0.5, 10.0));
	gui.add(rotate.set("Rotate 90", false));
	gui.add(fullscreen.set("Fullscreen", false));
	gui.add(threshold.set("Threshold", 0.0, 0.0, 1.0));
    gui.add(contrast.set("Contrast", 1.0, 0.0, 20.0));
    gui.add(tint.set("Tint", ofColor(255, 205, 170)));
    // Do a custom folder
    ofParameter<bool> p;
    p.set("Custom/", false);
    foldersGroup.add(p);
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
    fullscreen.addListener(this, &ofApp::fullscreenChanged);
    
    ofSetVerticalSync(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (playing) {
		playDuration += ofGetLastFrameTime();
        percent = ofMap(playDuration, 0, (numFiles)/fps, 0, percent.getMax());
		if (index == numFiles - 1) {
			playing = false;
			player.play();
		} else if (playDuration - timeOfLastStep >= (1.0 / fps)) {
			stepRight();
			timeOfLastStep = playDuration;
		}
        cout<<index<<endl;
	}
	else {
		timeOfLastStep = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (negative)
		ofSetColor(0);
	else
		ofSetColor(tint.get()*convertColorToUniformRange(tint).w);

	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255);
	ofPushMatrix();
	if (rotate) {
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
		ofRotateZ(90);
		ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
	}
	negativeEffect.begin();
	negativeEffect.setUniformTexture("diffuseTexture", image.getTexture(), 0);
	negativeEffect.setUniform1f("negative", (negative) ? 1 : 0);
	negativeEffect.setUniform1f("scale", scale);
	negativeEffect.setUniform1f("thresh", threshold);
    negativeEffect.setUniform4f("tint", convertColorToUniformRange(tint));
    negativeEffect.setUniform1f("contrast", contrast);
	ofTranslate(ofGetWidth() / 2 - image.getWidth() / 2 * scale, ofGetHeight() / 2 - image.getHeight() / 2 * scale);
	ofDrawRectangle(0, 0, image.getWidth() * scale, image.getHeight() * scale);
	negativeEffect.end();
   // image.draw(0, 0, image.getWidth() * scale, image.getHeight() * scale);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawGui(ofEventArgs & args) {
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

	ofPushMatrix();
	//ofScale(0.5, 0.5);
	ofPopMatrix();
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
		playDuration = 0;
	}
}

//--------------------------------------------------------------
void ofApp::fullscreenChanged(bool & val) {
    ofToggleFullscreen();
}

//--------------------------------------------------------------
ofVec4f ofApp::convertColorToUniformRange(ofColor col) {
    float r = ofMap(col.r, 0, 255, 0, 1);
    float g = ofMap(col.g, 0, 255, 0, 1);
    float b = ofMap(col.b, 0, 255, 0, 1);
    float a = ofMap(col.a, 0, 255, 0, 1);
    
    return ofVec4f(r, g, b, a);

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
    resetToBeginning();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'g') {
		ofShowCursor();
	}
	if (key == 'f') {
		ofToggleFullscreen();
	}
	ofxDiderotApp::keyPressed(key);
}

void ofApp::keyPressed(ofKeyEventArgs & args) {
    if (args.key == 'g') {
        ofShowCursor();
    }
    if (args.key == 'f') {
        ofToggleFullscreen();
    }
	ofxDiderotApp::keyPressed(args.key);
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
	buff.allocate(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
