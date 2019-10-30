#include "PauseMenu.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

PauseMenu::PauseMenu(cocos2d::Layer* layer)
{
	auto menuBackground = Sprite::create("Backgrounds/PauseMenuBackground.png");
	menuBackground->setTag(1);
	menuBackground->setPosition(Point(960, 540));
	layer->addChild(menuBackground, 150);


	auto resumeItem = MenuItemImage::create("Materials/Resume.png", "Materials/ResumeClicked.png", CC_CALLBACK_1(PauseMenu::ReturnToGameScene, this));
	resumeItem->setPosition(Point(960, 600));

	auto menu = Menu::create(resumeItem, NULL);
	menu->setTag(2);
	menu->setPosition(Point::ZERO);
	layer->addChild(menu, 151);
}
	
void PauseMenu::ReturnToGameScene(cocos2d::Ref* psender)
{
	layer->setLocalZOrder(-5);
}
    


