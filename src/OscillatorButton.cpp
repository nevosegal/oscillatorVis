//
//  OscillatorButton.cpp
//  oscillatorVis
//
//  Created by Nevo Segal on 01/01/2015.
//
//

#include "OscillatorButton.h"


OscillatorButton::OscillatorButton(){

}

OscillatorButton::OscillatorButton(int x, int y, string type){
    this->x = x;
    this->y = y;
    this->type = type;
    xsize = 35;
    ysize = 20;
}

double OscillatorButton::play(){
    if(type == "tri"){
        wave = osc.triangle(440);
    }
    else if(type == "saw"){
        wave = osc.saw(440);
    }
    else if(type == "square"){
        wave = osc.square(440);
    }
    else{
        wave = osc.sinewave(440);
    }

    return wave;
}

void OscillatorButton::draw(){
    ofFill();
    ofSetColor(150,150,150);
    ofRect(this->x, this->y, xsize, ysize);
}

bool OscillatorButton::isHovered(int x, int y){
    if(x > this->x && y > this->y && x < (this->x + xsize) && y < (this->y + ysize)){
        return true;
    }
    return false;
}