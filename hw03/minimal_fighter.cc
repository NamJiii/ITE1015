#include "minimal_fighter.h"

MinimalFighter::MinimalFighter(){
	mHp = 0;
	mPower = 0;
	mStatus = Invalid;
}

MinimalFighter::MinimalFighter(int _hp, int _power){
	mHp = _hp;
	mPower = _power;
	if(mHp<=0) mStatus = Dead;
	else mStatus = Alive;
}

int MinimalFighter::hp() const{
	return mHp;
}

int MinimalFighter::power() const{
	return mPower;
}

FighterStatus MinimalFighter::status() const{
	return mStatus;
}

void MinimalFighter::setHp(int _hp){
	mHp = _hp;
}

void MinimalFighter::setStatus(FighterStatus status){
	mStatus = status;
}

void MinimalFighter::hit(MinimalFighter *enemy){
	setHp(hp()-enemy->power());
	enemy->setHp(enemy->hp()-power());
	if(hp()<=0) setStatus(Dead);
	if(enemy->hp()<=0) enemy->setStatus(Dead);
}

void MinimalFighter::attack(MinimalFighter*_target){
	_target->setHp(_target->hp()-power());
	if(_target->hp()<=0) _target->setStatus(Dead);
}

void MinimalFighter::fight(MinimalFighter*_enemy){
	while(hp()>0 && _enemy->hp()>0){
		setHp(hp()-_enemy->power());
		_enemy->setHp(_enemy->hp()-power());
	}
	if(hp()<=0) setStatus(Dead);
	if(_enemy->hp()<=0) _enemy->setStatus(Dead);
}
