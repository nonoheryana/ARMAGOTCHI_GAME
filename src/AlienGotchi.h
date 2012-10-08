#ifndef ALIENGOTCHI_H
#define ALIENGOTCHI_H

#define Healthy_MAX 100
#define Happy_MAX 150
#define Hungry_MAX 200

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

//the higher the value the more hungry the pet is
const int Hungry_Thres_Up       = 15;

//the lower the value the less hungry the pet is
const int Hungry_Thres_Down     = 5;

//the higher the value the more happy the pet is
const int Happy_Thres_Up		= 20;

//the lower the value the less happy the pet is
const int Happy_Thres_Down		= 3;

//the higher the value the more healthy the pet is
const int Health_Thres_Up		= 30;

//the lower the value the less healthy the pet is
const int Health_Thres_Down		= 4;

//above that threshold the pet is sick
const int Sick_Thres			= 20;

//below that threshold the pet is dead
const int Death_Thres			= 0;




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
  void          IncreaseAppetite(){m_iHungryLevel += 1;}
  bool			Full()const;

  bool			Happy()const;
  void			DecreaseHappiness();
  void			IncreaseHappiness(){m_iHappyLevel += 1;}
  bool			Sad()const;

  bool			Healthy()const;
  void			DecreaseFitness();
  void			IncreaseFitness();
  bool			Ill()const;

  bool			Death()const;
  

};




#endif
