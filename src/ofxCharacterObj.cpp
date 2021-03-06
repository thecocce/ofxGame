/*
 *  ofxCharProxy.cpp
 *
 *  Created by Patricio González Vivo on 04/07/11.
 *  Copyright 2011 PatricioGonzalezVivo.com. All rights reserved.
 *
 *
 *  This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 
 *	Unported License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/ 
 *	or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 */
#include "ofxCharacterObj.h"

ofxCharacterObj::ofxCharacterObj(string _charName){
	objectName = _charName;//"character"; 
	loadXml();
	loadExtraXml();
	character.load(file);
	reset();
	saveXml();
}

void ofxCharacterObj::reset(){
	character.setOrientation(ori);
	character.setPhysics(den, bou, fri);
	width = character.getWidth()*2;
	height = character.getHeight()*2;
	character.setScale(scale);
	character.pos.set(x, y);
}

void ofxCharacterObj::draw(int _x, int _y){
	ofSetColor(255, 255);
	character.draw(*bDebug);
	
	ofPushMatrix();
	ofTranslate(_x-getScaledWidth()*0.5,_y-getScaledHeight()*0.5);
	ofScale(scale, scale);
	
	if (*bDebug)
		drawBoundingBox();
	
	ofPopMatrix();
}

void ofxCharacterObj::loadExtraXml(string filePath){
	ofxXmlSettings XML;
	//cout << "Reading " << objectName << " configuration file " << filePath;
	
	if (XML.loadFile(filePath)){
		//cout << " [ OK ]" << endl;
		
		ori = XML.getValue(objectName+":orientation","LEFT");
		den = XML.getValue(objectName+":density",0.5);
		bou = XML.getValue(objectName+":bounce",0.5);
		fri = XML.getValue(objectName+":friction",0.5);
		
	} else
		cout << " [ FAIL ]" << endl;
};