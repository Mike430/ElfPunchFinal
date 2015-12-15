#include "Elf.h"


Elf* Elf::create()
{
	/*Elf* newElf = new Elf();
	if (newElf->init())
	{
		newElf->autorelease();
		return newElf;
	}
	else
	{
		CC_SAFE_DELETE(newElf);
		return nullptr;
	}*/
	Elf* newElf = new Elf();
	newElf->init();
	//newElf->autorelease();
	return newElf;
}

bool Elf::init()
{
	if (!Node::init())
	{
		return false;
	}

	this->_rootNode = cocos2d::CSLoader::createNode("Elf.csb");
	this->addChild(_rootNode);
	this->_missed = (cocos2d::Sprite*) _rootNode->getChildByName("Missed");
	this->_hit = (cocos2d::Sprite*) _rootNode->getChildByName("PunchedElf");
	this->_common = (cocos2d::Sprite*) _rootNode->getChildByName("RegularElfUntouched");
	this->_rare = (cocos2d::Sprite*) _rootNode->getChildByName("RareElfUntouched");
	
	this->_hit->setVisible(false);
	this->_common->setVisible(false);
	this->_rare->setVisible(false);
	return true;
}

Elf::Elf()
{
}

Elf::~Elf()
{
}

void Elf::Setup(float x, float y, int name)
{
	float posX = this->_rootNode->getPositionX();
	float posY_Up = this->_rootNode->getPositionY() + 20.0f;
	float posY_Down = this->_rootNode->getPositionY();
	this->_startingYPos = this->_rootNode->getPositionY();

	cocos2d::Vec2 up = cocos2d::Vec2(posX, posY_Up);
	cocos2d::Vec2 down = cocos2d::Vec2(posX, posY_Down);

	this->_posUpY = up;
	this->_posDownY = down;
	this->_timeLeft = SetATime();
	this->_name = name;

	this->_isUp = false;
}



void Elf::UpdateElf(Elf* elf, bool state)
{
	elf->_timeLeft -= 1;
	if (elf->_timeLeft <= 0.0f)
	{
		if (elf->_isUp)
			ElfPopDown(elf);
		else
			ElfPopUp(elf);

		//elf->_isUp = !elf->_isUp;//This flips the state but the methods abover were already doing that. woops
		elf->_timeLeft = SetATime();
	}
}

void Elf::ElfPopUp(Elf* elf)
{
	int elfCount = GameManager::GetInstance()->GetNumOfElfs();
	elfCount -= 1;
	GameManager::GetInstance()->SetNumOfElfs(elfCount);

	if (elfCount <= 0)
		GameManager::GetInstance()->SetGameOver(true);
	else
	{
		cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(0.1, elf->_posUpY);
		//_missed->setVisible(false);
		//_common->setVisible(true);
		elf->_rootNode->runAction(moveTo);
		elf->_isUp = true;
	}
}

void Elf::ElfHit(Elf* elf)
{
	GameManager::GetInstance()->AddToScore(10);
	ElfPopDown(elf);
}

void Elf::ElfPopDown(Elf* elf)
{
	cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(0.1, elf->_posDownY);
	elf->_rootNode->runAction(moveTo);
	//_missed->setVisible(true);
	//_common->setVisible(false);
	elf->_isUp = false;
}

int Elf::SetATime()
{
	double time;
	double randElement = rand() % 10 + 5;
	randElement = randElement / 10;
	time = randElement * 5;
	time = time / GameManager::GetInstance()->GetDifficulty();
	time = time * 60;
	int finalTime = (int)time;
	return finalTime;
}