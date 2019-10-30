#ifndef __COCOS_SCENE_H__
#define __COCOS_SCENE_H__

#include "cocos2d.h"

class CocosScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(CocosScene);

private:
	void GoToMainMenuScene(float dt);

};

#endif // __COCOS_SCENE_H__
