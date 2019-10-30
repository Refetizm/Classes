#ifndef __BOSS_OVER_SCENE_H__
#define __BOSS_OVER_SCENE_H__

#include "cocos2d.h"

class BossOverScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
private:
	void GoToRetryScene(cocos2d::Ref* psender);
	void GoToGameScene(cocos2d::Ref* psender);
	void GoToMainMenuScene(cocos2d::Ref* psender);
	void GoToExitScene(cocos2d::Ref* psender);

    
    
    // implement the "static create()" method manually
    CREATE_FUNC(BossOverScene);
};

#endif // __BOSS_OVER_SCENE_H__
