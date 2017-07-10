#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofxNestedFileLoader loader;
	string path = "C:\\Users\\Flowers\\Documents\\of_v0.9.3_vs_release\\apps\\Diderot\\DiderotData\\V1";
	vector<string> paths = loader.load(path);

	//for (int j = 0; j < paths.size(); j++) {
		string myPath = paths[0];
		buff = ofBufferFromFile(myPath, true);

		char * data = buff.getData();
		//for (int i = 0; i < buff.size(); i++) {
		//	cout << data[i] << endl;
		//}
		cout << buff.size() << endl;

		float numColors = buff.size();

		pix.allocate(sqrt(buff.size()), sqrt(buff.size()), OF_IMAGE_GRAYSCALE);

		for (int i = 0; i < numColors; i++) {
			ofColor col;
			col.r = data[i];
			col.g = data[i];
			col.b = data[i];
			pix.setColor(i, col);
		}

		rep.setFromPixels(pix);

		//img = ofImage(path);
	//}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofScale(2, 2);
	rep.draw(0, 0);
	//img.draw(0, 0);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
