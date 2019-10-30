#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
private:
	void GoToGameScene(cocos2d::Ref* sender);
	void GoToExit(cocos2d::Ref* psender);
	void GoToMainMenuScene(cocos2d::Ref* psender);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);
};

#endif // __GAME_OVER_SCENE_H__
