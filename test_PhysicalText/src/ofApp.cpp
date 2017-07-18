#include "ofApp.h"

#define NUM_MESHES 9

//--------------------------------------------------------------
void ofApp::setup(){

	int numMeshes = NUM_MESHES;

	int width = 50;
	int height = 50;
	int depth = 300;

	meshes.resize(numMeshes);
	scales.resize(numMeshes);
	scaleTargets.resize(numMeshes);


	for (int j = 0; j < numMeshes; j++) {
		meshes[j].setMode(OF_PRIMITIVE_POINTS);
		for (int i = 0; i < 10000; i++) {
			ofVec3f p;
			p.x = ofRandom(-width, width);
			p.y = ofRandom(-height, height);
			p.z = ofRandom(-depth, depth);

			meshes[j].addVertex(p);
			meshes[j].addColor(ofRandom(127, 255));
		}
		scales[j] = ofMap(j, 0, numMeshes, 1, 10);
		scaleTargets[j] = 1;
	}

	ofBackground(0);

	post.init(ofGetWidth(), ofGetHeight());
	post.createPass<BloomPass>()->setEnabled(true);

	ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < NUM_MESHES; i++) {
		scales[i] = ofLerp(scales[i], scaleTargets[i], 0.1);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	post.begin(cam);
	for (int i = 0; i < NUM_MESHES; i++) {
		ofPushMatrix();
		ofScale(scales[i], scales[i], scales[i]);
		meshes[i].draw();
		ofPopMatrix();
	}
	post.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') {
		if (scaleTargets[0] == 20) {
			scaleTargets[0] = 1;
		}
		else {
			scaleTargets[0] = 20;
		}
	}
	if (key == '2') {
		if (scaleTargets[1] == 20) {
			scaleTargets[1] = 1;
		}
		else {
			scaleTargets[1] = 20;
		}
	}
	if (key == '3') {
		if (scaleTargets[2] == 20) {
			scaleTargets[2] = 1;
		}
		else {
			scaleTargets[2] = 20;
		}
	}
	if (key == '4') {
		if (scaleTargets[3] == 20) {
			scaleTargets[3] = 1;
		}
		else {
			scaleTargets[3] = 20;
		}
	}
	if (key == '5') {
		if (scaleTargets[4] == 20) {
			scaleTargets[4] = 1;
		}
		else {
			scaleTargets[4] = 20;
		}
	}
	if (key == '6') {
		if (scaleTargets[5] == 20) {
			scaleTargets[5] = 1;
		}
		else {
			scaleTargets[5] = 20;
		}
	}
	if (key == '7') {
		if (scaleTargets[6] == 20) {
			scaleTargets[6] = 1;
		}
		else {
			scaleTargets[6] = 20;
		}
	}
	if (key == '8') {
		if (scaleTargets[7] == 20) {
			scaleTargets[7] = 1;
		}
		else {
			scaleTargets[7] = 20;
		}
	}
	if (key == '9') {
		if (scaleTargets[8] == 20) {
			scaleTargets[8] = 1;
		}
		else {
			scaleTargets[8] = 20;
		}
	}
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
