#include "SplashScene.h"
#include "Definitions.h"
#include "CocosScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    return SplashScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SplashScene::init()
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
	this->scheduleOnce(schedule_selector(SplashScene::GoToCocosScene), DISPLAY_TIME_SPLASH_SCENE);
	auto splashSprite = Sprite::create("Backgrounds/SplashScene.png");
	splashSprite->setAnchorPoint(Vec2(0.0, 0.0));
	splashSprite->setPosition(Point(0, 0));
	this->addChild(splashSprite);

    /////////////////////////////
    // 3. add your codes below...

    return true;
}

void SplashScene::GoToCocosScene(float dt)
{
	auto scene = CocosScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

