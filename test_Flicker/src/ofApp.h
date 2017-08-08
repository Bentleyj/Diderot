#pragma once

#include "ofMain.h"
#include "ofxDiderotApp.h"
#include "ofxCv.h"

class ofApp : public ofxDiderotApp{

	public:
		void setup();
		void setupGui();
		void update();
		void draw();
		void drawGui(ofEventArgs & args);

		void exposureChanged(int & val);
		void playingChanged(bool & val);
		void onFolderChanged(ofAbstractParameter &p);

		void keyPressed(int key);
		void keyPressed(ofKeyEventArgs & args);
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
		ofParameter<bool> rotate;
		ofParameter<bool> thresholdOn;
		ofParameter<float> threshold;
		vector<ofParameter<bool>> folders;

		ofFbo buff;

		ofParameterGroup foldersGroup;

		float playDuration;

		ofSoundPlayer player;

		float timeOfLastStep;

		int numFiles;

		float fps;

		ofShader negativeEffect;
};
