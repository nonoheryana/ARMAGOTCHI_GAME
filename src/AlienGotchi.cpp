#include "AlienGotchi.h"
#include "AlienOwnedStates.h"


AlienGotchi::AlienGotchi(int id):BaseGameEntity(id),
                     m_Mood(bored),
                     m_iHungryLevel(0),
					 m_iHappyLevel(Happy_MAX),
					 m_iHealthyLevel(Healthy_MAX/2),
                     m_pCurrentState(Bored::Instance())
                                                                  
{}

//--------------------------- ChangeState -------------------------------------
//-----------------------------------------------------------------------------
void AlienGotchi::ChangeState(State *pNewState)
{
  //make sure both states are both valid before attempting to 
  //call their methods
  assert (m_pCurrentState && pNewState);

  //call the exit method of the existing state
  m_pCurrentState->Exit(this);

  //change state to the new state
  m_pCurrentState = pNewState;

  //call the entry method of the new state
  m_pCurrentState->Enter(this);

  
}

//-----------------------------------------------------------------------------
void AlienGotchi::Update()
{
	//m_iHungryLevel += 1;

	if (m_pCurrentState)
	{
		m_pCurrentState->Execute(this);
	}
}

//-----------------------------------------------------------------------------
bool AlienGotchi::Hungry()const
{
  if (m_iHungryLevel >= Hungry_Thres_Up){return true;}

  return false;
}

bool AlienGotchi::Full()const
{
  if (m_iHungryLevel < Hungry_Thres_Down)
  {
    return true;
  }

  return false;
}

void AlienGotchi::IncreaseAppetite()
{
	m_iHungryLevel += 1;
	if (m_iHungryLevel>Hungry_MAX)
	{
		m_iHungryLevel=Hungry_MAX;
	}
}
void AlienGotchi::DecreaseAppetite()
{
	m_iHungryLevel -= 5;
	if (m_iHungryLevel < 0)
	{
		m_iHungryLevel=0;
	}
}

void AlienGotchi::ResetAppetite()
{
	m_iHungryLevel=0;
}

//-----------------------------------------------------------------------------
bool AlienGotchi::Happy()const
{
	if (m_iHappyLevel >= Happy_Thres_Up){return true;}

	return false;
}

bool AlienGotchi::Sad()const
{
	if (m_iHappyLevel < Happy_Thres_Down)
	{
		return true;
	}

	return false;
}

void AlienGotchi::DecreaseHappiness()
{
	m_iHappyLevel -= 1;
	if (m_iHappyLevel < 0)
	{
		m_iHappyLevel=0;
	}
}

void AlienGotchi::IncreaseHappiness()
{
	m_iHappyLevel += 3;
	if (m_iHappyLevel > Happy_MAX)
	{
		m_iHappyLevel = Happy_MAX;
	}
	
}

void AlienGotchi::ResetHappiness()
{
	m_iHappyLevel=Happy_MAX;
}

//-----------------------------------------------------------------------------
bool AlienGotchi::Healthy()const
{
	if (m_iHealthyLevel >= Health_Thres_Up){return true;}

	return false;
}

bool AlienGotchi::Ill()const
{
	if (m_iHungryLevel > Sick_Thres)
	{
		return true;
	}

	return false;
}

void AlienGotchi::DecreaseFitness(){
	m_iHealthyLevel -= 1;
	if (m_iHealthyLevel < 0)
	{
		m_iHealthyLevel=0;
	}
}

void AlienGotchi::IncreaseFitness(){
	m_iHealthyLevel += 6;
	if (m_iHealthyLevel > Healthy_MAX)
	{
		m_iHealthyLevel= Healthy_MAX;
	}
}

void AlienGotchi::ResetFitness(){
	m_iHealthyLevel= Healthy_MAX/2;
}
//-----------------------------------------------------------------------------
bool AlienGotchi::Death()const
{
	if (m_iHealthyLevel < Death_Thres)
	{
		return true;
	}

	return false;
}


//-----------------------------------------------------------------------------
string AlienGotchi::SetMessage(string val)
{
	return m_message=val;
}
