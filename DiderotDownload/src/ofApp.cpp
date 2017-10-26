#include "ofApp.h"

// Here's an example URL that we want to fetch a p[age from:
// http://artflsrv02.uchicago.edu/images/encyclopedie/V1/ENC_1-1.jpeg
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// for the Fuplements the format is like this:
// http://artflsrv02.uchicago.edu/images/encyclopedie/SUP1/01_0002.jpg
// +++++++++++++++++

string pad(string num) {
	while (num.size() < 3) {
		num = "0" + num;
	}
	return num;
}

string convertToRN(int index) {
	switch (index) {
		case 1:
			return "i";
			break;
		case 2:
			return "ii";
			break;
		case 3:
			return "iii";
			break;
		case 4:
			return "iiij";
			break;
		case 5:
			return "iij";
			break;
		case 6:
			return "ij";
			break;
		case 7:
			return "iv";
			break;
		case 8:
			return "ix";
			break;
		case 9:
			return "jx";
			break;
		case 10:
			return "v";
			break;
		case 11:
			return "vi";
			break;
		case 12:
			return "vii";
			break;
		case 13:
			return "viii";
			break;
		case 14:
			return "viij";
			break;
		case 15:
			return "vij";
			break;
		case 16:
			return "vj";
			break;
		case 17:
			return "x";
			break;
		case 18:
			return "xi";
			break;
		case 19:
			return "xii";
			break;
		case 20:
			return "xiii";
			break;
		case 21:
			return "xiij";
			break;
		case 22:
			return "xij";
			break;
		case 23:
			return "xiv";
			break;
		case 24:
			return "xj";
			break;
		case 25:
			return "xjv";
			break;
		default :
			return "";
			break;
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
    //https://www.bl.uk/TreasuresImages/gutenberg/max/kl1/324_v.jpg
	baseURL = "https://www.bl.uk/TreasuresImages/gutenberg/max/kl"; //1/ENC_1-1.jpeg";
	ofLogToFile("Progress.txt");
	volumeIndex = 1;
	pageIndex = 1;
	pad(ofToString(pageIndex));
	bool downloading = true;
	while (downloading) {
		string URL = baseURL + ofToString(volumeIndex) + "/" + pad(ofToString(pageIndex)) + "_v.jpg";
		string path = "Gutenberg/V" + ofToString(volumeIndex) + "/V" + ofToString(volumeIndex) + "F" + ofToString(pageIndex) + "_v.jpg";
		ofHttpResponse resp = loader.saveTo(URL, path);
		pageIndex++;
		if (resp.error != "OK") {

			cout << "Error saving file from: " + URL << endl;
			cout << "to: " + URL << endl;
			cout << "Error: " + resp.error << endl;
			cout << "This means there are " + ofToString(pageIndex) + " files in Volume " + ofToString(volumeIndex) << endl;

			ofLog() << "Error saving file from: " + URL;
			ofLog() << "to: " + URL;
			ofLog() << "Error: " + resp.error;
			ofLog() << "This means there are " + ofToString(pageIndex) + " files in Volume " + ofToString(volumeIndex);
			pageIndex = 1;
			volumeIndex++;
		}
		else {
			cout << "File saved successfully to: " + path << endl;
			ofLog() << "File saved successfully to: " + path;
		}
		if (volumeIndex > 2) {
			downloading = false;
			cout << "Download complete!" << endl;
			ofLog() << "Download complete!";
		}

		//ofExit();
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
