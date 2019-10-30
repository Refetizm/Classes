#include "SplashScene.h"
#include "BossBlock.h"
#include "GameScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

BossBlock::BossBlock(cocos2d::Layer* layer)
{
	
	bossBlockSprite = Sprite::create("Materials/BossBlock.png");
	bossBlockSprite->setAnchorPoint(Vec2(0.0, 0.0));
	bossBlockSprite->setPosition(Point(0, 0));
	auto bossBlockBody = PhysicsBody::createBox(bossBlockSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	bossBlockBody->setCollisionBitmask(ROAD_COLLISION_BITMASK);
	bossBlockBody->setContactTestBitmask(true);
	bossBlockBody->setDynamic(false);
	bossBlockSprite->setPhysicsBody(bossBlockBody);
	layer->addChild(bossBlockSprite, 3);
}