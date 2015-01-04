//
//  OscillatorButton.h
//  oscillatorVis
//
//  Created by Nevo Segal on 01/01/2015.
//
//

#ifndef __oscillatorVis__OscillatorButton__
#define __oscillatorVis__OscillatorButton__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMaxim.h"

class OscillatorButton{
public:
    OscillatorButton();
    OscillatorButton(int x, int y, string type);
    
    void draw();
    bool isHovered(int x, int y);
    double play();
    void setFreq(int freq);
    int getFreq();
    bool isActive();
    void activate();
    void deactivate();
    
    int x, y, xsize, ysize;
    maxiOsc osc;
    string type;
    double wave;
    int freq;
    bool playing;
    ofImage img;
    bool active;
};

#endif /* defined(__oscillatorVis__OscillatorButton__) */