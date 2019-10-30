#ifndef __THIRD_CUTSCENE_H__
#define __THIRD_CUTSCENE_H__

#include "cocos2d.h"
#include "CutsceneMaterials.h"

class ThirdCutScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
private:
	EndSpeechOne* endSpeechOne;
	EndSpeechTwo* endSpeechTwo;
	EndSpeechThree* endSpeechThree;
	EndSpeechFour* endSpeechFour;
	EndSpeechFive* endSpeechFive;
	EndSpeechSix* endSpeechSix;
	EndSpeechSeven* endSpeechSeven;
	EndSpeechEight* endSpeechEight;
	EndSpeechNine* endSpeechNine;
	EndSpeechTen* endSpeechTen;



	BadgeScene* badgeScene;
	FirstHailScene* firstHailScene;
	SecondHailScene* secondHailScene;
    
    

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void GoToCreditsScene(cocos2d::Ref* psender);

    // implement the "static create()" method manually
    CREATE_FUNC(ThirdCutScene);
};

#endif // __THIRD_CUTSCENE_H__
