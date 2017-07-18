#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	string url;

	ofLogToFile("settings/settings.html", false);

	ofURLFileLoader loader;
	ofHttpResponse resp;
	string s;

	ofxXmlSettings t;
	t.addTag("Topics");
	t.pushTag("Topics");

	int p;
	for (int i = 0; i < 9999; i++) {
		t.addTag("Volume");
		t.pushTag("Volume");
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
				cout << "Found " + ofToString(i) + " " + ofToString(j) << endl;
				int textEnd = getTextPos(s, "</div>", p + 21);
				string text = s.substr(p + 21, textEnd - p - 21);
				int posOfHTMLStart = 0;
				int posOfHTMLEnd = 0;
				posOfHTMLStart = getTextPos(text, "<", 0);
				posOfHTMLEnd = getTextPos(text, ">", posOfHTMLStart);
				cout << text << endl;
				while (posOfHTMLStart != -1 && posOfHTMLEnd != -1) {
					string firstPart = text.substr(0, posOfHTMLStart);
					string secondPart = text.substr(posOfHTMLEnd+1, text.length());
					text = firstPart + secondPart;
					posOfHTMLStart = getTextPos(text, "<", 0);
					posOfHTMLEnd = getTextPos(text, ">", posOfHTMLStart);
				}
				t.addValue("Topic", text);
				t.saveFile("settings/text.xml");
			}
		}
		t.popTag();
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
	return s;
}

//--------------------------------------------------------------
int ofApp::getTextPos(string sIn, string sFor, int start = 0) {

	int pos = sIn.find(sFor, start);
	cout << "Found " << sFor << " at position: " << pos << endl;
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
