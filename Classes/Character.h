#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"

class Character
{
public:
	Character(cocos2d::Layer* layer);
	void Fall();											//For update our character's function (falling or jumping)
	void Fly() { isFalling = false; }						//Our character's jumping function. We added "isFalling=true" boolean function. Because If we're gonna jump, we shouldn't fall.
	void StopFlying() { isFalling = true;}					//This function is used to start the fall function immediately after jumping.
	void Walk() { isWalking = true; }						//This function was created to enable different animations when walking and jumping.
	void StopWalking() { isWalking = false; }				//This function is used to start the jumping animation immediately after we stop walking.

private:
	cocos2d::Sprite* mainChar;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	bool isFalling;											//For checking is our character falling or jumping?
	bool isWalking;											//For checking is our character walking or jumping?
	cocos2d::SpriteBatchNode* charBatchNode;				//We called Sprite Batch Node function for our character's animation.

	
	
};


#endif // __CHARACTER_H__
