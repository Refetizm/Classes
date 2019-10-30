#ifndef __SECOND_CUTSCENE_H__
#define __SECOND_CUTSCENE_H__

#include "cocos2d.h"
#include "CutsceneMaterials.h"

class SecondCutScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
private:
	cocos2d::Sprite* cutsceneChar;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::SpriteBatchNode* cutsceneBatchNode;

	BossSpeechOne* bossSpeechOne;
	BossSpeechTwo* bossSpeechTwo;
	BossSpeechThree* bossSpeechThree;
	BossSpeechFour* bossSpeechFour;
	BossSpeechFive* bossSpeechFive;
	BossSpeechSix* bossSpeechSix;
	BossSpeechSeven* bossSpeechSeven;
	BossSpeechEight* bossSpeechEight;
	BossSpeechNine* bossSpeechNine;
	BossSpeechTen* bossSpeechTen;
	BossSpeechEleven* bossSpeechEleven;
	BossSpeechTwelve* bossSpeechTwelve;
	BossSpeechThirteen* bossSpeechThirteen;
	BossSpeechFourteen* bossSpeechFourteen;
	BossSpeechFifteen* bossSpeechFifteen;
	BossSpeechSixteen* bossSpeechSixteen;
	BossSpeechSeventeen* bossSpeechSeventeen;
	BossSpeechEighteen* bossSpeechEighteen;
	BossSpeechNineteen* bossSpeechNineteen;
	BossSpeechTwenty* bossSpeechTwenty;
	BossSpeechTwentyOne* bossSpeechTwentyOne;
	BossSpeechTwentyTwo* bossSpeechTwentyTwo;
	BossSpeechTwentyThree* bossSpeechTwentyThree;
	BossSpeechTwentyFour* bossSpeechTwentyFour;
	BossSpeechTwentyFive* bossSpeechTwentyFive;
	BossSpeechTwentySix* bossSpeechTwentySix;
	BossSpeechTwentySeven* bossSpeechTwentySeven;
	BossSpeechTwentyEight* bossSpeechTwentyEight;
	BossSpeechTwentyNine* bossSpeechTwentyNine;
    
    

	BigHead* bigHead;
	Sorcerer* sorcerer;
	Magic* magic;
	CannonBall* cannonBall;


	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void GoToBossScene(cocos2d::Ref* psender);
    // implement the "static create()" method manually
    CREATE_FUNC(SecondCutScene);
};

#endif // __SECOND_CUTSCENE_H__
