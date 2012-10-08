#ifndef ALIEN_OWNED_STATES_H
#define ALIEN_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   AlienOwnedStates.h
//
//  Desc:   All the states that can be assigned to the AlienGotchi class
//
//  Author: Polychronis Kondaxakis 2012 (p.kondaxakis@ieee.org)
//
//------------------------------------------------------------------------
#include "State.h"


class AlienGotchi;

//------------------------------------------------------------------------
//
//  The alien will hang around until is hungry or sad. If it becomes hungry hr will change state to Feed. If is unhappy he will change state to 
//  Play. Else he will remain to Bored state. 
//------------------------------------------------------------------------
class Bored : public State
{
private:

	Bored(){}

	//copy ctor and assignment should be private
	Bored(const Bored&);
	Bored& operator=(const Bored&);

public:

	//this is a singleton
	static Bored *Instance();

	virtual void Enter(AlienGotchi *pAlien);

	virtual void Execute(AlienGotchi *pAlien);

	virtual void Exit(AlienGotchi *pAlien);
};

//------------------------------------------------------------------------
//
//  In this state the alien will continuously play with his ray gun. If he gets hungry he'll change state
//  to Feed. If he gets tired he will go to the Bored state.    
//------------------------------------------------------------------------
class Play : public State
{
private:

  Play(){}

  //copy ctor and assignment should be private
  Play(const Play&);
  Play& operator=(const Play&);

public:

  //this is a singleton
  static Play *Instance();
  
  virtual void Enter(AlienGotchi *pAlien);

  virtual void Execute(AlienGotchi *pAlien);

  virtual void Exit(AlienGotchi *pAlien);
};

//------------------------------------------------------------------------
//
//  The alien will start eating brains until you feed it enough. If it becomes full and is unhappy he will change state to 
//  Play. Else he will go to Bored state. If you don't feed it, it will go to state Sick
//------------------------------------------------------------------------
class Feed : public State
{
private:

  Feed(){}

  //copy ctor and assignment should be private
  Feed(const Feed&);
  Feed& operator=(const Feed&);
  
public:

  //this is a singleton
  static Feed *Instance();

  virtual void Enter(AlienGotchi *pAlien);

  virtual void Execute(AlienGotchi *pAlien);

  virtual void Exit(AlienGotchi *pAlien);
};

//------------------------------------------------------------------------
//
//  The alien is ill until you give it the proper medicine. If it becomes healthy again it will change state to Feed.
//------------------------------------------------------------------------
class Sick : public State
{
private:

	Sick(){}

	//copy ctor and assignment should be private
	Sick(const Sick&);
	Sick& operator=(const Sick&);

public:

	//this is a singleton
	static Sick *Instance();

	virtual void Enter(AlienGotchi *pAlien);

	virtual void Execute(AlienGotchi *pAlien);

	virtual void Exit(AlienGotchi *pAlien);
};

//------------------------------------------------------------------------
//
//  If the alien does not receive the proper medicine, it will die.
//------------------------------------------------------------------------
class Dead : public State
{
private:

	Dead(){}

	//copy ctor and assignment should be private
	Dead(const Dead&);
	Dead& operator=(const Dead&);

public:

	//this is a singleton
	static Dead *Instance();

	virtual void Enter(AlienGotchi *pAlien);

	virtual void Execute(AlienGotchi *pAlien);

	virtual void Exit(AlienGotchi *pAlien);
};

#endif