#include "SplashScene.h"
#include "SimpleAudioEngine.h"
#include "CutsceneMaterials.h"

USING_NS_CC;

NpcOne::NpcOne(cocos2d::Layer* layer)
{
	npcOneBatchNode = SpriteBatchNode::create("SpriteSheets/Father-Idle.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/Father-Idle.plist");
	npcOneSprite = Sprite::createWithSpriteFrameName("Father1.png");
	npcOneSprite->setAnchorPoint(Vec2(0.0, 0.0));
	npcOneBatchNode->setTag(1);
	npcOneBatchNode->addChild(npcOneSprite);
	npcOneBatchNode->setScale(0.40);
	npcOneBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	npcOneBatchNode->setPosition(Point(385, 190));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 2; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("Father%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	npcOneSprite->runAction(animate);
	layer->addChild(npcOneBatchNode, 3);

	auto npcOneMover = MoveTo::create(3, Point(385, 100));
	auto npcOneScaler = ScaleTo::create(3, 0.5);
	npcOneBatchNode->runAction(npcOneMover);
	npcOneBatchNode->runAction(npcOneScaler);
	auto npcOneDelayer = DelayTime::create(3);
	auto npcOneSeq = Sequence::create(npcOneDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1);
			auto npcIdle = Sprite::create("SpriteSheets/Father-Right.png");
			npcIdle->setScale(0.5);
			npcIdle->setAnchorPoint(Vec2(0.0, 0.0));
			npcIdle->setPosition(Point(385, 100));
			layer->addChild(npcIdle, 3); }),
		nullptr);
	layer->runAction(npcOneSeq);
}

NpcTwo::NpcTwo(cocos2d::Layer* layer)
{
	npcTwoBatchNode = SpriteBatchNode::create("SpriteSheets/Ogz-Idle.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/Ogz-Idle.plist");
	npcTwoSprite = Sprite::createWithSpriteFrameName("Ogz1.png");
	npcTwoSprite->setAnchorPoint(Vec2(0.0, 0.0));
	npcTwoBatchNode->setTag(1);
	npcTwoBatchNode->addChild(npcTwoSprite);
	npcTwoBatchNode->setScale(0.40);
	npcTwoBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	npcTwoBatchNode->setPosition(Point(575, 190));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 2; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("Ogz%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	npcTwoSprite->runAction(animate);
	layer->addChild(npcTwoBatchNode, 3);

	auto npcTwoMover = MoveTo::create(3, Point(575, 100));
	auto npcTwoScaler = ScaleTo::create(3, 0.5);
	npcTwoBatchNode->runAction(npcTwoMover);
	npcTwoBatchNode->runAction(npcTwoScaler);
	auto npcTwoDelayer = DelayTime::create(3);
	auto npcTwoSeq = Sequence::create(npcTwoDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1);
			auto npcIdle = Sprite::create("SpriteSheets/Ogz-Right.png");
			npcIdle->setScale(0.5);
			npcIdle->setAnchorPoint(Vec2(0.0, 0.0));
			npcIdle->setPosition(Point(575, 100));
			layer->addChild(npcIdle, 3); }),
		nullptr);
	layer->runAction(npcTwoSeq);
}

SpeechOne::SpeechOne(cocos2d::Layer* layer)
{
	
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("WHERE_HAVE_YOU_BEEN?");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(225, 265));
	layer->addChild(speechSprite, 5);
	
	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);
	
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Jumper.wav", true, 3.0);
	

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);

	
}

SpeechTwo::SpeechTwo(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	
	label->setString("WE_HAVE_DOZENS_OF_PAPERWORK!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(335, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechThree::SpeechThree(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("I_WROTE_CODE_UNTIL_DAWN.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(200, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechFour::SpeechFour(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("ALSO_THE_TIME_IS_YET_09:00AM.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(100, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechFive::SpeechFive(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("DON'T_MAKE_ME_FUCK_YOUR_CODE!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(150, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechSix::SpeechSix(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("FIRST_YOU_HAVE_TO_GO_TO_THE_LAND_OF_REGISTRY_OFFICE.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(-50, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechSeven::SpeechSeven(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("AND_THEN_YOU_MUST_GO_TO_THE_MUNICIPLATIY!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(225, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechEight::SpeechEight(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("YOU_MUST_FILL_OUT_THESE_PAPERS!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(125, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(2);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechNine::SpeechNine(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("YOU_MUST_UPDATE_ADVERTS!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(375, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(2);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechTen::SpeechTen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("BLA_BLA_BLA!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(0.5);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(325, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(1);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechEleven::SpeechEleven(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("BLA_BLA_BLA!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(0.5);

	speechSprite = Sprite::create("Materials/SpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(515, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(1);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

AngerMeter::AngerMeter(cocos2d::Layer* layer)
{
	angerBatchNode = SpriteBatchNode::create("SpriteSheets/AngerMeter.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/AngerMeter.plist");
	angerSprite = Sprite::createWithSpriteFrameName("AngerMeter1.png");
	angerSprite->setAnchorPoint(Vec2(0.0, 0.0));
	angerBatchNode->addChild(angerSprite);
	angerBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	angerBatchNode->setPosition(Point(1750, 329));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 71; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("AngerMeter%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 0.38f);
	animation->setLoops(1);
	auto animate = Animate::create(animation);
	angerSprite->runAction(animate);
	layer->addChild(angerBatchNode, 3);
	
	auto angerModeEndDelayer = DelayTime::create(27);
	auto angerModeEndSeq = Sequence::create(angerModeEndDelayer,
		CallFunc::create([=]() -> void {

			angerBatchNode->setLocalZOrder(-5); }),
		nullptr);
	layer->runAction(angerModeEndSeq);
}

RageMode::RageMode(cocos2d::Layer* layer)
{
	auto rageModeBackground = Sprite::create("Backgrounds/RageAnim-Background.png");
	rageModeBackground->setAnchorPoint(Vec2(0.0, 0.0));
	rageModeBackground->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	layer->addChild(rageModeBackground, 10);

	rageModeSprite = Sprite::create("SpriteSheets/RageCharacter-First.png");
	rageModeSprite->setPosition(Point(960, -540));
	layer->addChild(rageModeSprite, 12);

	auto rageModeFirstAction = MoveTo::create(0.3, Point(960, -250));
	auto rageModeRotateLeft = RotateBy::create(0.1, -5);
	auto rageModeRotateRight = RotateBy::create(0.1, 5);
	auto rageModeFirstSeq = Sequence::create(rageModeRotateLeft, rageModeRotateRight, nullptr);
	auto rageModeFirstRepeater = RepeatForever::create(rageModeFirstSeq);
	

	rageModeSprite->runAction(rageModeFirstAction);
	rageModeSprite->runAction(rageModeFirstRepeater);

	auto rageModeDelayer = DelayTime::create(1);
	auto rageModeSecondSeq = Sequence::create(rageModeDelayer, 
		CallFunc::create([=]() -> void {
			rageModeSprite->setTexture("SpriteSheets/RageCharacter-Second.png"); }), nullptr);
	rageModeSprite->runAction(rageModeSecondSeq);


	rageBatchNode = SpriteBatchNode::create("SpriteSheets/RageMode.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/RageMode.plist");
	auto rageModeBackgroundSprite = Sprite::createWithSpriteFrameName("RageMode1.png");
	rageModeBackgroundSprite->setAnchorPoint(Vec2(0.0, 0.0));
	rageBatchNode->addChild(rageModeBackgroundSprite);
	rageBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	rageBatchNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 2; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("RageMode%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 1.0f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	rageModeBackgroundSprite->runAction(animate);
	layer->addChild(rageBatchNode, 11);

	auto rageModeEndDelayer = DelayTime::create(5);
	auto rageModeEndSeq = Sequence::create(rageModeEndDelayer,
		CallFunc::create([=]() -> void {
			rageModeBackground->setLocalZOrder(-5);
			rageModeSprite->setLocalZOrder(-5);
			rageModeSprite->stopAction(rageModeFirstAction);
			rageModeSprite->stopAction(rageModeFirstRepeater);
			rageModeSprite->stopAction(rageModeFirstSeq);
			rageBatchNode->setLocalZOrder(-5); }), nullptr);
	layer->runAction(rageModeEndSeq);
}

SpeechTwelve::SpeechTwelve(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("FUCK_THIS_SHIT!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(0.5);

	speechSprite = Sprite::create("Materials/SpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(350, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechThirteen::SpeechThirteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("I'M_NOT_A_REAL_ESTATE_AGENT!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(0.5);

	speechSprite = Sprite::create("Materials/SpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(115, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechFourteen::SpeechFourteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("I'M_A_GAME_DEVELOPER...");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(0.5);

	speechSprite = Sprite::create("Materials/SpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(215, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechFifteen::SpeechFifteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);

	label->setString("I'M_GOING_TO_MASOMO!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(0.5);

	speechSprite = Sprite::create("Materials/SpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(230, 265));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

SpeechSixteen::SpeechSixteen(cocos2d::Layer* layer)
{
	speechSprite = Sprite::create("Materials/MasomoBuble.png");
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(320, 265));
	layer->addChild(speechSprite, 7);
}

/////////////////////////////////////////////////////

BossSpeechOne::BossSpeechOne(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("HELLO_STRANGER...");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwo::BossSpeechTwo(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("WELCOME_TO_MASOMO.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechThree::BossSpeechThree(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("MY_NAME_IS_IBRAHIM.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechFour::BossSpeechFour(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("OMG!_YOU_ARE_THE_BOSS!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(180, 365));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechFive::BossSpeechFive(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("BOSS???_YOU_LIVE_IN_THE_NINETIES?");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechSix::BossSpeechSix(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("I'M_THE_CEO!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechSeven::BossSpeechSeven(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("SHIT!_WHAT_HAPPENED_TO_MY_HEAD?");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(222, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechEight::BossSpeechEight(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("IT'S_OUR_SORCERER'S_MAGIC.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechNine::BossSpeechNine(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("ANYONE_WHO_STEPS_INTO_MASOMO...");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTen::BossSpeechTen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("...IS_AFFECTED_BY_HER_SPELL!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechEleven::BossSpeechEleven(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("OMG!_SHE'S_FLYING!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(222, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwelve::BossSpeechTwelve(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("AND_SHE_WORKS_FOR_MINIMUM_WAGE.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechThirteen::BossSpeechThirteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("SO,_ARE_YOU_READY_FOR_THE_FINAL_CHALLANGE?");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechFourteen::BossSpeechFourteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("HELL_YES!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(222, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechFifteen::BossSpeechFifteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("YOU'RE_GONNA_PLAY_BALL_AGAINST_ME....");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}


BossSpeechSixteen::BossSpeechSixteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("...IN_YOUR_LAST_CHALLANGE!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechSeventeen::BossSpeechSeventeen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("HEAD_BALL???");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(222, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechEighteen::BossSpeechEighteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("NO,_YOU_DUMBASS!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechNineteen::BossSpeechNineteen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("WE'RE_GONNA_PLAY_CANNON_BALL!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwenty::BossSpeechTwenty(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("CANNON_BALL?_WTF_IS_CANNON_BALL???");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(222, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentyOne::BossSpeechTwentyOne(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("THIS_IS_CANNON_BALL!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentyTwo::BossSpeechTwentyTwo(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("HOLY_SHIT!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(222, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentyThree::BossSpeechTwentyThree(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("YOUR_END_HAS_COME!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentyFour::BossSpeechTwentyFour(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("NO_ONE_HAS_EVER_BEATEN_ME.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentyFive::BossSpeechTwentyFive(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("BECAUSE_I_HAVE_USAIN_BOLT'S_SHOES.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentySix::BossSpeechTwentySix(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("ERDEM_YURDANUR_STOLE_THESE_FOR_ME!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentySeven::BossSpeechTwentySeven(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("WE_WILL_NOT_USE_OUR_FEET_ON_CANNON_BALL.");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Left.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(0.0, 0.0));
	speechSprite->setPosition(Point(222, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentyEight::BossSpeechTwentyEight(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("YOU_THINK_YOU'RE_SMART?!?!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

BossSpeechTwentyNine::BossSpeechTwentyNine(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("BRACE_YOURSELF!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1725, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}






BigHead::BigHead(cocos2d::Layer* layer)
{
	headSprite = Sprite::create("SpriteSheets/HeadSmall.png");
	headSprite->setAnchorPoint(Vec2(0.0, 0.0));
	headSprite->setPosition(Point(100, 275));
	layer->addChild(headSprite, 6);
	auto headAction = ScaleBy::create(3, 1.97);
	auto headMover = MoveBy::create(3, Point(-44, 0));
	headSprite->runAction(headAction);
	headSprite->runAction(headMover);
}

Sorcerer::Sorcerer(cocos2d::Layer* layer)
{
	sorcererBatchNode = SpriteBatchNode::create("SpriteSheets/CrazyWizard.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/CrazyWizard.plist");
	sorcererSprite = Sprite::createWithSpriteFrameName("CrazyWizard1.png");
	sorcererSprite->setAnchorPoint(Vec2(0.0, 0.0));
	sorcererBatchNode->addChild(sorcererSprite);
	sorcererBatchNode->setScale(0.7);
	sorcererBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	sorcererBatchNode->setPosition(Point(860, 1265));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 10; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("CrazyWizard%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	sorcererSprite->runAction(animate);
	layer->addChild(sorcererBatchNode, 3);

	auto charMove = MoveTo::create(7, Point(860, 715));
	sorcererBatchNode->runAction(charMove);

	auto carpetSprite = Sprite::create("Materials/Carpet.png");
	carpetSprite->setAnchorPoint(Vec2(0.0, 0.0));
	carpetSprite->setPosition(Point(880, 1250));
	layer->addChild(carpetSprite, 2);

	auto carpetMove = MoveTo::create(7, Point(880, 700));
	carpetSprite->runAction(carpetMove);
}

Magic::Magic(cocos2d::Layer* layer)
{
	
	auto magicBatchNode = SpriteBatchNode::create("SpriteSheets/Magic.png");
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpriteSheets/Magic.plist");
	auto magicSprite = Sprite::createWithSpriteFrameName("Magic1.png");
	magicSprite->setAnchorPoint(Vec2(0.0, 0.0));
	magicBatchNode->addChild(magicSprite);
	magicBatchNode->setAnchorPoint(Vec2(0.0, 0.0));
	magicBatchNode->setPosition(Point(220, 890));
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 2; i++)
	{
		std::string frameName = cocos2d::StringUtils::format("Magic%d.png", i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(frameName.c_str());
		frames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frames, 4.0f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	magicSprite->runAction(animate);
	layer->addChild(magicBatchNode, 3);
}

CannonBall::CannonBall(cocos2d::Layer* layer)
{
	cannonSprite = Sprite::create("Materials/CannonBall.png");
	cannonSprite->setAnchorPoint(Vec2(0.0, 0.0));
	cannonSprite->setPosition(1950, 45);
	layer->addChild(cannonSprite, 4);

	auto cannonMover = MoveTo::create(7, Point(1500, 45));
	cannonSprite->runAction(cannonMover);
}

/////////////////////////////////////////////////////

EndSpeechOne::EndSpeechOne(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("RAFET,_YOU_COLLECTED_ALL_THE_ITEMS...");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechTwo::EndSpeechTwo(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("...AND_BEAT_ME_AT_THE_CANNON_BALL!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechThree::EndSpeechThree(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("WITH_THE_AUTHORITY_THAT_GOD...");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechFour::EndSpeechFour(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("...AND_THE_COMPANY_PARTNERS_GAVE_ME,");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechFive::EndSpeechFive(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("I_DECLARE_YOU_A_MEMBER_OF_MASOMO!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechSix::EndSpeechSix(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("FROM_NOW_ON...");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechSeven::EndSpeechSeven(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("...EVERYONE_WILL_CALL_YOU...");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechEight::EndSpeechEight(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("!!!RAFET_THE_DEVELOPER!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechNine::EndSpeechNine(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("!!!HAIL_TO_RAFET!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

EndSpeechTen::EndSpeechTen(cocos2d::Layer* layer)
{
	label = CCLabelBMFontAnimated::createWithTTF("", "fonts/PressStart2P.ttf", 20.0f,
		Size(visibleSize.width, 40),
		cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	label->setString("!!!HAIL_TO_MASOMO!!!");

	std::string str = label->getString();

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '_')
		{
			label->getLetter(i)->setColor(Color3B::WHITE);
		}
		else {
			if (label->getLetter(i) != nullptr)
			{
				label->getLetter(i)->setColor(Color3B::BLACK);

			}
		}
	}

	label->animateInTypewriter(1);

	speechSprite = Sprite::create("Materials/BossSpeechBuble-Right.png");
	speechSprite->setContentSize(label->getContentSize() * 2);
	speechSprite->setTag(1);
	speechSprite->setScaleX(0.75);
	speechSprite->setAnchorPoint(Vec2(1.0, 0.0));
	speechSprite->setPosition(Point(1060, 465));
	layer->addChild(speechSprite, 5);

	label->setPosition(Point(speechSprite->getContentSize().width / 2, speechSprite->getContentSize().height / 3 * 2));
	speechSprite->addChild(label, 4);

	auto speechDelayer = DelayTime::create(3);
	auto speechSeq = Sequence::create(speechDelayer,
		CallFunc::create([=]() -> void {

			layer->removeChildByTag(1); }),
		nullptr);
	layer->runAction(speechSeq);
}

















BadgeScene::BadgeScene(cocos2d::Layer* layer)
{
	auto badgeBackground = Sprite::create("Backgrounds/BadgeBackground.png");
	badgeBackground->setTag(1);
	badgeBackground->setAnchorPoint(Vec2(0.0, 0.0));
	badgeBackground->setPosition(Point(0, 0));
	layer->addChild(badgeBackground, 20);
	
	auto badgeBoss = Sprite::create("SpriteSheets/BadgeBoss.png");
	badgeBoss->setTag(2);
	badgeBoss->setAnchorPoint(Vec2(0.0, 0.0));
	badgeBoss->setPosition(Point(2000, 0));
	layer->addChild(badgeBoss, 22);

	auto badgeMasomo = Sprite::create("Materials/BadgeMasomo.png");
	badgeMasomo->setTag(3);
	badgeMasomo->setAnchorPoint(Vec2(0.0, 0.0));
	badgeMasomo->setPosition(Point(1900, 750));
	layer->addChild(badgeMasomo, 21);

	auto smallBadge = Sprite::create("Materials/BadgeMasomo.png");
	smallBadge->setScale(0.15);
	smallBadge->setAnchorPoint(Vec2(0.0, 0.0));
	smallBadge->setPosition(Point(775, 225));
	layer->addChild(smallBadge, 7);

	auto bossMover = MoveTo::create(6, Point(900, 0));
	auto badgeMover = MoveTo::create(6, Point(800, 750));
	auto bossReturner = MoveTo::create(6, Point(2000, 0));
	auto bossSeq = Sequence::create(bossMover, bossReturner, nullptr);
	badgeBoss->runAction(bossSeq);
	badgeMasomo->runAction(badgeMover);

	auto endDelayer = DelayTime::create(13);
	auto endSeq = Sequence::create(endDelayer, CallFunc::create([=]() -> void 
		{
			layer->removeChildByTag(1);
			layer->removeChildByTag(2);
			layer->removeChildByTag(3);

		}), nullptr);

	layer->runAction(endSeq);

}

FirstHailScene::FirstHailScene(cocos2d::Layer* layer)
{
	hailSprite = Sprite::create("Materials/HailFirst.png");
	hailSprite->setTag(1);
	hailSprite->setAnchorPoint(Vec2(0.0, 0.0));
	hailSprite->setPosition(Point(421, 730));
	layer->addChild(hailSprite, 15);

	auto hailDelayer = DelayTime::create(3.5);
	auto hailSeq = Sequence::create(hailDelayer, CallFunc::create([=]() -> void
		{
			layer->removeChildByTag(1);

		}), nullptr);
}

SecondHailScene::SecondHailScene(cocos2d::Layer* layer)
{
	hailSprite = Sprite::create("Materials/HailSecond.png");
	hailSprite->setTag(1);
	hailSprite->setAnchorPoint(Vec2(0.0, 0.0));
	hailSprite->setPosition(Point(421, 730));
	layer->addChild(hailSprite, 15);

	auto hailDelayer = DelayTime::create(3.5);
	auto hailSeq = Sequence::create(hailDelayer, CallFunc::create([=]() -> void
		{
			layer->removeChildByTag(1);

		}), nullptr);
}