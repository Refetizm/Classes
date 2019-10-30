#include "BossScene.h"
#include "Definitions.h"
#include "ThirdCutscene.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "BossOverScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* BossScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
	scene->getPhysicsWorld()->setGravity(Vect(0, 0));
	auto layer = BossScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool BossScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

    /////////////////////////////
    // 2. SPRITE SECTION
    //    You can add your sprites below...
	/////////////////////////////
    
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/Impact.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/BossScene.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/BossScene.mp3");

	auto gearItem = MenuItemImage::create("Materials/Gear.png", "Materials/Gear.png", CC_CALLBACK_1(BossScene::GoToPauseMenuScene, this));
	gearItem->setPosition(Point(1800, 960));

	menu = Menu::create(gearItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 150);

	characterFinal = new CharacterFinal(this);


	auto masomoSprite = Sprite::create("Backgrounds/Masomo2.png");
	masomoSprite->setAnchorPoint(Vec2(0.0, 0.0));
	masomoSprite->setPosition(Point(0, 0));
	this->addChild(masomoSprite, 1);

	auto cannonSprite = Sprite::create("Materials/CannonBall.png");
	cannonSprite->setAnchorPoint(Vec2(0.0, 0.0));
	cannonSprite->setPosition(Point(1500, 45));
	this->addChild(cannonSprite, 3);

	auto bossSprite = Sprite::create("SpriteSheets/Boss-Idle.png");
	bossSprite->setAnchorPoint(Vec2(0.0, 0.0));
	bossSprite->setPosition(Point(1725, 45));
	this->addChild(bossSprite, 2);

	




	auto sorcererBatchNode = SpriteBatchNode::create("SpriteSheets/CrazyWizard.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/CrazyWizard.plist");
	auto sorcererSprite = Sprite::createWithSpriteFrameName("CrazyWizard1.png");
	sorcererSprite->setAnchorPoint(Vec2(0.0, 0.0));
	sorcererBatchNode->addChild(sorcererSprite);
	sorcererBatchNode->setScale(0.7);
	sorcererBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	sorcererBatchNode->setPosition(Point(860, 715));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 10; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("CrazyWizard%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	sorcererSprite->runAction(animate);
	this->addChild(sorcererBatchNode, 3);

	auto carpetSprite = Sprite::create("Materials/Carpet.png");
	carpetSprite->setAnchorPoint(Vec2(0.0, 0.0));
	carpetSprite->setPosition(Point(880, 700));
	this->addChild(carpetSprite, 2);


	auto magicBatchNode = SpriteBatchNode::create("SpriteSheets/Magic.png");
	SpriteFrameCache* frameCacheMagic = SpriteFrameCache::getInstance();
	frameCacheMagic->addSpriteFramesWithFile("SpriteSheets/Magic.plist");
	auto magicSprite = Sprite::createWithSpriteFrameName("Magic1.png");
	magicSprite->setAnchorPoint(Vec2(0.0, 0.0));
	magicBatchNode->addChild(magicSprite);
	magicBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	magicBatchNode->setPosition(Point(220, 890));
	Vector<SpriteFrame*> framesMagic;
	for (int i = 1; i <= 2; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("Magic%d.png", i);
		SpriteFrame* frameMagic = frameCacheMagic->getSpriteFrameByName(frameName.c_str());
		framesMagic.pushBack(frameMagic);
	}
	Animation* animationMagic = Animation::createWithSpriteFrames(framesMagic, 4.0f);
	animationMagic->setLoops(-1);
	auto animateMagic = Animate::create(animationMagic);
	magicSprite->runAction(animateMagic);
	this->addChild(magicBatchNode, 3);

	bossBlock = new BossBlock(this);


	auto fireNode = Node::create();
	auto fireBody = PhysicsBody::createBox(Size(1, 125));
	fireBody->setDynamic(false);
	fireBody->setCollisionBitmask(FIRE_TRIGGER_BITMASK);
	fireBody->setContactTestBitmask(true);
	fireNode->setPhysicsBody(fireBody);
	fireNode->setRotation(45);
	fireNode->setPosition(Point(1545, 290));
	this->addChild(fireNode);

	auto scoreNode = Node::create();
	auto scoreBody = PhysicsBody::createBox(Size(1, 1080));
	scoreBody->setDynamic(false);
	scoreBody->setCollisionBitmask(SCORE_TRIGGER_BITMASK);
	scoreBody->setContactTestBitmask(true);
	scoreNode->setPhysicsBody(scoreBody);
	scoreNode->setPosition(Point(-10, visibleSize.height / 2 + origin.y));
	this->addChild(scoreNode);
	
	

	this->schedule(schedule_selector(BossScene::SpawnBall), BALL_SPAWN_FREQUENCY * visibleSize.width);

	auto explosionContactListener = EventListenerPhysicsContact::create();
	explosionContactListener->onContactBegin = CC_CALLBACK_1(BossScene::onExplosionContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(explosionContactListener, this);

	auto scoreContactListener = EventListenerPhysicsContact::create();
	scoreContactListener->onContactBegin = CC_CALLBACK_1(BossScene::onScoreContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(scoreContactListener, this);

	auto overContactListener = EventListenerPhysicsContact::create();
	overContactListener->onContactBegin = CC_CALLBACK_1(BossScene::onOverContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(overContactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(BossScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	score = 0;
	endingScore = 5;
	__String* tempScore = __String::createWithFormat("%i", score);
	scoreLabel = Label::createWithTTF(tempScore->getCString(), "fonts/PressStart2P.ttf", visibleSize.height * SCORE_FONT_SIZE);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(Point(visibleSize.width / 2 + origin.x, 100));

	this->addChild(scoreLabel, 1000);

	

	

	
	this->scheduleUpdate();
	
    return true;
}

void BossScene::SpawnBall(float dt)
{
	ball.SpawnBall(this);

	auto fireSprite = Sprite::create("Materials/Fire.png");
	fireSprite->setTag(1);
	fireSprite->setAnchorPoint(Vec2(1.0, 0.0));
	fireSprite->setPosition(Point(1725, 465));
	this->addChild(fireSprite, 5);
	auto fireDelayer = DelayTime::create(2);
	auto fireSeq = Sequence::create(fireDelayer, (CallFunc::create([this]()
		{
			this->removeChildByTag(1);
		})), nullptr);
	this->runAction(fireSeq);
}

void BossScene::GoToPauseMenuScene(cocos2d::Ref* psender)
{
	Director::getInstance()->pause();
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

	menu->setLocalZOrder(-5);

	auto transparentBackground = Sprite::create("Backgrounds/MenuTransparentBackground.png");
	transparentBackground->setTag(1);
	transparentBackground->setAnchorPoint(Vec2(0.0, 0.0));
	transparentBackground->setPosition(Point(0, 0));
	this->addChild(transparentBackground, 149);

	auto menuBackground = Sprite::create("Backgrounds/PauseMenuBackground.png");
	menuBackground->setTag(2);
	menuBackground->setPosition(Point(960, 540));
	this->addChild(menuBackground, 150);


	auto resumeItem = MenuItemImage::create("Materials/Resume.png", "Materials/ResumeClicked.png", CC_CALLBACK_1(BossScene::GoToResumeScene, this));
	resumeItem->setPosition(Point(960, 600));

	auto retryItem = MenuItemImage::create("Materials/RetryPause.png", "RetryPauseClicked.png", CC_CALLBACK_1(BossScene::GoToRetryScene, this));
	retryItem->setPosition(Point(960, 550));

	auto newGameItem = MenuItemImage::create("Materials/NewGamePause.png", "NewGamePauseClicked.png", CC_CALLBACK_1(BossScene::GoToNewGameScene, this));
	newGameItem->setPosition(Point(960, 500));

	auto mainMenuItem = MenuItemImage::create("Materials/MainMenuPause.png", "MainMenuPauseClicked.png", CC_CALLBACK_1(BossScene::GoToMainMenuScene, this));
	mainMenuItem->setPosition(Point(960, 450));

	auto exitItem = MenuItemImage::create("Materials/ExitPause.png", "Materials/ExitPauseClicked.png", CC_CALLBACK_1(BossScene::GoToExitScene, this));
	exitItem->setPosition(Point(960, 400));

	auto menu = Menu::create(resumeItem, retryItem, newGameItem, mainMenuItem, exitItem, NULL);
	menu->setTag(3);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 151);
}

void BossScene::GoToResumeScene(cocos2d::Ref* psender)
{
	this->removeChildByTag(1);
	this->removeChildByTag(2);
	this->removeChildByTag(3);
	Director::getInstance()->resume();
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	menu->setLocalZOrder(150);
}

void BossScene::GoToRetryScene(cocos2d::Ref* psender)
{
	Director::getInstance()->resume();
	auto scene = BossScene::createScene();
	Director::sharedDirector()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void BossScene::GoToNewGameScene(cocos2d::Ref* psender)
{
	Director::getInstance()->resume();
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void BossScene::GoToMainMenuScene(cocos2d::Ref* psender)
{
	Director::getInstance()->resume();
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void BossScene::GoToExitScene(cocos2d::Ref* psender)
{
	Director::getInstance()->end();
}

bool BossScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	characterFinal->Fly();
	this->scheduleOnce(schedule_selector(BossScene::StopFlying), CHAR_FLY_DURATION);
	return true;
}

bool BossScene::onExplosionContactBegin(cocos2d::PhysicsContact& explosionContact)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/CannonBall.wav");
	PhysicsBody* a = explosionContact.getShapeA()->getBody();
	PhysicsBody* b = explosionContact.getShapeB()->getBody();
	if ((BALL_TRIGGER_BITMASK == a->getCollisionBitmask() && FIRE_TRIGGER_BITMASK == b->getCollisionBitmask()) || (BALL_TRIGGER_BITMASK == b->getCollisionBitmask() && FIRE_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/CannonBall.wav");

		explosionBatchNode = SpriteBatchNode::create("SpriteSheets/explosionSprite.png");
		SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
		frameCache->addSpriteFramesWithFile("SpriteSheets/explosionSprite.plist");
		explosionSprite = Sprite::createWithSpriteFrameName("explosion1.gif");
		explosionSprite->setAnchorPoint(Vec2(0.0, 0.0));
		explosionBatchNode->addChild(explosionSprite);
		explosionBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
		explosionBatchNode->setScale(2);
		explosionBatchNode->setPosition(Point(1400, 225));
		Vector<SpriteFrame*>frames;
		for (int i = 1; i <= 65; i++)
		{
			std::string frameName = cocos2d::StringUtils::format("explosion%d.gif", i);
			SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
			frames.pushBack(frame);
			
		}
		Animation* animation = Animation::createWithSpriteFrames(frames, 0.01f);
		animation->setLoops(1);
		auto animate = Animate::create(animation);
		explosionSprite->runAction(animate);
		this->addChild(explosionBatchNode, 5);
		return true;
	}
	
	return true;
}

bool BossScene::onScoreContactBegin(cocos2d::PhysicsContact& scoreContact)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/Item.wav");
	PhysicsBody* a = scoreContact.getShapeA()->getBody();
	PhysicsBody* b = scoreContact.getShapeB()->getBody();
	if ((BALL_TRIGGER_BITMASK == a->getCollisionBitmask() && SCORE_TRIGGER_BITMASK == b->getCollisionBitmask()) || (BALL_TRIGGER_BITMASK == b->getCollisionBitmask() && SCORE_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
		score++;
		__String* tempScore = __String::createWithFormat("%i", score);
		scoreLabel->setString(tempScore->getCString());
		if (score >= endingScore)
		{
			endingScore = score;
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, ThirdCutScene::createScene()));
			
		}
		return true;
	}
	
	return true;
}

bool BossScene::onOverContactBegin(cocos2d::PhysicsContact& overContact)
{
	
	PhysicsBody* a = overContact.getShapeA()->getBody();
	PhysicsBody* b = overContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && BALL_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && BALL_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Impact.wav");
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, BossOverScene::createScene()));
		
	}
	return true;
}

void BossScene::StopFlying(float dt)
{
	characterFinal->StopFlying();
}

void BossScene::update(float dt)
{
	characterFinal->Fall();
	
}