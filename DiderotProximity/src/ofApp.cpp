#include "ofApp.h"

/*
    If you are struggling to get the device to connect ( especially Windows Users )
    please look at the ReadMe: in addons/ofxKinect/README.md
*/

//--------------------------------------------------------------
void ofApp::setup() {
    DiderotApp::setup();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	// enable depth->video image calibration
	kinect.setRegistration(true);
    
	//kinect.init();
	//kinect.init(true); // shows infrared instead of RGB video image
	kinect.init(false, false); // disable video image (faster fps)
	
	kinect.open();		// opens first available kinect
	//kinect.open(1);	// open a kinect by id, starting with 0 (sorted by serial # lexicographically))
	//kinect.open("A00362A08602047A");	// open a kinect using it's unique serial #
	
	// print the intrinsic IR sensor values
	if(kinect.isConnected()) {
		ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
		ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
		ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
		ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
	}
	
#ifdef USE_TWO_KINECTS
	kinect2.init();
	kinect2.open();
#endif
    
    string settingsPath = "settings/settings.xml";
	
    gui.setup("Controls", settingsPath);
    gui.add(minDepthStepToTriggerNewPage.set("Page Step", 0.5, 0.0001, 2));
    gui.loadFromFile(settingsPath);

//    gui.add(nearThreshold.set("Near Thresh", 230, 0, 400));
//    gui.add(farThreshold.set("Far Thresh", 70, 0, 400));
	
	ofSetFrameRate(60);

    depthFinder.setup(kinect.width, kinect.height);
    }

//--------------------------------------------------------------
void ofApp::update() {
    float diff = depthFinder.getCurrentAverageDepth() - depthFinder.getRunningAverageDepth();
    if(abs(diff) > minDepthStepToTriggerNewPage) {
        if(diff > 0) {
            stepLeft();
        } else {
            stepRight();
        }
    }
        
    depthFinder.updateAverageDepth(&kinect);
	
	ofBackground(100, 100, 100);
	
	kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    DiderotApp::draw();
    float width = depthFinder.image.getWidth();
    float height = depthFinder.image.getHeight();

    depthFinder.debugDraw(ofGetWidth() - width/2, ofGetHeight() - height/2, width/2, height/2);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::drawPointCloud() {
	int w = 640;
	int h = 480;
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_POINTS);
	int step = 2;
	for(int y = 0; y < h; y += step) {
		for(int x = 0; x < w; x += step) {
			if(kinect.getDistanceAt(x, y) > 0) {
				mesh.addColor(kinect.getColorAt(x,y));
				mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
			}
		}
	}
	glPointSize(3);
	ofPushMatrix();
	// the projected points are 'upside down' and 'backwards' 
	ofScale(1, -1, -1);
	ofTranslate(0, 0, -1000); // center the points a bit
	ofEnableDepthTest();
	mesh.drawVertices();
	ofDisableDepthTest();
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit() {
	kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();
}

//--------------------------------------------------------------
//void ofApp::keyPressed (int key) {
//    DiderotApp::keyPressed(key);
//}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}
