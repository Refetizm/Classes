#ifndef __CUTSCENE_MATERIALS_H__
#define __CUTSCENE_MATERIALS_H__

#include "cocos2d.h"
#include "CCLabelBMFontAnimated.h"

/*==========FIRST CUTSCENE==========*/
class NpcOne
{
public:
	NpcOne(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* npcOneSprite;
	cocos2d::SpriteBatchNode* npcOneBatchNode;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

};

class NpcTwo
{
public:
	NpcTwo(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* npcTwoSprite;
	cocos2d::SpriteBatchNode* npcTwoBatchNode;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

class SpeechOne
{
public:
	SpeechOne(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechTwo
{
public:
	SpeechTwo(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechThree
{
public:
	SpeechThree(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechFour
{
public:
	SpeechFour(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechFive
{
public:
	SpeechFive(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechSix
{
public:
	SpeechSix(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechSeven
{
public:
	SpeechSeven(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechEight
{
public:
	SpeechEight(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechNine
{
public:
	SpeechNine(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechTen
{
public:
	SpeechTen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechEleven
{
public:
	SpeechEleven(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class AngerMeter
{
public:
	AngerMeter(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* angerSprite;
	cocos2d::SpriteBatchNode* angerBatchNode;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

class RageMode
{
public:
	RageMode(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* rageModeSprite;
	cocos2d::SpriteBatchNode* rageBatchNode;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

class SpeechTwelve
{
public:
	SpeechTwelve(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechThirteen
{
public:
	SpeechThirteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechFourteen
{
public:
	SpeechFourteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechFifteen
{
public:
	SpeechFifteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class SpeechSixteen
{
public:
	SpeechSixteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

/*==========SECOND CUTSCENE==========*/

class BossSpeechOne
{
public:
	BossSpeechOne(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwo
{
public:
	BossSpeechTwo(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechThree
{
public:
	BossSpeechThree(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechFour
{
public:
	BossSpeechFour(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechFive
{
public:
	BossSpeechFive(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechSix
{
public:
	BossSpeechSix(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechSeven
{
public:
	BossSpeechSeven(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechEight
{
public:
	BossSpeechEight(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechNine
{
public:
	BossSpeechNine(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTen
{
public:
	BossSpeechTen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechEleven
{
public:
	BossSpeechEleven(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwelve
{
public:
	BossSpeechTwelve(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechThirteen
{
public:
	BossSpeechThirteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechFourteen
{
public:
	BossSpeechFourteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechFifteen
{
public:
	BossSpeechFifteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechSixteen
{
public:
	BossSpeechSixteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechSeventeen
{
public:
	BossSpeechSeventeen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechEighteen
{
public:
	BossSpeechEighteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechNineteen
{
public:
	BossSpeechNineteen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwenty
{
public:
	BossSpeechTwenty(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentyOne
{
public:
	BossSpeechTwentyOne(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentyTwo
{
public:
	BossSpeechTwentyTwo(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentyThree
{
public:
	BossSpeechTwentyThree(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentyFour
{
public:
	BossSpeechTwentyFour(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentyFive
{
public:
	BossSpeechTwentyFive(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentySix
{
public:
	BossSpeechTwentySix(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentySeven
{
public:
	BossSpeechTwentySeven(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentyEight
{
public:
	BossSpeechTwentyEight(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class BossSpeechTwentyNine
{
public:
	BossSpeechTwentyNine(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};










class BigHead
{
public:
	BigHead(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* headSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

class Sorcerer
{
public:
	Sorcerer(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* sorcererSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::SpriteBatchNode* sorcererBatchNode;
};

class Magic
{
public:
	Magic(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* magicSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::SpriteBatchNode* magicBatchNode;
};

class CannonBall
{
public:
	CannonBall(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* cannonSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

/*==========THIRD CUTSCENE==========*/
class EndSpeechOne
{
public:
	EndSpeechOne(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechTwo
{
public:
	EndSpeechTwo(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechThree
{
public:
	EndSpeechThree(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechFour
{
public:
	EndSpeechFour(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechFive
{
public:
	EndSpeechFive(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechSix
{
public:
	EndSpeechSix(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechSeven
{
public:
	EndSpeechSeven(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechEight
{
public:
	EndSpeechEight(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechNine
{
public:
	EndSpeechNine(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};

class EndSpeechTen
{
public:
	EndSpeechTen(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* speechSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	CCLabelBMFontAnimated* label;
	cocos2d::Label* title;
};
















class BadgeScene
{
public:
	BadgeScene(cocos2d::Layer* layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

class FirstHailScene
{
public:
	FirstHailScene(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* hailSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

class SecondHailScene
{
public:
	SecondHailScene(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* hailSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};

#endif // __CUTSCENE_MATERIALS_H__
