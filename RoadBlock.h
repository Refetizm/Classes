#ifndef __ROAD_BLOCK_H__
#define __ROAD_BLOCK_H__

#include "cocos2d.h"

class RoadBlock
{
public:
	RoadBlock(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* roadBlockSprite;
	cocos2d::Size* visibleSize;
	cocos2d::Vec2* origin;
};

#endif // __ROAD_BLOCK_H__
