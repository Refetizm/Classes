#include "BossOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "BossScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* BossOverScene::createScene()
{
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = BossOverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool BossOverScene::init()
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
    
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/GameOver.mp3");

	auto musicDelayer = DelayTime::create(1);
	auto musicSeq = Sequence::create(musicDelayer, (CallFunc::create([this]()
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/GameOver.mp3");
		})), nullptr);
	this->runAction(musicSeq);




	/*------BACKGROUND IMAGE------*/
	auto menuSprite = Sprite::create("Backgrounds/MenuBackground.png");
	menuSprite->setAnchorPoint(Vec2(0.0, 0.0));
	menuSprite->setPosition(Point(0, 0));
	this->addChild(menuSprite);
	/*----------------------------*/


	auto logoSprite = Sprite::create("Materials/GameLogo.png");
	logoSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 4 + origin.y));
	this->addChild(logoSprite, 1);

	auto retryItem = MenuItemImage::create("Materials/Retry.png", "Materials/RetryClicked.png", CC_CALLBACK_1(BossOverScene::GoToRetryScene, this));
	retryItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 3));

	auto playItem = MenuItemImage::create("Materials/NewGame.png", "Materials/NewGameClicked.png", CC_CALLBACK_1(BossOverScene::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 2.7));

	auto mainMenuItem = MenuItemImage::create("Materials/MainMenu.png", "Materials/MainMenuClicked.png", CC_CALLBACK_1(BossOverScene::GoToMainMenuScene, this));
	mainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 2.4));

	auto exitItem = MenuItemImage::create("Materials/Exit.png", "Materials/ExitClicked.png", CC_CALLBACK_1(BossOverScene::GoToExitScene, this));
	exitItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 2.1));



	auto menu = Menu::create(retryItem, playItem, mainMenuItem, exitItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);






	/////////////////////////////
	// 3. add your codes below...

	return true;
}

void BossOverScene::GoToRetryScene(cocos2d::Ref* psender)
{
	auto scene = BossScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void BossOverScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void BossOverScene::GoToMainMenuScene(cocos2d::Ref* psender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void BossOverScene::GoToExitScene(cocos2d::Ref* psender)
{
	Director::getInstance()->end();
}