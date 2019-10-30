#ifndef __CHARACTER_FINAL_H__
#define __CHARACTER_FINAL_H__

#include "cocos2d.h"

class CharacterFinal
{
public:
	CharacterFinal(cocos2d::Layer* layer);
	void Fall();
	void Fly() { isFalling = false; }
	void StopFlying() { isFalling = true; }
	bool onGroundContactBegin(cocos2d::PhysicsContact& groundContact);
	

private:
	cocos2d::Sprite* charFinal;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	bool isFalling;


};

#endif // __CHARACTER_FINAL_H__
