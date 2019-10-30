#include "SecondCutscene.h"
#include "Definitions.h"
#include "BossScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SecondCutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SecondCutScene::create();
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
bool SecondCutScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/SecondCutscene.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/SecondCutscene.mp3");

	auto cutsceneBackground = Sprite::create("Backgrounds/Masomo2.png");
	cutsceneBackground->setAnchorPoint(Vec2(0.0, 0.0));
	cutsceneBackground->setPosition(Point(0, 0));
	this->addChild(cutsceneBackground, 1);

	auto bossSprite = Sprite::create("SpriteSheets/Boss-Idle.png");
	bossSprite->setAnchorPoint(Vec2(0.0, 0.0));
	bossSprite->setPosition(Point(1725, 45));
	this->addChild(bossSprite, 3);

	cutsceneBatchNode = SpriteBatchNode::create("SpriteSheets/SecondCutsceneChar.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/SecondCutsceneChar.plist");
	cutsceneChar = Sprite::createWithSpriteFrameName("SecondCutsceneChar1.png");
	cutsceneChar->setAnchorPoint(Vec2(0.0, 0.0));
	cutsceneBatchNode->addChild(cutsceneChar);
	cutsceneBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	cutsceneBatchNode->setPosition(Point(-150, 45));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 6; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("SecondCutsceneChar%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	cutsceneChar->runAction(animate);
	this->addChild(cutsceneBatchNode, 3);

	auto charMove = MoveTo::create(4, Point(100, 45));
	cutsceneBatchNode->runAction(charMove);

    /////////////////////////////
    // 2. SPRITE SECTION
    //    You can add your sprites below...
	/////////////////////////////
	auto nodeScene = Node::create();

	auto oneSecDelayer = DelayTime::create(1);
	auto bubleDelayer = DelayTime::create(3.5);
	auto sceneStartDelayer = DelayTime::create(4);
	auto magicDelayer = DelayTime::create(7);
	auto cannonDelayer = DelayTime::create(10);

	auto sceneStartSeq = Sequence::create(sceneStartDelayer, (CallFunc::create([this]() 
		{
			cutsceneBatchNode->setLocalZOrder(-5);
			auto idleSprite = Sprite::create("SpriteSheets/CharacterIdle-Left.png");
			idleSprite->setAnchorPoint(Vec2(0.0, 0.0));
			idleSprite->setPosition(Point(100, 45));
			this->addChild(idleSprite, 5);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechOne = new BossSpeechOne(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwo = new BossSpeechTwo(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechThree = new BossSpeechThree(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechFour = new BossSpeechFour(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechFive = new BossSpeechFive(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechSix = new BossSpeechSix(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bigHead = new BigHead(this);
		})), bubleDelayer, oneSecDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechSeven = new BossSpeechSeven(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechEight = new BossSpeechEight(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechNine = new BossSpeechNine(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTen = new BossSpeechTen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				sorcerer = new Sorcerer(this);
		})), magicDelayer,
		(CallFunc::create([this]()
		{
				magic = new Magic(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechEleven = new BossSpeechEleven(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwelve = new BossSpeechTwelve(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechThirteen = new BossSpeechThirteen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechFourteen = new BossSpeechFourteen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechFifteen = new BossSpeechFifteen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechSixteen = new BossSpeechSixteen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechSeventeen = new BossSpeechSeventeen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechEighteen = new BossSpeechEighteen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechNineteen = new BossSpeechNineteen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwenty = new BossSpeechTwenty(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				cannonBall = new CannonBall(this);
		})), cannonDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentyOne = new BossSpeechTwentyOne(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentyTwo = new BossSpeechTwentyTwo(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentyThree = new BossSpeechTwentyThree(this);
		})), bubleDelayer, 
		(CallFunc::create([this]()
		{
				bossSpeechTwentyFour = new BossSpeechTwentyFour(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentyFive = new BossSpeechTwentyFive(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentySix = new BossSpeechTwentySix(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentySeven = new BossSpeechTwentySeven(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentyEight = new BossSpeechTwentyEight(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
				bossSpeechTwentyNine = new BossSpeechTwentyNine(this);
		})), bubleDelayer, 
		(CallFunc::create([this]() 
		{
				Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, BossScene::createScene())); 
		})), nullptr);











	nodeScene->runAction(sceneStartSeq);
	this->addChild(nodeScene);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(SecondCutScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);


    /////////////////////////////
    // 3. add your codes below...

    return true;
}

bool SecondCutScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto skipItem = MenuItemImage::create("Materials/Skip.png", "Materials/SkipClicked.png", CC_CALLBACK_1(SecondCutScene::GoToBossScene, this));
	skipItem->setPosition(Point(1670, 540));

	auto menu = Menu::create(skipItem, NULL);
	menu->setTag(5);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 150);
	return true;
}

void SecondCutScene::GoToBossScene(cocos2d::Ref* psender)
{
	auto scene = BossScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}