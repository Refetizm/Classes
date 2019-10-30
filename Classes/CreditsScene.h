#ifndef __CREDITS_SCENE_H__
#define __CREDITS_SCENE_H__

#include "cocos2d.h"

class CreditsScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void GoToMainMenuScene(cocos2d::Ref* psender);
    // implement the "static create()" method manually
    CREATE_FUNC(CreditsScene);
};

#endif // __CREDITS_SCENE_H__
