#include "FirstCutscene.h"
#include "Definitions.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;


Scene* FirstCutScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
	scene->getPhysicsWorld()->setGravity(Vect(0, 0));
	auto layer = FirstCutScene::create();
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
bool FirstCutScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto cutsceneBackground = Sprite::create("Backgrounds/FirstCutsceneBackgroundClose.png");
	cutsceneBackground->setAnchorPoint(Vec2(0.0, 0.0));
	cutsceneBackground->setPosition(Point(0, 0));
	this->addChild(cutsceneBackground, 1);

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/FirstCutscene.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/FirstCutscene.mp3");
	
	/////////////////////////////
	// 1. TIMELINE
	//    Each tab has a 10-second segment of the scene.
	/////////////////////////////
	
	// 0-10 SECONDS BEGINING

	
	
	
	auto nodeScene = Node::create();
	
	/* auto delayer = DelayTime::create(5);
	
	auto seq = Sequence::create(delayer, CallFunc::create([this]() { teamCut = new TeamCut(this); }), nullptr); */

	auto npcOneDelay = DelayTime::create(9);
	auto npcOneSeq = Sequence::create(npcOneDelay, Spawn::create((CallFunc::create([this]() {npcOne = new NpcOne(this); })), 
		(CallFunc::create([this]() {npcTwo = new NpcTwo(this); })), nullptr) , nullptr);

	
	nodeScene->runAction(npcOneSeq);
	this->addChild(nodeScene);

	// 0-10 SECONDS END
	////////////////////////////////////////////////////////////////////////////////////////////
	// 10-20 SECONDS BEGINING

	auto speechDelayer = DelayTime::create(13);
	auto bubleDelayer = DelayTime::create(3.5);
	auto bubleFastDelayer = DelayTime::create(3.1);
	auto bubleFastestDelayer = DelayTime::create(2);
	auto bubleUltraFastDelayer = DelayTime::create(0.5);
	auto bubleGodLikeFastDelayer = DelayTime::create(0.1);
	auto angerMeterDelayer = DelayTime::create(30);
	auto rageModeDelayer = DelayTime::create(57);
	auto afterRageDelayer = DelayTime::create(63);
	auto lastSpeechDelayer = DelayTime::create(11);

	auto speechOneSeq = Sequence::create(speechDelayer, (CallFunc::create([this]() {speechOne = new SpeechOne(this); })), bubleDelayer, 
		(CallFunc::create([this]() {speechTwo = new SpeechTwo(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechThree = new SpeechThree(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechFour = new SpeechFour(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechFive = new SpeechFive(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechSix = new SpeechSix(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechSeven = new SpeechSeven(this); })), bubleFastDelayer,
		(CallFunc::create([this]() {speechEight = new SpeechEight(this); })), bubleFastDelayer,
		(CallFunc::create([this]() {speechNine = new SpeechNine(this); })), bubleFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleFastestDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleFastestDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleFastestDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleFastestDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleUltraFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleUltraFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleUltraFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleUltraFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleUltraFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleUltraFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleUltraFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechTen = new SpeechTen(this); })), bubleGodLikeFastDelayer,
		(CallFunc::create([this]() {speechEleven = new SpeechEleven(this); })), bubleGodLikeFastDelayer, nullptr);
	nodeScene->runAction(speechOneSeq);

	
	auto angerMeterSeq = Sequence::create(angerMeterDelayer, (CallFunc::create([this]() {angerMeter = new AngerMeter(this); })), nullptr);
	nodeScene->runAction(angerMeterSeq);

	auto rageModeSeq = Sequence::create(rageModeDelayer, (CallFunc::create([this]() {rageMode = new RageMode(this); })), nullptr);
	nodeScene->runAction(rageModeSeq);
	
	auto afterRageSeq = Sequence::create(afterRageDelayer, (CallFunc::create([this]() {speechTwelve = new SpeechTwelve(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechThirteen = new SpeechThirteen(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechFourteen = new SpeechFourteen(this); })), bubleDelayer,
		(CallFunc::create([this]() {speechFifteen = new SpeechFifteen(this); })), lastSpeechDelayer,
		(CallFunc::create([this]() {speechSixteen = new SpeechSixteen(this); })), bubleDelayer,
		(CallFunc::create([this]() {Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, GameScene::createScene())); })), nullptr);
	nodeScene->runAction(afterRageSeq);

	
	cutsceneBatchNode = SpriteBatchNode::create("SpriteSheets/characterCutsceneWalk.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/characterCutsceneWalk.plist");
	cutsceneChar = Sprite::createWithSpriteFrameName("wlkl1.png");
	cutsceneChar->setAnchorPoint(Vec2(0.0, 0.0));
	cutsceneBatchNode->addChild(cutsceneChar);
	cutsceneBatchNode->setScale(0.5);
	cutsceneBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	cutsceneBatchNode->setPosition(Point(1950, 100));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 6; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("wlkl%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	cutsceneChar->runAction(animate);
	this->addChild(cutsceneBatchNode, 3);

	auto charMove = MoveTo::create(7, Point(700, 100));
	cutsceneBatchNode->runAction(charMove);

	auto charBody = PhysicsBody::createBox(cutsceneChar->getContentSize(), PhysicsMaterial(0, 1, 0));
	charBody->setCollisionBitmask(CHARACTER_COLLISION_BITMASK);
	charBody->setDynamic(false);
	charBody->setContactTestBitmask(true);
	cutsceneChar->setPhysicsBody(charBody);

	auto eventNode = Node::create();
	auto eventBody = PhysicsBody::createBox(Size(1, 1080));
	eventBody->setDynamic(false);
	eventBody->setCollisionBitmask(EVENT_TRIGGER_BITMASK);
	eventBody->setContactTestBitmask(true);
	eventNode->setPhysicsBody(eventBody);
	eventNode->setPosition(Point(710, 540));
	this->addChild(eventNode);

	auto eventContactListener = EventListenerPhysicsContact::create();
	eventContactListener->onContactBegin = CC_CALLBACK_1(FirstCutScene::onEventContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventContactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(FirstCutScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	
    return true;
	
}

bool FirstCutScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto skipItem = MenuItemImage::create("Materials/Skip.png", "Materials/SkipClicked.png", CC_CALLBACK_1(FirstCutScene::GoToGameScene, this));
	skipItem->setPosition(Point(1670, 540));

	auto menu = Menu::create(skipItem, NULL);
	menu->setTag(5);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 150);
	return true;
}

void FirstCutScene::GoToGameScene(cocos2d::Ref* psender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

bool FirstCutScene::onEventContactBegin(cocos2d::PhysicsContact& contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && EVENT_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && EVENT_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		auto backgroundDelayer = DelayTime::create(1);
		auto backgroundSeq = Sequence::create(backgroundDelayer,
			CallFunc::create([=]() -> void {
		auto cutsceneBackgroundOpen = Sprite::create("Backgrounds/FirstCutsceneBackgroundOpen.png");
		cutsceneBackgroundOpen->setAnchorPoint(Vec2(0.0, 0.0));
		cutsceneBackgroundOpen->setPosition(Point(0, 0));
		this->addChild(cutsceneBackgroundOpen, 2);
		
				}),
			nullptr);
		this->runAction(backgroundSeq);
		cutsceneBatchNode->setLocalZOrder(-5);
		auto characterIdle = Sprite::create("SpriteSheets/characterIdle.png");
		characterIdle->setScale(0.5);
		characterIdle->setAnchorPoint(Vec2(0.0, 0.0));
		characterIdle->setPosition(Point(700, 100));
		this->addChild(characterIdle, 3);

		auto characterDelayer = DelayTime::create(50);
		auto rageReturnDelayer = DelayTime::create(20);
		auto characterChanger = Sequence::create(characterDelayer,
			CallFunc::create([=]() -> void {
				characterIdle->setTexture("SpriteSheets/RageCharacter-Idle.png"); }), rageReturnDelayer,
			CallFunc::create([=]() -> void {
					characterIdle->setLocalZOrder(-5);
				
				
					cutsceneBatchNode = SpriteBatchNode::create("SpriteSheets/RageReturn.png");
					SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
					frameCache->addSpriteFramesWithFile("SpriteSheets/RageReturn.plist");
					cutsceneChar = Sprite::createWithSpriteFrameName("RageReturn1.png");
					cutsceneChar->setAnchorPoint(Vec2(0.0, 0.0));
					cutsceneBatchNode->addChild(cutsceneChar);
					cutsceneBatchNode->setScale(0.5);
					cutsceneBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
					cutsceneBatchNode->setPosition(Point(700, 100));
					Vector<SpriteFrame*> frames;
					for (int i = 1; i <= 6; i++)
					{
						std::string frameName = cocos2d::StringUtils::format("RageReturn%d.png", i);
						SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
						frames.pushBack(frame);
					}
					Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);
					animation->setLoops(-1);
					auto animate = Animate::create(animation);
					cutsceneChar->runAction(animate);
					this->addChild(cutsceneBatchNode, 10);
				
					auto charMove = MoveTo::create(7, Point(1950, 100));
					cutsceneBatchNode->runAction(charMove);
				
				}), nullptr);
		this->runAction(characterChanger);
	}
	return true;
}