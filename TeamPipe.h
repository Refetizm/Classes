#ifndef __TEAM_PIPE_H__
#define __TEAM_PIPE_H__

#include "cocos2d.h"
/*----------FIRST PIPE----------*/
class TeamPipe
{
public:
	TeamPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* teamPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------SECOND PIPE----------*/
class CocosPipe
{
public:
	CocosPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* cocosPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------THIRD PIPE----------*/
class EnglishPipe
{
public:
	EnglishPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* englishPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------FOURTH PIPE----------*/
class CleanPipe
{
public:
	CleanPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* cleanPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------FIFTH PIPE----------*/
class UnityPipe
{
public:
	UnityPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* unityPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------SIXTH PIPE----------*/
class CsharpPipe
{
public:
	CsharpPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* csharpPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------SEVENTH PIPE----------*/
class GamesPipe
{
public:
	GamesPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* gamesPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------EIGHTH PIPE----------*/
class CppPipe
{
public:
	CppPipe(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* cppPipeSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------END LEVEL SPRITE----------*/
class Mistral
{
public:
	Mistral(cocos2d::Layer* layer);
private:
	cocos2d::Sprite* mistralSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
#endif // __TEAM_PIPE_H__
