#include "SplashScene.h"
#include "RoadBlock.h"
#include "GameScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

RoadBlock::RoadBlock(cocos2d::Layer* layer)
{
	
	roadBlockSprite = Sprite::create("Materials/RoadBlock.png");
	roadBlockSprite->setAnchorPoint(Vec2(0.0, 0.0));
	roadBlockSprite->setPosition(Point(0, 90));
	auto roadBody = PhysicsBody::createBox(roadBlockSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	roadBody->setCollisionBitmask(ROAD_COLLISION_BITMASK);
	roadBody->setContactTestBitmask(true);
	roadBody->setDynamic(false);
	roadBlockSprite->setPhysicsBody(roadBody);
	layer->addChild(roadBlockSprite, 5);
}