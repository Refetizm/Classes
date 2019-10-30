#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"

class Ball
{
public:
	Ball();
	void SpawnBall(cocos2d::Layer* layer);
	
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	float bezierRandomHeight;
	float bezierRandomWidth;
};

#endif // __BALL_H__
