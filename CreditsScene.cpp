#include "CreditsScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* CreditsScene::createScene()
{
    return CreditsScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool CreditsScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. SPRITE SECTION
    //    You can add your sprites below...
	/////////////////////////////

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/CreditsScene.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/CreditsScene.mp3");


	auto creditsBackground = Sprite::create("Backgrounds/Credits.png");
	creditsBackground->setAnchorPoint(Vec2(0.0, 1.0));
	creditsBackground->setPosition(Point(0, 0));
	this->addChild(creditsBackground, 1);

	auto creditsAction = RepeatForever::create(MoveBy::create(1, Point(0, 90)));
	creditsBackground->runAction(creditsAction);
	

	

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(CreditsScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool CreditsScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto skipItem = MenuItemImage::create("Materials/Skip.png", "Materials/SkipClicked.png", CC_CALLBACK_1(CreditsScene::GoToMainMenuScene, this));
	skipItem->setPosition(Point(1670, 540));

	auto menu = Menu::create(skipItem, NULL);
	menu->setTag(5);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 150);
	return true;
}

void CreditsScene::GoToMainMenuScene(cocos2d::Ref* psender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
