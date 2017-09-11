#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    setupGui();
    loadImages("Custom/");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(playing) {
        bool looped = false;
        looped = stepRight();
        if(looped) {
            playing = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(0, 0);
    gui.draw();
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), ofGetWidth() - 100, ofGetHeight() - 100);
}

//--------------------------------------------------------------
void ofApp::setupGui() {
    string settingsPath = "settings.xml";
    gui.setup("gui", settingsPath);
    gui.add(exposure.set("Exposure (s)", 300, 1, 600));
    gui.add(playing.set("Playing", false));
    gui.add(percent.set("Percent", 0, 0, 100));
    gui.add(negative.set("Negative", false));
    gui.add(scale.set("Scale", 1.26, 0.5, 10.0));
    gui.add(rotate.set("Rotate 90", false));
    gui.add(fullscreen.set("Fullscreen", false));
    gui.add(threshold.set("Threshold", 0.0, 0.0, 1.0));
    gui.add(contrast.set("Contrast", 1.0, 0.0, 20.0));
    gui.add(tint.set("Tint", ofColor(255, 205, 170)));
    // Do a custom folder
    ofParameter<bool> p;
    p.set("Custom/", false);
    foldersGroup.add(p);
    // Do the Supplements
    for (int i = 1; i < 6; i++) {
        ofParameter<bool> p;
        p.set("SUP" + ofToString(i) + "/", false);
        foldersGroup.add(p);
    }
    // Do the Volumes
    for (int i = 1; i < 29; i++) {
        ofParameter<bool> p;
        p.set("V" + ofToString(i) + "/", false);
        foldersGroup.add(p);
    }
    
    gui.add(foldersGroup);
    gui.loadFromFile(settingsPath);
    
    ofAddListener(foldersGroup.parameterChangedE(), this, &ofApp::onFolderChanged);
    exposure.addListener(this, &ofApp::onExposureChanged);
    playing.addListener(this, &ofApp::onPlayingChanged);
//    ofAddListener(foldersGroup.parameterChangedE(), this, &ofApp::onFolderChanged);
//    fullscreen.addListener(this, &ofApp::fullscreenChanged);
    
    ofSetVerticalSync(false);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') {
        loadImages("Custom/");
    }
    if(key == 's') {
        loadImages("SUP1/");
    }
    ofxDiderotApp::keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::onPlayingChanged(bool & val) {
    percent = 0;
    if(val) {
        ofSetFrameRate((float)fps);
    } else {
        ofSetFrameRate(60);
    }
    //index = 0;
    //image.load(imagePaths[0]);
}

//--------------------------------------------------------------
void ofApp::onFolderChanged(ofAbstractParameter &p) {
    string name = p.getName();
    for (auto it = foldersGroup.begin(); it != foldersGroup.end(); it++) {
        if (it->get()->getName() != name) {
            foldersGroup.getBool(it->get()->getName()).setWithoutEventNotifications(false);
            //it->get()->setWithoutEventNotification(false);
        }
        else {
            foldersGroup.getBool(it->get()->getName()).setWithoutEventNotifications(true);
        }
    }
    loadImages(name);
    numFiles = imagePaths.size();
    fps =  (float)numFiles / (float)exposure;
    cout << fps << endl;
    //    resetToBeginning();
}

//--------------------------------------------------------------
void ofApp::onExposureChanged(int & val) {
    fps = (float)numFiles / (float)val; // This is frames per second
    spf = (1.0 / fps);
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
