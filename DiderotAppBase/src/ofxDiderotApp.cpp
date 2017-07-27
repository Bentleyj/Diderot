#include "ofxDiderotApp.h"

//--------------------------------------------------------------
void ofxDiderotApp::setup(){

	loadImages("SUP1/");

	image.load(imagePaths[0]);
	index = 0;
	//ofSetRectMode(OF_RECTMODE_CENTER);
}

void ofxDiderotApp::loadImages(string path) {
	string imagesRoot = "../../DiderotData/" + path;
	ofSetDataPathRoot(imagesRoot);

	imagePaths.clear();
	loader.clearPaths();
	cout << "Starting to load Paths: " << ofGetElapsedTimef() << endl;
	imagePaths = loader.load("", "jpeg");
	cout << "End Load Paths: " << ofGetElapsedTimef() << endl;
	cout << "We loaded " << imagePaths.size() << " images." << endl;

	if (imagePaths.size() > 0) {
		image.load(imagePaths[0]);
	}
	else {
		cout << "ofxDidertoApp::loadImaegs [Error] Path: " + imagesRoot + " contained no jpeg files." << endl;
	}
}

//--------------------------------------------------------------
void ofxDiderotApp::update(){
	stepRight();
}

//--------------------------------------------------------------
void ofxDiderotApp::draw(){
	ofPushMatrix();
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	image.draw(0, 0);
	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofxDiderotApp::stepLeft() {
	index--;
	index %= imagePaths.size();	
	//cout << indexToLoad << ": " << imagePaths[indexToLoad] << endl;
	image.load(imagePaths[index]);

}

//--------------------------------------------------------------
void ofxDiderotApp::stepRight() {
	index++;
	index %= imagePaths.size();
	//cout << indexToLoad << ": " << imagePaths[indexToLoad] << endl;
	image.load(imagePaths[index]);
}

//--------------------------------------------------------------
void ofxDiderotApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		stepLeft();
	}
	else if (key == OF_KEY_RIGHT) {
		stepRight();
	}
}

//--------------------------------------------------------------
void ofxDiderotApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxDiderotApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofxDiderotApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofxDiderotApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofxDiderotApp::dragEvent(ofDragInfo dragInfo){ 

}
