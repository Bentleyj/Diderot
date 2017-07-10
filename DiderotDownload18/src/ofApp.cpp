#include "ofApp.h"

// Here's an example URL that we want to fetch a page from:
// http://artflsrv02.uchicago.edu/images/encyclopedie/V26/ENC_26-1-3.jpeg
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//--------------------------------------------------------------
void ofApp::setup() {
	baseURL = "http://artflsrv02.uchicago.edu/images/encyclopedie/V"; //1/ENC_1-1.jpeg";
	ofLogToFile("Progress.txt");
	volumeIndex = 18;
	pageIndex = 1;
	middleIndex = 0;
	bool downloading = true;
	while (downloading) {
		string URL = baseURL + ofToString(volumeIndex) + "/plate_" + ofToString(volumeIndex) + "_" + ofToString(middleIndex) + "_" + ofToString(pageIndex) + ".jpeg";
		string path = "PlateV" + ofToString(volumeIndex) + "M" + ofToString(middleIndex) + "P" + ofToString(pageIndex) + ".jpeg";
		ofHttpResponse resp = loader.saveTo(URL, path);
		pageIndex++;
		if (resp.error != "OK") {

			cout << "Error saving file from: " + URL << endl;
			cout << "to: " + URL << endl;
			cout << "Error: " + resp.error << endl;

			ofLog() << "Error saving file from: " + URL;
			ofLog() << "to: " + URL;
			ofLog() << "Error: " + resp.error;

			pageIndex = 1;
			middleIndex++;
		}
		else {
			cout << "File saved successfully to: " + path << endl;
			ofLog() << "File saved successfully to: " + path;

		}
		if (middleIndex > 35) {
			middleIndex = 0;
			pageIndex = 0;
			volumeIndex++;
		}
		if (volumeIndex > 28) {
			downloading = false;
			cout << "Download complete!" << endl;
			ofLog() << "Download complete!";
		}

		ofExit();
	}
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
