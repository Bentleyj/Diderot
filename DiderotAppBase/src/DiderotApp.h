#pragma once

#include "ofMain.h"

#include "ofxNestedFileLoader.h"
#include "ofxGui.h"

class DiderotApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void stepLeft();
		void stepRight();

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

		vector<string> imagePaths;
		vector<ofImage*> images;
		ofxNestedFileLoader loader;
		int index;

		ofxPanel gui;
		
};