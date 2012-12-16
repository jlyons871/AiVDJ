#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "beatDetect.h"
#include "ofxColourTheory.h"

#include "alex/physicsMode.h"
#include "alex/vidMode.h"
//#include "jake/djMode.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		/*-----------util-----------*/
		int mouseX, mouseY;

		/*-----------GUI-----------*/
		enum MODE{
			DJ,
			AUD,
			PHYSICS,
			VID
		};

		void guiSetup();
		void guiColors(ofxUIWidget *w);
		void guiEvent(ofxUIEventArgs &e);
		void initRects();
		void changeColorScheme(std::string d);
		void exit();

		ofxUICanvas *gui;
		float guiWidth, guiHeight;
		float slider1, slider2;
		bool drawDJ, drawAud, drawDisplay, drawSound;
		bool drawDJKinect, drawAudKinect;
		ofColor cmain, ccomp1, ccomp2, ccomp3, ccomp4, ccomp5, white;
		ofRectangle displayRect, djRect, audRect, guiRect;

		MODE mode;

		/*-----------Alex-----------*/
		//Physics
		physicsMode physics;
		int numParticles;

		//Video
		vidMode vid;
		int vidX;
		int vidY;

		//Color Stuff
		vector<ofColor> colors;
		ofxColourTheory colorGen;
		ColourConstraints curShade;

		vector<pair<ColourShade,string>> color_options;

		void generateColors(ColourShade seed);
		void drawColorSwatches(int x, int y);
		/*-----------Jake-----------*/
//		djMode DJ;

		/*-----------Sound-----------*/
		void audioIn(float * input, int bufferSize, int nChannels); 

		void drawVolGraphs();
		void drawBeatBins();
		bool trackBeats(int low, int high); //check subbands between low and high for beats

		vector <float> left;
		vector <float> right;
		vector <float> volHistory;
		
		float cVol;
		float pVol;
		float lastBeatTime, startTime, lengthOfBeat, bpm;
		int tapCount;

		ofSoundStream soundStream;
		ofxUIMovingGraph *audio;

		beatDetect bd;

		
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)

};

