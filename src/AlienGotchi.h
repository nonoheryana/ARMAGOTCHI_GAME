#ifndef ALIENGOTCHI_H
#define ALIENGOTCHI_H

#define Healthy_MAX 50
#define Happy_MAX 50
#define Hungry_MAX 50

//the higher the value the more hungry the pet is
#define Hungry_Thres_Up        35

//the lower the value the less hungry the pet is
#define Hungry_Thres_Down      15

//the higher the value the more happy the pet is
#define Happy_Thres_Up	       40

//the lower the value the less happy the pet is
#define Happy_Thres_Down	   20

//the higher the value the more healthy the pet is
#define Health_Thres_Up		   45

//the lower the value the less healthy the pet is (== Sick_Thres)
#define Health_Thres_Down	   15

//above that threshold the pet is sick
#define Sick_Thres			   45

//below that threshold the pet is dead
#define Death_Thres			   0
//------------------------------------------------------------------------
//
//  Name:   AlienGotchi.h
//
//  Desc:   A class defining an alien armagotchi.
//
//  Author: Polychronis Kondaxakis 2012 (p.kondaxakis@ieee.org)
//
//------------------------------------------------------------------------
#include <string>
using std::string;
#include <cassert>

#include "BaseGameEntity.h"
#include "Moods.h"


class State;


class AlienGotchi : public BaseGameEntity
{
private:

  State					*m_pCurrentState;
  
  mood_type				m_Mood;

  //how hungry your creature is
  int                   m_iHungryLevel;
  //how happy your creature is
  int					m_iHappyLevel;
  //how healthy your creature is
  int					m_iHealthyLevel;

  //action messaging
  string				m_message;

public:

  AlienGotchi(int id);

  //this must be implemented
  void Update();
  //this method changes the current state to the new state. It first
  //calls the Exit() method of the current state, then assigns the
  //new state to m_pCurrentState and finally calls the Entry()
  //method of the new state.
  void ChangeState(State *new_state);

  
  string		Message(){return m_message;}
  string		SetMessage(string val);

  mood_type		Mood()const{return m_Mood;}
  void          ChangeMood(const mood_type moo){m_Mood=moo;}

  bool          Hungry()const; 
  void          DecreaseAppetite();
  void          IncreaseAppetite();
  bool			Full()const;
  int			HungryLevel(){return m_iHungryLevel;}
  void			ResetAppetite();

  bool			Happy()const;
  void			DecreaseHappiness();
  void			IncreaseHappiness();
  bool			Sad()const;
  int			HappyLevel(){return m_iHappyLevel;}
  void			ResetHappiness();

  bool			Healthy()const;
  void			DecreaseFitness();
  void			IncreaseFitness();
  bool			Ill()const;
  int			HealthyLevel(){return m_iHealthyLevel;}
  void			ResetFitness();

  bool			Death()const;
  

};




#endif
