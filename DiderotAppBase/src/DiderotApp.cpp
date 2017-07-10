#include "DiderotApp.h"

//--------------------------------------------------------------
void DiderotApp::setup(){
	int numImages = 3;

	string settingsPath = "settings/settings.xml";
	gui.setup("gui", settingsPath);
	gui.add(index.set("Image Index", 0, 0, numImages-1));
	gui.loadFromFile(settingsPath);

	string imagesRoot = "../../DiderotData/";
	ofSetDataPathRoot(imagesRoot);

	cout << "Starting to load Paths: " << ofGetElapsedTimef() << endl;
	vector<string> imagePaths = loader.load("", "jpeg");
	cout << "End Load Paths" << ofGetElapsedTimef() << endl;
	cout << "We loaded " << imagePaths.size() << " images."<< endl;

	if (numImages > imagePaths.size())
		numImages = imagePaths.size();

	cout << "Starting to load " << numImages << " images at " <<ofGetElapsedTimef() << " seconds from the start of the app." << endl;

	for (int i = 0; i < numImages; i++) {
		ofImage img;
		img.load(imagePaths[i]);
		images.push_back(img);
	}

	cout << "Finished loading " << numImages << " images at " << ofGetElapsedTimef() << " seconds from the start of the app." << endl;

	//ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void DiderotApp::update(){

}

//--------------------------------------------------------------
void DiderotApp::draw(){
	gui.draw();
	ofTranslate(ofGetWidth() / 2 - images[index].getWidth() / 2, ofGetHeight() / 2 - images[index].getHeight() / 2);
	images[index].draw(0, 0);
}

//--------------------------------------------------------------
void DiderotApp::stepLeft() {
	index--;
}

//--------------------------------------------------------------
void DiderotApp::stepRight() {

}

//--------------------------------------------------------------
void DiderotApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		stepLeft();
	}
	else if (key == OF_KEY_RIGHT) {
		stepRight();
	}
}

//--------------------------------------------------------------
void DiderotApp::keyReleased(int key){

}

//--------------------------------------------------------------
void DiderotApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void DiderotApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void DiderotApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void DiderotApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void DiderotApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void DiderotApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void DiderotApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void DiderotApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void DiderotApp::dragEvent(ofDragInfo dragInfo){ 

}
