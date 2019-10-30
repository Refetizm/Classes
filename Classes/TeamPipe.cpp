#include "TeamPipe.h"
#include "GameScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

TeamPipe::TeamPipe(cocos2d::Layer* layer)
{
	teamPipeSprite = Sprite::create("Materials/TeamPipe.png");
	teamPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	teamPipeSprite->setPosition(Point(2500, 100));
	auto teamPipeBody = PhysicsBody::createBox(teamPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	teamPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	teamPipeBody->setContactTestBitmask(true);
	teamPipeBody->setDynamic(false);
	teamPipeSprite->setPhysicsBody(teamPipeBody);
	layer->addChild(teamPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	teamPipeSprite->runAction(moverAction);
}
CocosPipe::CocosPipe(cocos2d::Layer* layer)
{
	cocosPipeSprite = Sprite::create("Materials/CocosPipe.png");
	cocosPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	cocosPipeSprite->setPosition(Point(5000, 100));
	auto cocosPipeBody = PhysicsBody::createBox(cocosPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	cocosPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	cocosPipeBody->setContactTestBitmask(true);
	cocosPipeBody->setDynamic(false);
	cocosPipeSprite->setPhysicsBody(cocosPipeBody);
	layer->addChild(cocosPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	cocosPipeSprite->runAction(moverAction);
}

EnglishPipe::EnglishPipe(cocos2d::Layer* layer)
{
	englishPipeSprite = Sprite::create("Materials/EnglishPipe.png");
	englishPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	englishPipeSprite->setPosition(Point(7500, 100));
	auto englishPipeBody = PhysicsBody::createBox(englishPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	englishPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	englishPipeBody->setContactTestBitmask(true);
	englishPipeBody->setDynamic(false);
	englishPipeSprite->setPhysicsBody(englishPipeBody);
	layer->addChild(englishPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	englishPipeSprite->runAction(moverAction);
}

CleanPipe::CleanPipe(cocos2d::Layer* layer)
{
	cleanPipeSprite = Sprite::create("Materials/CleanPipe.png");
	cleanPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	cleanPipeSprite->setPosition(Point(10000, 100));
	auto cleanPipeBody = PhysicsBody::createBox(cleanPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	cleanPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	cleanPipeBody->setContactTestBitmask(true);
	cleanPipeBody->setDynamic(false);
	cleanPipeSprite->setPhysicsBody(cleanPipeBody);
	layer->addChild(cleanPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	cleanPipeSprite->runAction(moverAction);
}

UnityPipe::UnityPipe(cocos2d::Layer* layer)
{
	unityPipeSprite = Sprite::create("Materials/UnityPipe.png");
	unityPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	unityPipeSprite->setPosition(Point(12500, 100));
	auto unityPipeBody = PhysicsBody::createBox(unityPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	unityPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	unityPipeBody->setContactTestBitmask(true);
	unityPipeBody->setDynamic(false);
	unityPipeSprite->setPhysicsBody(unityPipeBody);
	layer->addChild(unityPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	unityPipeSprite->runAction(moverAction);
}

CsharpPipe::CsharpPipe(cocos2d::Layer* layer)
{
	csharpPipeSprite = Sprite::create("Materials/CsharpPipe.png");
	csharpPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	csharpPipeSprite->setPosition(Point(15000, 100));
	auto csharpPipeBody = PhysicsBody::createBox(csharpPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	csharpPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	csharpPipeBody->setContactTestBitmask(true);
	csharpPipeBody->setDynamic(false);
	csharpPipeSprite->setPhysicsBody(csharpPipeBody);
	layer->addChild(csharpPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	csharpPipeSprite->runAction(moverAction);
}

GamesPipe::GamesPipe(cocos2d::Layer* layer)
{
	gamesPipeSprite = Sprite::create("Materials/GamesPipe.png");
	gamesPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	gamesPipeSprite->setPosition(Point(17500, 100));
	auto gamesPipeBody = PhysicsBody::createBox(gamesPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	gamesPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	gamesPipeBody->setContactTestBitmask(true);
	gamesPipeBody->setDynamic(false);
	gamesPipeSprite->setPhysicsBody(gamesPipeBody);
	layer->addChild(gamesPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	gamesPipeSprite->runAction(moverAction);
}

CppPipe::CppPipe(cocos2d::Layer* layer)
{
	cppPipeSprite = Sprite::create("Materials/CppPipe.png");
	cppPipeSprite->setAnchorPoint(Vec2(0.0, 0.0));
	cppPipeSprite->setPosition(Point(20000, 100));
	auto cppPipeBody = PhysicsBody::createBox(cppPipeSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	cppPipeBody->setCollisionBitmask(PIPE_COLLISION_BITMASK);
	cppPipeBody->setContactTestBitmask(true);
	cppPipeBody->setDynamic(false);
	cppPipeSprite->setPhysicsBody(cppPipeBody);
	layer->addChild(cppPipeSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	cppPipeSprite->runAction(moverAction);
}

Mistral::Mistral(cocos2d::Layer* layer)
{
	mistralSprite = Sprite::create("Materials/Mistral.png");
	mistralSprite->setScale(3);
	mistralSprite->setAnchorPoint(Vec2(0.0, 0.0));
	mistralSprite->setPosition(Point(23000, 100));
	auto mistralBody = PhysicsBody::createBox(mistralSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	mistralBody->setCollisionBitmask(MISTRAL_COLLISION_BITMASK);
	mistralBody->setContactTestBitmask(true);
	mistralBody->setDynamic(false);
	mistralSprite->setPhysicsBody(mistralBody);
	layer->addChild(mistralSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	mistralSprite->runAction(moverAction);
}