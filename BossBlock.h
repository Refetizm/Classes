#ifndef __BOSS_BLOCK_H__
#define __BOSS_BLOCK_H__

#include "cocos2d.h"

class BossBlock
{
public:
	BossBlock(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* bossBlockSprite;
	cocos2d::Size* visibleSize;
	cocos2d::Vec2* origin;
};

#endif // __BOSS_BLOCK_H__
