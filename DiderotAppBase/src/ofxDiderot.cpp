#include "ofxDiderot.h"

//--------------------------------------------------------------
void DiderotApp::setup(){

	string settingsPath = "settings/settings.xml";
	gui.setup("gui", settingsPath);
	gui.loadFromFile(settingsPath);
    
	string imagesRoot = "../../../DiderotData/";
	//ofSetDataPathRoot(imagesRoot);

	cout << "Starting to load Paths: " << ofGetElapsedTimef() << endl;
	imagePaths = loader.load(imagesRoot);
	cout << "End Load Paths " << ofGetElapsedTimef() << endl;
	cout << "We loaded " << imagePaths.size() << " images."<< endl;

	images.resize(3);

	for (int i = 0; i < images.size(); i++) {
		images[i] = new ofImage();
	}
    if(imagePaths.size() > 0) {
        
        images[0]->load(imagePaths[imagePaths.size() - 1]);
        images[1]->load(imagePaths[0]);
        images[2]->load(imagePaths[1]);
        
        index = 1;
    }


	//ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void DiderotApp::update(){
	//stepRight();
}

//--------------------------------------------------------------
void DiderotApp::draw(){
	ofTranslate(ofGetWidth() / 2 - images[1]->getWidth() / 2, ofGetHeight() / 2 - images[1]->getHeight() / 2);
	images[1]->draw(0, 0);
}

//--------------------------------------------------------------
void DiderotApp::stepLeft() {
	images[2] = images[1];
	images[1] = images[0];
	int indexToLoad = (index - 2) % imagePaths.size();
	//cout << indexToLoad << ": " << imagePaths[indexToLoad] << endl;
	images[0]->load(imagePaths[indexToLoad]);
	index--;
	index %= imagePaths.size();
}

//--------------------------------------------------------------
void DiderotApp::stepRight() {
	images[0] = images[1];
	images[1] = images[2];
	int indexToLoad = (index + 2) % imagePaths.size();
	//cout << indexToLoad << ": " << imagePaths[indexToLoad] << endl;
	images[2]->load(imagePaths[indexToLoad]);
	index++;
	index %= imagePaths.size();
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
