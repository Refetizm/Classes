#include "Items.h"
#include "Definitions.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

TShirt::TShirt(cocos2d::Layer* layer)
{
	tShirtSprite = Sprite::create("Materials/Tshirt.png");
	tShirtSprite->setScale(0.2);
	tShirtSprite->setAnchorPoint(Vec2(0.0, 0.0));
	tShirtSprite->setPosition(Point(3000, 750));
	auto tShirtBody = PhysicsBody::createBox(tShirtSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	tShirtBody->setCollisionBitmask(TSHIRT_TRIGGER_BITMASK);
	tShirtBody->setContactTestBitmask(true);
	tShirtBody->setDynamic(false);
	tShirtSprite->setPhysicsBody(tShirtBody);
	layer->addChild(tShirtSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	tShirtSprite->runAction(moverAction);
}

Netflix::Netflix(cocos2d::Layer* layer)
{
	netflixSprite = Sprite::create("Materials/Netflix.png");
	netflixSprite->setScale(0.3);
	netflixSprite->setAnchorPoint(Vec2(0.0, 0.0));
	netflixSprite->setPosition(Point(4750, 450));
	auto netflixBody = PhysicsBody::createBox(netflixSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	netflixBody->setCollisionBitmask(NETFLIX_TRIGGER_BITMASK);
	netflixBody->setContactTestBitmask(true);
	netflixBody->setDynamic(false);
	netflixSprite->setPhysicsBody(netflixBody);
	layer->addChild(netflixSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	netflixSprite->runAction(moverAction);
}

IPad::IPad(cocos2d::Layer* layer)
{
	iPadSprite = Sprite::create("Materials/iPad.png");
	iPadSprite->setScale(0.4);
	iPadSprite->setAnchorPoint(Vec2(0.0, 0.0));
	iPadSprite->setPosition(Point(6500, 250));
	auto iPadBody = PhysicsBody::createBox(iPadSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	iPadBody->setCollisionBitmask(IPAD_TRIGGER_BITMASK);
	iPadBody->setContactTestBitmask(true);
	iPadBody->setDynamic(false);
	iPadSprite->setPhysicsBody(iPadBody);
	layer->addChild(iPadSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	iPadSprite->runAction(moverAction);
}

BagPack::BagPack(cocos2d::Layer* layer)
{
	bagPackSprite = Sprite::create("Materials/BagPack.png");
	bagPackSprite->setScale(0.5);
	bagPackSprite->setAnchorPoint(Vec2(0.0, 0.0));
	bagPackSprite->setPosition(Point(8000, 500));
	auto bagPackBody = PhysicsBody::createBox(bagPackSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	bagPackBody->setCollisionBitmask(BAGPACK_TRIGGER_BITMASK);
	bagPackBody->setContactTestBitmask(true);
	bagPackBody->setDynamic(false);
	bagPackSprite->setPhysicsBody(bagPackBody);
	layer->addChild(bagPackSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	bagPackSprite->runAction(moverAction);
}

Mug::Mug(cocos2d::Layer* layer)
{
	mugSprite = Sprite::create("Materials/Mug.png");
	mugSprite->setScale(0.2);
	mugSprite->setAnchorPoint(Vec2(0.0, 0.0));
	mugSprite->setPosition(Point(10000, 800));
	auto mugBody = PhysicsBody::createBox(mugSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	mugBody->setCollisionBitmask(MUG_TRIGGER_BITMASK);
	mugBody->setContactTestBitmask(true);
	mugBody->setDynamic(false);
	mugSprite->setPhysicsBody(mugBody);
	layer->addChild(mugSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	mugSprite->runAction(moverAction);
}

Thermos::Thermos(cocos2d::Layer* layer)
{
	thermosSprite = Sprite::create("Materials/Thermos.png");
	thermosSprite->setScale(0.5);
	thermosSprite->setAnchorPoint(Vec2(0.0, 0.0));
	thermosSprite->setPosition(Point(12000, 250));
	auto thermosBody = PhysicsBody::createBox(thermosSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	thermosBody->setCollisionBitmask(THERMOS_TRIGGER_BITMASK);
	thermosBody->setContactTestBitmask(true);
	thermosBody->setDynamic(false);
	thermosSprite->setPhysicsBody(thermosBody);
	layer->addChild(thermosSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	thermosSprite->runAction(moverAction);
}

iTunes::iTunes(cocos2d::Layer* layer)
{
	itunesSprite = Sprite::create("Materials/iTunes.png");
	itunesSprite->setScale(0.3);
	itunesSprite->setAnchorPoint(Vec2(0.0, 0.0));
	itunesSprite->setPosition(Point(14000, 675));
	auto itunesBody = PhysicsBody::createBox(itunesSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	itunesBody->setCollisionBitmask(ITUNES_TRIGGER_BITMASK);
	itunesBody->setContactTestBitmask(true);
	itunesBody->setDynamic(false);
	itunesSprite->setPhysicsBody(itunesBody);
	layer->addChild(itunesSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	itunesSprite->runAction(moverAction);
}

MasomoBox::MasomoBox(cocos2d::Layer* layer)
{
	masomoBoxSprite = Sprite::create("Materials/MasomoBox.png");
	masomoBoxSprite->setScale(0.3);
	masomoBoxSprite->setAnchorPoint(Vec2(0.0, 0.0));
	masomoBoxSprite->setPosition(Point(16000, 500));
	auto masomoBoxBody = PhysicsBody::createBox(masomoBoxSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	masomoBoxBody->setCollisionBitmask(MASOMOBOX_TRIGGER_BITMASK);
	masomoBoxBody->setContactTestBitmask(true);
	masomoBoxBody->setDynamic(false);
	masomoBoxSprite->setPhysicsBody(masomoBoxBody);
	layer->addChild(masomoBoxSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	masomoBoxSprite->runAction(moverAction);
}

MacBook::MacBook(cocos2d::Layer* layer)
{
	macbookSprite = Sprite::create("Materials/MacBook.png");
	macbookSprite->setScale(0.4);
	macbookSprite->setAnchorPoint(Vec2(0.0, 0.0));
	macbookSprite->setPosition(Point(20000, 780));
	auto macbookBody = PhysicsBody::createBox(macbookSprite->getContentSize(), PhysicsMaterial(0, 1, 0));
	macbookBody->setCollisionBitmask(MACBOOK_TRIGGER_BITMASK);
	macbookBody->setContactTestBitmask(true);
	macbookBody->setDynamic(false);
	macbookSprite->setPhysicsBody(macbookBody);
	layer->addChild(macbookSprite, 5);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	macbookSprite->runAction(moverAction);
}