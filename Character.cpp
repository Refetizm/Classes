#include "Character.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Character::Character(cocos2d::Layer* layer)
{
	if (isWalking)
	{
		CCLOG("WALKING");
	}
	else
	{
		CCLOG("FLYING");
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 1. SPRITE SECTION
	//    In this section we call our character's spritesheet and datas for our character's animations.
	/////////////////////////////

	
	charBatchNode = SpriteBatchNode::create("SpriteSheets/Character.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/Character.plist");
	mainChar = Sprite::createWithSpriteFrameName("wlk1.png");
	mainChar->setAnchorPoint(Vec2(0.5f, 0.0));
	charBatchNode->addChild(mainChar);
	charBatchNode->setScale(0.5);
	charBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	charBatchNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));
	Vector<SpriteFrame*>frames;
	for (int i = 1; i <= 6; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("wlk%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	mainChar->runAction(animate);
	
	/////////////////////////////
	// 2. PHYSICS SECTION
	//    In this section we add to physics body to our character.
	/////////////////////////////

	
	auto charBody = PhysicsBody::createBox(mainChar->getContentSize(), PhysicsMaterial(0, 1, 0));
	charBody->setCollisionBitmask(CHARACTER_COLLISION_BITMASK);
	charBody->setContactTestBitmask(true);
	mainChar->setPhysicsBody(charBody);
	layer->addChild(charBatchNode, 5);
	

	
	
	isFalling = true;
		

}

void Character::Fall()
{
	if (true == isFalling)
	{
		charBatchNode->setPositionX(visibleSize.width / 2 + origin.x);													//Our character jumps only y-axis. Therefore x-position will not change as our character falls.
		charBatchNode->setPositionY(charBatchNode->getPositionY() - (CHAR_FALLING_SPEED * visibleSize.height * 3));			//As our character falls, his height will decrease by the multiplication of the character's height and falling speed.
		if (charBatchNode->getPositionY() <= 100)
		{
			charBatchNode->setPositionY(100);
			charBatchNode->setRotation(0);
		}
	}
	else
	{
		charBatchNode->setPositionX(visibleSize.width / 2 + origin.x);													//Our character jumps only y-axis. Therefore x-position will not change as our character jumps.
		charBatchNode->setPositionY(charBatchNode->getPositionY() + (CHAR_FALLING_SPEED * visibleSize.height * 3));		//As our character jumps, his height will increase by the multiplication of the character's height and falling speed.
		
		
	}
	
}

