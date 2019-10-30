#include "GameOverScene.h"
#include "Definitions.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOverScene::create();

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
bool GameOverScene::init()
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

	auto playItem = MenuItemImage::create("Materials/NewGame.png", "Materials/NewGameClicked.png", CC_CALLBACK_1(GameOverScene::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 3));

	auto mainMenuItem = MenuItemImage::create("Materials/MainMenu.png", "Materials/MainMenuClicked.png", CC_CALLBACK_1(GameOverScene::GoToMainMenuScene, this));
	mainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 2.7));

	auto exitItem = MenuItemImage::create("Materials/Exit.png", "Materials/ExitClicked.png", CC_CALLBACK_1(GameOverScene::GoToExit, this));
	exitItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 5 * 2.4));

	

	auto menu = Menu::create(playItem, mainMenuItem, exitItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);






    /////////////////////////////
    // 3. add your codes below...

    return true;
}

void GameOverScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOverScene::GoToMainMenuScene(cocos2d::Ref* psender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOverScene::GoToExit(cocos2d::Ref* psender)
{
	Director::getInstance()->end();
}