#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "OscillatorButton.h"


class ofApp : public ofBaseApp{
    
public:
    ~ofApp();
    
    //class methods
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
    void audioRequested (float * input, int bufferSize, int nChannels);
    void audioReceived (float * input, int bufferSize, int nChannels);
    
    //class variables
    int	initialBufferSize;
    int	sampleRate;
    double wave,sample,outputs[2];
    ofxMaxiMix mymix;
    ofxMaxiOsc sine1;
    double *buffer;
    float screenRatio;
    OscillatorButton *osc_btns;
    int numOsc;
    int currOsc;
    int ypos;
    ofTrueTypeFont ttf;
    
};
