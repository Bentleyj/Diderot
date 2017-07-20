#pragma once

#include "ofMain.h"
#include "ofxDiderotApp.h"

class ofApp : public ofxDiderotApp{

	public:
		void setup();
		void update();
		void draw();

		void exposureChanged(int & val);
		void playingChanged(bool & val);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofParameter<int> exposure;
		ofParameter<bool> playing;
		ofParameter<float> percent;

		int timeOfLastStepMillis;

		int numFiles;

		bool drawGui;

		float fps;
		
};
