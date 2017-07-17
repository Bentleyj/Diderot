#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	string url;

	ofLogToFile("settings/settings.html", false);

	ofURLFileLoader loader;
	ofHttpResponse resp;
	string s;

	ofxXmlSettings settings;

	int p;
	for (int i = 0; i < 9999; i++) {
		for (int j = 0; j < 999; j++) {
			url = getURL(i, j);
			resp = loader.get(url);
			s = resp.data.getText();
			p = getTextPos(s, "doccontent", 0);
			if (p == -1) {
				// Skip it! it's a fialeld lookup.
			}
			else {
				// We got a page!
				int end = getTextPos(s, "</div>", p + 21);
				int index = p + 21;
				while (index < end) {
					cout << s[index];
					index++;
				}

			}
		}
	}
}

//--------------------------------------------------------------
string ofApp::pad4(int val) {
	string s = ofToString(val);
	int l = s.length();
	switch (l) {
		case 1:
			return "000" + s;
			break;
		case 2:
			return "00" + s;
			break;
		case 3:
			return "0" + s;
			break;
		case 4:
			return s;
		default:
			cout << "Something has gone wrong in pad4!" << endl;
			return "";
	}
}

//--------------------------------------------------------------
string ofApp::pad3(int val) {
	string s = ofToString(val);
	int l = s.length();
	switch (l) {
		case 1:
			return "00" + s;
			break;
		case 2:
			return "0" + s;
			break;
		case 3:
			return s;
		default:
			cout << "Something has gone wrong in pad3!" << endl;
			return "";
	}
}

//--------------------------------------------------------------
string ofApp::getURL(int i1, int i2) {
	string s = "https://quod.lib.umich.edu/cgi/t/text/text-idx?c=did;cc=did;rgn=main;view=text;idno=did2222." + pad4(i1) + "." + pad3(i2);
	cout << s << endl;
	return s;
}

//--------------------------------------------------------------
int ofApp::getTextPos(string sIn, string sFor, int start = 0) {

	int pos = sIn.find(sFor, start);

	return pos;
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
