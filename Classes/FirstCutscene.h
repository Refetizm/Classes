#ifndef __FIRST_CUTSCENE_H__
#define __FIRST_CUTSCENE_H__

#include "cocos2d.h"
#include "CutsceneMaterials.h"

class FirstCutScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

	virtual bool init();
private:
	cocos2d::PhysicsWorld* sceneWorld;
	void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
	bool onEventContactBegin(cocos2d::PhysicsContact& contact);
	cocos2d::Sprite* cutsceneChar;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::SpriteBatchNode* cutsceneBatchNode;
	NpcOne* npcOne;
	NpcTwo* npcTwo;
	SpeechOne* speechOne;
	SpeechTwo* speechTwo;
	SpeechThree* speechThree;
	SpeechFour* speechFour;
	SpeechFive* speechFive;
	SpeechSix* speechSix;
	SpeechSeven* speechSeven;
	SpeechEight* speechEight;
	SpeechNine* speechNine;
	SpeechTen* speechTen;
	SpeechEleven* speechEleven;
	SpeechTwelve* speechTwelve;
	SpeechThirteen* speechThirteen;
	SpeechFourteen* speechFourteen;
	SpeechFifteen* speechFifteen;
	SpeechSixteen* speechSixteen;
	AngerMeter* angerMeter;
	RageMode* rageMode;

	void GoToGameScene(cocos2d::Ref* sender);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	
    // implement the "static create()" method manually
    CREATE_FUNC(FirstCutScene);
};




#endif // __FIRST_CUTSCENE_H__
