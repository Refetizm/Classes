#ifndef __BOSS_SCENE_H__
#define __BOSS_SCENE_H__

#include "cocos2d.h"
#include "CharacterFinal.h"
#include "Ball.h"
#include "BossBlock.h"

class BossScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(BossScene);

	bool endGame = false;
	
private:
	cocos2d::PhysicsWorld* bossWorld;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	bool onExplosionContactBegin(cocos2d::PhysicsContact& explosionContact);
	bool onScoreContactBegin(cocos2d::PhysicsContact& scoreContact);
	bool onOverContactBegin(cocos2d::PhysicsContact& overContact);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);


	void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { bossWorld = world; };
	void SpawnBall(float dt);
	void StopFlying(float dt);
	void update(float dt);

	void GoToPauseMenuScene(cocos2d::Ref* psender);
	void GoToResumeScene(cocos2d::Ref* psender);
	void GoToRetryScene(cocos2d::Ref* psender);
	void GoToNewGameScene(cocos2d::Ref* psender);
	void GoToMainMenuScene(cocos2d::Ref* psender);
	void GoToExitScene(cocos2d::Ref* psender);

	Ball ball;
	CharacterFinal* characterFinal;
	BossBlock* bossBlock;
	cocos2d::Sprite* explosionSprite;
	cocos2d::SpriteBatchNode* explosionBatchNode;
	cocos2d::Label* scoreLabel;
	cocos2d::Menu* menu;
	unsigned int score;
	unsigned int endingScore;





    
};

#endif // __BOSS_SCENE_H__
