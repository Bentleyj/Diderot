#include "ofApp.h"

// Here's an example URL that we want to fetch a p[age from:
// http://artflsrv02.uchicago.edu/images/encyclopedie/V1/ENC_1-1.jpeg
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// for the Fuplements the format is like this:
// http://artflsrv02.uchicago.edu/images/encyclopedie/SUP1/01_0002.jpg
// +++++++++++++++++

string pad(string num) {
	while (num.size() < 4) {
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
    //https://ia800207.us.archive.org/BookReader/BookReaderImages.php?zip=/22/items/oed01arch/oed01arch_jp2.tar&file=oed01arch_jp2/oed01arch_0025.jp2
	//https://ia800203.us.archive.org/BookReader/BookReaderImages.php?zip=/2/items/oed04arch/oed04arch_jp2.tar&file=oed04arch_jp2/oed04arch_0133.jp2
	//https://ia800204.us.archive.org/BookReader/BookReaderImages.php?zip=/10/items/oed03arch/oed03arch_jp2.tar&file=oed03arch_jp2/oed03arch_0647.jp2
	//https://ia800203.us.archive.org/BookReader/BookReaderImages.php?zip=/30/items/oed02arch/oed02arch_jp2.zip&file=oed02arch_jp2/oed02arch_0363.jp2

	baseURL = "https://ia800203.us.archive.org/BookReader/BookReaderImages.php?zip=/2/items/oed04arch/oed04arch_jp2.tar&file=oed04arch_jp2/oed04arch_"; //0025.jp2";
	ofLogToFile("Progress.txt");
	volumeIndex = 1;
	pageIndex = 216;
	pad(ofToString(pageIndex));
	bool downloading = true;
	while (downloading) {
		string URL = baseURL + pad(ofToString(pageIndex)) + ".jp2";
		string path = "OED/FG/"+ pad(ofToString(pageIndex)) + ".jpg";
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
		if (volumeIndex > 1) {
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
