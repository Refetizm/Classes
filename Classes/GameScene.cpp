#include "GameScene.h"
#include "GameOverScene.h"
#include "SecondCutscene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;


Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
	scene->getPhysicsWorld()->setGravity(Vect(0, 0));
	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
	
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(false);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/GameMusic.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/GameMusic.mp3", true);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/Item.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/Impact.wav");
	
	auto gearItem = MenuItemImage::create("Materials/Gear.png", "Materials/Gear.png", CC_CALLBACK_1(GameScene::GoToPauseMenuScene, this));
	gearItem->setPosition(Point(1800, 960));

	menu = Menu::create(gearItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 150);
	
    /////////////////////////////
    // 2. SCENE SECTION
    //    You can add your scene materials below...
	/////////////////////////////

	/*----------2.1 NON-PHYSICAL SECTION----------*/
	/* You can add non-physical materials to this section(Background, Roads etc.) */
	auto moverSprite = Sprite::create("Materials/Mover.png");
	moverSprite->setAnchorPoint(Vec2(0.0, 0.0));
	moverSprite->setPosition(Point(0, 0));
	this->addChild(moverSprite, 3);
	auto moverAction = RepeatForever::create(MoveBy::create(1, Point(SPRITE_MOVEMENT_SPEED, 0)));
	moverSprite->runAction(moverAction);

	auto backgroundMap = TMXTiledMap::create("Materials/Background.tmx");
	backgroundMap->setAnchorPoint(Vec2(0.0, 0.0));
	backgroundMap->setPosition(Point(0, 0));
	this->addChild(backgroundMap, 1);
	auto backgroundAction = RepeatForever::create(MoveBy::create(1, Point(BACKGROUND_MOVEMENT_SPEED, 0)));
	backgroundMap->runAction(backgroundAction);

	auto roadMap = TMXTiledMap::create("Materials/Road.tmx");
	roadMap->setAnchorPoint(Vec2(0.0, 0.0));
	roadMap->setPosition(Point(0, 0));
	moverSprite->addChild(roadMap, 2);

	auto mountainSprite = Sprite::create("Materials/Mountain.png");
	mountainSprite->setAnchorPoint(Vec2(0.0, 0.0));
	mountainSprite->setPosition(Point(0, 186));
	this->addChild(mountainSprite, 2);

	auto bushMap = TMXTiledMap::create("Materials/Bushes.tmx");
	bushMap->setAnchorPoint(Vec2(0.0, 0.0));
	bushMap->setPosition(Point(0, 186));
	moverSprite->addChild(bushMap, 3);

	auto office1Sprite = Sprite::create("Materials/Office1.png");
	office1Sprite->setAnchorPoint(Vec2(0.0, 0.0));
	office1Sprite->setPosition(Point(0, 186));
	moverSprite->addChild(office1Sprite, 4);

	auto office2Sprite = Sprite::create("Materials/Office2.png");
	office2Sprite->setAnchorPoint(Vec2(0.0, 0.0));
	office2Sprite->setPosition(Point(500, 186));
	moverSprite->addChild(office2Sprite, 4);
	

	

	/*----------2.1 PHYSICAL SECTION----------*/
	/* You can add physical materials to this section(Characters, Pipes etc.) */
	
	
	


	/////////////////////////////
	// 2. CHARACTER SECTION
	//    You can add your character materials below...
	/////////////////////////////

	character = new Character(this);

	roadBlock = new RoadBlock(this);

	teamPipe = new TeamPipe(this);

	cocosPipe = new CocosPipe(this);

	englishPipe = new EnglishPipe(this);

	cleanPipe = new CleanPipe(this);

	unityPipe = new UnityPipe(this);

	csharpPipe = new CsharpPipe(this);

	gamesPipe = new GamesPipe(this);

	cppPipe = new CppPipe(this);
	
	mistral = new Mistral(this);
	



	tshirt = new TShirt(this);
	
	netflix = new Netflix(this);

	iPad = new IPad(this);

	bagPack = new BagPack(this);

	mug = new Mug(this);

	thermos = new Thermos(this);

	itunes = new iTunes(this);

	masomoBox = new MasomoBox(this);

	macbook = new MacBook(this);



	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	auto roadContactListener = EventListenerPhysicsContact::create();
	roadContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onRoadContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(roadContactListener, this);

	auto mistralContactListener = EventListenerPhysicsContact::create();
	mistralContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onMistralContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mistralContactListener, this);

	auto tshirtContactListener = EventListenerPhysicsContact::create();
	tshirtContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onTshirtContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(tshirtContactListener, this);

	auto netflixContactListener = EventListenerPhysicsContact::create();
	netflixContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onNetflixContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(netflixContactListener, this);

	auto ipadContactListener = EventListenerPhysicsContact::create();
	ipadContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onIPadContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(ipadContactListener, this);

	auto bagpackContactListener = EventListenerPhysicsContact::create();
	bagpackContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onBagPackContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(bagpackContactListener, this);

	auto mugContactListener = EventListenerPhysicsContact::create();
	mugContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onMugContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mugContactListener, this);

	auto thermosContactListener = EventListenerPhysicsContact::create();
	thermosContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onThermosContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(thermosContactListener, this);

	auto itunesContactListener = EventListenerPhysicsContact::create();
	itunesContactListener->onContactBegin = CC_CALLBACK_1(GameScene::oniTunesContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(itunesContactListener, this);

	auto masomoBoxContactListener = EventListenerPhysicsContact::create();
	masomoBoxContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onMasomoBoxContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(masomoBoxContactListener, this);

	auto macbookContactListener = EventListenerPhysicsContact::create();
	macbookContactListener->onContactBegin = CC_CALLBACK_1(GameScene::onMacBookContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(macbookContactListener, this);





	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->scheduleUpdate();



    return true;
}


bool GameScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	//Check if the bodies have collided

	if (( CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && PIPE_COLLISION_BITMASK == b->getCollisionBitmask() ) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && PIPE_COLLISION_BITMASK == a->getCollisionBitmask()))
	{
		auto scene = GameOverScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Impact.wav");
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}


	return true;
}

bool GameScene::onRoadContactBegin(cocos2d::PhysicsContact& roadContact)
{
	PhysicsBody* c = roadContact.getShapeA()->getBody();
	PhysicsBody* d = roadContact.getShapeB()->getBody();

	//Check if the bodies have collided

	if ((CHARACTER_COLLISION_BITMASK == c->getCollisionBitmask() && ROAD_COLLISION_BITMASK == d->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == d->getCollisionBitmask() && ROAD_COLLISION_BITMASK == c->getCollisionBitmask()))
	{
		
		character->Walk();
		
	}
	else
	{
		character->StopWalking();
		
	}


	return true;
}

bool GameScene::onMistralContactBegin(cocos2d::PhysicsContact& mistralContact)
{
	PhysicsBody* e = mistralContact.getShapeA()->getBody();
	PhysicsBody* f = mistralContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == e->getCollisionBitmask() && MISTRAL_COLLISION_BITMASK == f->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == f->getCollisionBitmask() && MISTRAL_COLLISION_BITMASK == e->getCollisionBitmask()))
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		auto scene = SecondCutScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		
	}
	return true;
}

bool GameScene::onTshirtContactBegin(cocos2d::PhysicsContact& tshirtContact)
{
	PhysicsBody* a = tshirtContact.getShapeA()->getBody();
	PhysicsBody* b = tshirtContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && TSHIRT_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && TSHIRT_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		tshirt->tShirtOrder();

		auto tshirtLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		tshirtLabel->setColor(Color3B::BLACK);
		tshirtLabel->setString("x1 MASOMO T-SHIRT    ");
		tshirtLabel->setAnchorPoint(Vec2(0.0, 0.0));
		tshirtLabel->setPosition(Point(-50, 1250));
		this->addChild(tshirtLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		tshirtLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::onNetflixContactBegin(cocos2d::PhysicsContact& netflixContact)
{
	PhysicsBody* a = netflixContact.getShapeA()->getBody();
	PhysicsBody* b = netflixContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && NETFLIX_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && NETFLIX_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		netflix->netflixOrder();

		auto netflixLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		netflixLabel->setColor(Color3B::BLACK);
		netflixLabel->setString("x1 NETFLIX GIFT CARD");
		netflixLabel->setAnchorPoint(Vec2(0.0, 0.0));
		netflixLabel->setPosition(Point(-50, 1250));
		this->addChild(netflixLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		netflixLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::onIPadContactBegin(cocos2d::PhysicsContact& ipadContact)
{
	PhysicsBody* a = ipadContact.getShapeA()->getBody();
	PhysicsBody* b = ipadContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && IPAD_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && IPAD_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		iPad->iPadOrder();

		auto ipadLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		ipadLabel->setColor(Color3B::BLACK);
		ipadLabel->setString("x1 APPLE IPAD        ");
		ipadLabel->setAnchorPoint(Vec2(0.0, 0.0));
		ipadLabel->setPosition(Point(-50, 1250));
		this->addChild(ipadLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		ipadLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::onBagPackContactBegin(cocos2d::PhysicsContact& bagpackContact)
{
	PhysicsBody* a = bagpackContact.getShapeA()->getBody();
	PhysicsBody* b = bagpackContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && BAGPACK_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && BAGPACK_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		bagPack->bagPackOrder();

		auto bagPackLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		bagPackLabel->setColor(Color3B::BLACK);
		bagPackLabel->setString("x1 MASOMO BAGPACK    ");
		bagPackLabel->setAnchorPoint(Vec2(0.0, 0.0));
		bagPackLabel->setPosition(Point(-50, 1250));
		this->addChild(bagPackLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		bagPackLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::onMugContactBegin(cocos2d::PhysicsContact& mugContact)
{
	PhysicsBody* a = mugContact.getShapeA()->getBody();
	PhysicsBody* b = mugContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && MUG_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && MUG_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		mug->mugOrder();

		auto mugLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		mugLabel->setColor(Color3B::BLACK);
		mugLabel->setString("x1 MASOMO MUG        ");
		mugLabel->setAnchorPoint(Vec2(0.0, 0.0));
		mugLabel->setPosition(Point(-50, 1250));
		this->addChild(mugLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		mugLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::onThermosContactBegin(cocos2d::PhysicsContact& thermosContact)
{
	PhysicsBody* a = thermosContact.getShapeA()->getBody();
	PhysicsBody* b = thermosContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && THERMOS_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && THERMOS_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		thermos->thermosOrder();

		auto thermosLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		thermosLabel->setColor(Color3B::BLACK);
		thermosLabel->setString("x1 MASOMO THERMOS    ");
		thermosLabel->setAnchorPoint(Vec2(0.0, 0.0));
		thermosLabel->setPosition(Point(-50, 1250));
		this->addChild(thermosLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		thermosLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::oniTunesContactBegin(cocos2d::PhysicsContact& itunesContact)
{
	PhysicsBody* a = itunesContact.getShapeA()->getBody();
	PhysicsBody* b = itunesContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && ITUNES_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && ITUNES_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		itunes->itunesOrder();

		auto itunesLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		itunesLabel->setColor(Color3B::BLACK);
		itunesLabel->setString("x1 ITUNES GIFT CARD");
		itunesLabel->setAnchorPoint(Vec2(0.0, 0.0));
		itunesLabel->setPosition(Point(-50, 1250));
		this->addChild(itunesLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		itunesLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::onMasomoBoxContactBegin(cocos2d::PhysicsContact& masomoBoxContact)
{
	PhysicsBody* a = masomoBoxContact.getShapeA()->getBody();
	PhysicsBody* b = masomoBoxContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && MASOMOBOX_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && MASOMOBOX_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		masomoBox->masomoBoxOrder();

		auto masomoBoxLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		masomoBoxLabel->setColor(Color3B::BLACK);
		masomoBoxLabel->setString("x1 MASOMO MYSTERY BOX");
		masomoBoxLabel->setAnchorPoint(Vec2(0.0, 0.0));
		masomoBoxLabel->setPosition(Point(-50, 1250));
		this->addChild(masomoBoxLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		masomoBoxLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}

bool GameScene::onMacBookContactBegin(cocos2d::PhysicsContact& macbookContact)
{
	PhysicsBody* a = macbookContact.getShapeA()->getBody();
	PhysicsBody* b = macbookContact.getShapeB()->getBody();
	if ((CHARACTER_COLLISION_BITMASK == a->getCollisionBitmask() && MACBOOK_TRIGGER_BITMASK == b->getCollisionBitmask()) || (CHARACTER_COLLISION_BITMASK == b->getCollisionBitmask() && MACBOOK_TRIGGER_BITMASK == a->getCollisionBitmask()))
	{
		macbook->macbookOrder();

		auto macbookLabel = Label::createWithTTF("", "fonts/PressStart2P.ttf", 30.0f, Size(750, 40), cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
		macbookLabel->setColor(Color3B::BLACK);
		macbookLabel->setString("x1 APPLE MACBOOK PRO");
		macbookLabel->setAnchorPoint(Vec2(0.0, 0.0));
		macbookLabel->setPosition(Point(-50, 1250));
		this->addChild(macbookLabel, 5);
		auto labelDelayer = DelayTime::create(3);
		auto firstMove = MoveTo::create(0.25, Point(-50, 1000));
		auto secondMove = MoveTo::create(0.25, Point(-50, 1250));
		auto labelSeq = Sequence::create(firstMove, labelDelayer, secondMove, nullptr);
		macbookLabel->runAction(labelSeq);

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Item.wav");
	}
	return true;
}






bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	character->Fly();
	
	this->scheduleOnce(schedule_selector(GameScene::StopFlying), CHAR_FLY_DURATION);
	
	return true;
}


void GameScene::GoToPauseMenuScene(cocos2d::Ref* psender)
{
	Director::getInstance()->pause();
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

	menu->setLocalZOrder(-5);

	auto transparentBackground = Sprite::create("Backgrounds/MenuTransparentBackground.png");
	transparentBackground->setTag(1);
	transparentBackground->setAnchorPoint(Vec2(0.0, 0.0));
	transparentBackground->setPosition(Point(0, 0));
	this->addChild(transparentBackground, 149);

	auto menuBackground = Sprite::create("Backgrounds/PauseMenuBackground.png");
	menuBackground->setTag(2);
	menuBackground->setPosition(Point(960, 540));
	this->addChild(menuBackground, 150);


	auto resumeItem = MenuItemImage::create("Materials/Resume.png", "Materials/ResumeClicked.png", CC_CALLBACK_1(GameScene::GoToResumeScene, this));
	resumeItem->setPosition(Point(960, 600));

	auto retryItem = MenuItemImage::create("Materials/RetryPause.png", "RetryPauseClicked.png", CC_CALLBACK_1(GameScene::GoToRetryScene, this));
	retryItem->setPosition(Point(960, 550));

	auto mainMenuItem = MenuItemImage::create("Materials/MainMenuPause.png", "MainMenuPauseClicked.png", CC_CALLBACK_1(GameScene::GoToMainMenuScene, this));
	mainMenuItem->setPosition(Point(960, 500));

	auto exitItem = MenuItemImage::create("Materials/ExitPause.png", "Materials/ExitPauseClicked.png", CC_CALLBACK_1(GameScene::GoToExitScene, this));
	exitItem->setPosition(Point(960, 450));

	auto menu = Menu::create(resumeItem, retryItem, mainMenuItem, exitItem, NULL);
	menu->setTag(3);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 151);
}

void GameScene::GoToResumeScene(cocos2d::Ref* psender)
{
	this->removeChildByTag(1);
	this->removeChildByTag(2);
	this->removeChildByTag(3);
	Director::getInstance()->resume();
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	menu->setLocalZOrder(150);
	
}

void GameScene::GoToRetryScene(cocos2d::Ref* psender)
{
	Director::getInstance()->resume();
	auto scene = GameScene::createScene();
	Director::sharedDirector()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	
}

void GameScene::GoToMainMenuScene(cocos2d::Ref* psender)
{
	Director::getInstance()->resume();
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameScene::GoToExitScene(cocos2d::Ref* psender)
{
	Director::getInstance()->end();
}

void GameScene::StopFlying(float dt)
{
	character->StopFlying();
}
void GameScene::update(float dt)
{
	character->Fall();
}
