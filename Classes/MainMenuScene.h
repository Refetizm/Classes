#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"
#include "GameScene.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);

private:
	void GoToGameScene(cocos2d::Ref *sender);
	void GoToCreditsScene(cocos2d::Ref* sender);
	void GoToExit(cocos2d::Ref* psender);
	void GoToGitHubScene(cocos2d::Ref* psender);
};

#endif // __MAIN_MENU_SCENE_H__
