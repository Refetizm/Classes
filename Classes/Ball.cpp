#include "Ball.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Ball::Ball()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void Ball::SpawnBall(cocos2d::Layer* layer)
{
	auto ballSprite = Sprite::create("Materials/Ball.png");
	
	auto ballBody = PhysicsBody::createCircle(ballSprite->getContentSize().width / 2, PhysicsMaterial(0, 1, 0));

	
	//
	
	//

	//
	auto randomBezierY = CCRANDOM_0_1();

	if (randomBezierY > UPPER_LIMIT)
	{
		bezierRandomHeight = 250;
	}
	else if (LOWER_LIMIT < randomBezierY < UPPER_LIMIT)
	{
		bezierRandomHeight = 150;
	}
	else if (randomBezierY < LOWER_LIMIT)
	{
		bezierRandomHeight = 50;
	}
	//

	//
	auto randomBezierX = CCRANDOM_0_1();
	if (randomBezierX > UPPER_LIMIT)
	{
		bezierRandomWidth = -50;
	}
	else if (LOWER_LIMIT < randomBezierX < UPPER_LIMIT)
	{
		bezierRandomWidth = -100;
	}
	else if (randomBezierX < LOWER_LIMIT)
	{
		bezierRandomWidth = -150;
	}

	

	ballBody->setDynamic(false);
	ballBody->setCollisionBitmask(BALL_TRIGGER_BITMASK);
	ballBody->setContactTestBitmask(true);
	ballSprite->setPhysicsBody(ballBody);

	
	ballSprite->setPosition(Point(1637, 200));
	layer->addChild(ballSprite, 1);

	auto ballAction1 = MoveTo::create(0.2, Point(1549, 284));
	auto ballAction2 = JumpTo::create(1, Point(bezierRandomWidth, bezierRandomHeight), bezierRandomHeight + 50, 1);
	auto ballAction3 = MoveTo::create(1, Point(-visibleSize.width / 2, bezierRandomHeight));
	auto ballSequence = Sequence::create(ballAction1, ballAction2, ballAction3, nullptr);

	ballSprite->runAction(ballSequence);
	
	

	auto ballRotater = RepeatForever::create(RotateBy::create(1, 150));
	ballSprite->runAction(ballRotater);
}
