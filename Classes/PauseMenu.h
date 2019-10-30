#ifndef __PAUSE_MENU_H__
#define __PAUSE_MENU_H__

#include "cocos2d.h"

class PauseMenu
{
public:
	PauseMenu(cocos2d::Layer* layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Layer* layer;
	void ReturnToGameScene(cocos2d::Ref* psender);

};

#endif // __PAUSE_MENU_H__
