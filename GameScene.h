#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Character.h"
#include "TeamPipe.h"
#include "Items.h"
#include "RoadBlock.h"
#include "PauseMenu.h"



class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	
	
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);


private:
	cocos2d::PhysicsWorld* sceneWorld;
	void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

	bool onContactBegin(cocos2d::PhysicsContact &contact);
	bool onRoadContactBegin(cocos2d::PhysicsContact& roadContact);
	bool onMistralContactBegin(cocos2d::PhysicsContact& mistralContact);
	

	bool onTshirtContactBegin(cocos2d::PhysicsContact& tshirtContact);
	bool onNetflixContactBegin(cocos2d::PhysicsContact& netflixContact);
	bool onIPadContactBegin(cocos2d::PhysicsContact& ipadContact);
	bool onBagPackContactBegin(cocos2d::PhysicsContact& bagpackContact);
	bool onMugContactBegin(cocos2d::PhysicsContact& mugContact);
	bool onThermosContactBegin(cocos2d::PhysicsContact& thermosContact);
	bool oniTunesContactBegin(cocos2d::PhysicsContact& itunesContact);
	bool onMasomoBoxContactBegin(cocos2d::PhysicsContact& masomoBoxContact);
	bool onMacBookContactBegin(cocos2d::PhysicsContact& macbookContact);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void StopFlying(float dt);
	void update(float dt);
	void GoToPauseMenuScene(cocos2d::Ref* psender);
	void GoToResumeScene(cocos2d::Ref* psender);
	void GoToRetryScene(cocos2d::Ref* psender);
	void GoToMainMenuScene(cocos2d::Ref* psender);
	void GoToExitScene(cocos2d::Ref* psender);

	PauseMenu* pauseMenu;
	Character* character;
	RoadBlock* roadBlock;
	TeamPipe* teamPipe;

	CocosPipe* cocosPipe;

	EnglishPipe* englishPipe;
	CleanPipe* cleanPipe;
	UnityPipe* unityPipe;
	CsharpPipe* csharpPipe;
	GamesPipe* gamesPipe;
	CppPipe* cppPipe;
	Mistral* mistral;

	TShirt* tshirt;
	Netflix* netflix;
	IPad* iPad;
	BagPack* bagPack;
	Mug* mug;
	Thermos* thermos;
	iTunes* itunes;
	MasomoBox* masomoBox;
	MacBook* macbook;

	
	cocos2d::Menu* menu;
	



	

};




#endif // __GAME_SCENE_H__