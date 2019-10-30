#include "ThirdCutscene.h"
#include "Definitions.h"
#include "CreditsScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* ThirdCutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ThirdCutScene::create();
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
bool ThirdCutScene::init()
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
    
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/ThirdCutscene.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/ThirdCutscene.mp3");

	auto cutsceneBackground = Sprite::create("Backgrounds/Masomo2.png");
	cutsceneBackground->setAnchorPoint(Vec2(0.0, 0.0));
	cutsceneBackground->setPosition(Point(0, 0));
	this->addChild(cutsceneBackground, 1);

	auto bossSprite = Sprite::create("SpriteSheets/Boss-Idle.png");
	bossSprite->setAnchorPoint(Vec2(0.0, 0.0));
	bossSprite->setPosition(Point(visibleSize.width / 2 + origin.x + 100, 45));
	this->addChild(bossSprite, 5);

	auto characterSprite = Sprite::create("Spritesheets/BigHeadIdle-Left.png");
	characterSprite->setAnchorPoint(Vec2(1.0, 0.0));
	characterSprite->setPosition(Point(visibleSize.width / 2 + origin.x - 100, 45));
	this->addChild(characterSprite, 3);
	auto nodeScene = Node::create();
	auto bubleDelayer = DelayTime::create(3.5);
	auto badgeDelayer = DelayTime::create(14);
	auto sceneStartSeq = Sequence::create(bubleDelayer, (CallFunc::create([this]()
		{
			endSpeechOne = new EndSpeechOne(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechTwo = new EndSpeechTwo(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechThree = new EndSpeechThree(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechFour = new EndSpeechFour(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechFive = new EndSpeechFive(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			badgeScene = new BadgeScene(this);
		})), badgeDelayer,
		(CallFunc::create([this]()
		{
			endSpeechSix = new EndSpeechSix(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechSeven = new EndSpeechSeven(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechEight = new EndSpeechEight(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechNine = new EndSpeechNine(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			endSpeechTen = new EndSpeechTen(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
			firstHailScene = new FirstHailScene(this);
		})), bubleDelayer, 
		(CallFunc::create([this]()
		{
			secondHailScene = new SecondHailScene(this);
		})), bubleDelayer,
		(CallFunc::create([this]()
		{
					Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_END_TIME, CreditsScene::createScene()));
		})), nullptr);

	nodeScene->runAction(sceneStartSeq);
	this->addChild(nodeScene);




	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(ThirdCutScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);


    /////////////////////////////
    // 3. add your codes below...

    return true;
}

bool ThirdCutScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto skipItem = MenuItemImage::create("Materials/Skip.png", "Materials/SkipClicked.png", CC_CALLBACK_1(ThirdCutScene::GoToCreditsScene, this));
	skipItem->setPosition(Point(1670, 540));

	auto menu = Menu::create(skipItem, NULL);
	menu->setTag(5);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 150);
	return true;
}

void ThirdCutScene::GoToCreditsScene(cocos2d::Ref* psender)
{
	auto scene = CreditsScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}