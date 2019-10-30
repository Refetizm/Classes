#include "CharacterFinal.h"
#include "Definitions.h"
#include "BossBlock.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

CharacterFinal::CharacterFinal(cocos2d::Layer* layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	
	charFinal = Sprite::create("SpriteSheets/CharacterFinal-Idle.png");
	charFinal->setAnchorPoint(Vec2(0.0, 0.0));
	charFinal->setPosition(Point(100, 100));
	auto charBody = PhysicsBody::createBox(charFinal->getContentSize(), PhysicsMaterial(0, 1, 0));
	charBody->setCollisionBitmask(CHARACTER_COLLISION_BITMASK);
	charBody->setContactTestBitmask(true);
	charBody->setDynamic(true);
	charFinal->setPhysicsBody(charBody);
	layer->addChild(charFinal, 5);

	isFalling = true;
	
}

void CharacterFinal::Fall()
{
	if (isFalling)
	{
		charFinal->setTexture("SpriteSheets/CharacterFinal-Idle.png");
		charFinal->setPositionX(visibleSize.width / 8 + origin.x);
		charFinal->setPositionY(charFinal->getPositionY() - (CHAR_FALLING_SPEED * visibleSize.height * 5));
		if (charFinal->getPositionY() <= 35)
		{
			charFinal->setPositionY(45);
			charFinal->setRotation(0);
		}
	}
	else
	{
		charFinal->setTexture("SpriteSheets/CharacterFinal-Jump.png");
		charFinal->setPositionX(visibleSize.width / 8 + origin.x);
		charFinal->setPositionY(charFinal->getPositionY() + (CHAR_FALLING_SPEED * visibleSize.height * 5));
	}
}