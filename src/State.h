#ifndef STATE_H
#define STATE_H
//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Author: Polychronis Kondaxakis 2012 (p.kondaxakis@ieee.org)
//
//------------------------------------------------------------------------

class AlienGotchi;

class State
{
public:

  virtual ~State(){}

  //this will execute when the state is entered
  virtual void Enter(AlienGotchi *)=0;

  //this is the state's normal update function
  virtual void Execute(AlienGotchi *)=0;

  //this will execute when the state is exited. (My word, isn't
  //life full of surprises... ;o))
  virtual void Exit(AlienGotchi *)=0;

};

#endif