#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "cocos2d.h"
/*----------TSHIRT----------*/
class TShirt
{
public:
	TShirt(cocos2d::Layer* layer);
	void tShirtOrder() { tShirtSprite->removeAllComponents(); tShirtSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* tShirtSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------NETFLIX----------*/
class Netflix
{
public:
	Netflix(cocos2d::Layer* layer);
	void netflixOrder() { netflixSprite->removeAllComponents(); netflixSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* netflixSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------IPAD----------*/
class IPad
{
public:
	IPad(cocos2d::Layer* layer);
	void iPadOrder() { iPadSprite->removeAllComponents(); iPadSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* iPadSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------BAGPACK----------*/
class BagPack
{
public:
	BagPack(cocos2d::Layer* layer);
	void bagPackOrder() { bagPackSprite->removeAllComponents(); bagPackSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* bagPackSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------BAGPACK----------*/
class Mug
{
public:
	Mug(cocos2d::Layer* layer);
	void mugOrder() { mugSprite->removeAllComponents(); mugSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* mugSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------THERMOS----------*/
class Thermos
{
public:
	Thermos(cocos2d::Layer* layer);
	void thermosOrder() { thermosSprite->removeAllComponents(); thermosSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* thermosSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------ITUNES----------*/
class iTunes
{
public:
	iTunes(cocos2d::Layer* layer);
	void itunesOrder() { itunesSprite->removeAllComponents(); itunesSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* itunesSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------MASOMOBOX----------*/
class MasomoBox
{
public:
	MasomoBox(cocos2d::Layer* layer);
	void masomoBoxOrder() { masomoBoxSprite->removeAllComponents(); masomoBoxSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* masomoBoxSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
/*----------MACBOOK----------*/
class MacBook
{
public:
	MacBook(cocos2d::Layer* layer);
	void macbookOrder() { macbookSprite->removeAllComponents(); macbookSprite->setLocalZOrder(-5); }
private:
	cocos2d::Sprite* macbookSprite;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
#endif // __ITEMS_H__
