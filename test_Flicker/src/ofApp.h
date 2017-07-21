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
		void onFolderChanged(ofAbstractParameter &p);

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
		ofParameter<bool> negative;
		ofParameter<float> scale;
		vector<ofParameter<bool>> folders;

		ofParameterGroup foldersGroup;

		float playDuration;

		ofSoundPlayer player;

		float timeOfLastStep;

		int numFiles;

		bool drawGui;

		float fps;

		ofShader negativeEffect;
};
