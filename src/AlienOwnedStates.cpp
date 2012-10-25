#include "AlienOwnedStates.h"
#include "State.h"
#include "AlienGotchi.h"
#include "Moods.h"
#include "EntityNames.h"
#include "misc/ConsoleUtils.h"

#include <iostream>
using std::cout;

//define this to output to a file
#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif



//----------------------------------------methods for Bored

Bored *Bored::Instance()
{
	static Bored instance;

	return &instance;
}

void Bored::Enter(AlienGotchi *pAlien)
{  
	//on entry the miner makes sure he is located at the bank
	if (pAlien->Mood() != bored)
	{
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "...";
		pAlien->SetMessage("...");
		pAlien->ChangeMood(bored);
	}
}

void Bored::Execute(AlienGotchi *pAlien)
{

	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
		<< "That is a very nice day on planet Earth... ";
	pAlien->SetMessage("That is a very nice day on planet Earth...");
	//Fed enough?
	if (pAlien->Hungry())
	{
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
			<< "I am feeling very hungry... :/";
		pAlien->SetMessage("I am feeling very hungry... :/");
		pAlien->ChangeState(Feed::Instance());      
	}
	if (pAlien->Sad()){
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
			<< "I am saaadd, I want to play... :/";
		pAlien->SetMessage("I am saaadd, I want to play... :/");
		pAlien->ChangeState(Play::Instance());
	}
}

void Bored::Exit(AlienGotchi *pAlien)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "..."; 
	pAlien->SetMessage("...");
}

//--------------------------------------methods for Play

Play *Play::Instance()
{
  static Play instance;

  return &instance;
}

void Play::Enter(AlienGotchi *pAlien)
{
  //if the alien is not already at playful mode, it must
  //change change mood
  if (pAlien->Mood() != playful)
  {
      SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
      cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "Need Humans to playyy...";
	  pAlien->SetMessage("Need Humans to playyy...");
      pAlien->ChangeMood(playful);
  }
}

void Play::Execute(AlienGotchi *pAlien)
{  
  //the alien plays with his ray gun. 
  //If he gets hungry during his play, he asks for food.

  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "Hssss I will zap you with my ray gun if we don't playyyy...";
  pAlien->SetMessage("Hssss I will zap you with my ray gun if we don't playyyy...");
  
  //if hungry, ask for food

  if (pAlien->Hungry())
  {
      pAlien->ChangeState(Feed::Instance());
  }
  else if (pAlien->Happy())
  {
	  pAlien->ChangeState(Bored::Instance());
  }
}

void Play::Exit(AlienGotchi *pAlien)
{
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
       << "Enough playing!!!";
  pAlien->SetMessage("Enough playing!!!");
}

//----------------------------------------methods for Feed

Feed *Feed::Instance()
{
  static Feed instance;

  return &instance;
}

void Feed::Enter(AlienGotchi *pAlien)
{  
  //on entry the miner makes sure he is located at the bank
  if (pAlien->Mood() != hungry)
  {
      SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
      cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "Miamyyyy sweet brains!!!";
	  pAlien->SetMessage("Miamyyyy sweet brains!!!");
      pAlien->ChangeMood(hungry);
  }
}

void Feed::Execute(AlienGotchi *pAlien)
{
    

  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
       << "More brains... I am still hungry! ";
  pAlien->SetMessage("More brains... I am still hungry!");
  
 
  if (pAlien->Full() && pAlien->Sad())
  {
	  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	  cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
		  << "Ouffff! I ate enough... Time to play";
	  pAlien->SetMessage("Ouffff! I ate enough... Time to play");
	  pAlien->ChangeState(Play::Instance());

  }
  if (pAlien->Full() && pAlien->Happy())
  {
	  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	  cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
		  << "I am fed up... Let's rest for a while!!;)";
	  pAlien->SetMessage("I am fed up... Let's rest for a while!!;)");
	  pAlien->ChangeState(Bored::Instance());      
  }

  if (pAlien->Ill())
  {
	  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	  cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
		  << "Gloup! I am feeling sick... I might throw up";
	  pAlien->SetMessage("Gloup! I am feeling sick... I might throw up");
	  pAlien->ChangeState(Sick::Instance()); 
  }
  
}

void Feed::Exit(AlienGotchi *pAlien)
{
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "Enough fun for today..."; 
  pAlien->SetMessage("Enough fun for today...");
}

//----------------------------------------methods for Sick

Sick *Sick::Instance()
{
	static Sick instance;

	return &instance;
}

void Sick::Enter(AlienGotchi *pAlien)
{  
	//on entry the alien makes sure he is ill
	if (pAlien->Mood() != ill)
	{
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "Not feeling well... :(((!!!";
		pAlien->SetMessage("Not feeling well... :(((!!!");
		pAlien->ResetAppetite();
		pAlien->ChangeMood(ill);
	}
}

void Sick::Execute(AlienGotchi *pAlien)
{


	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
		<< "I am not feeling good :((... I am going to throw up please help!";
	pAlien->SetMessage("I am not feeling good :((... I am going to throw up please help!");
	//healthy enough to feed again?
	if (pAlien->Death())
	{
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
			<< "Nobody takes care of meeee... snifff!! :((((( ";
		pAlien->SetMessage("Nobody takes care of meeee... snifff!! :((((( ");
		pAlien->ChangeState(Dead::Instance());
	}
	if (pAlien->Healthy())
	{
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
			<< "Ouffff! At last I am feeling better... :))";
		pAlien->SetMessage("Ouffff! At last I am feeling better... :))");
		pAlien->ChangeState(Feed::Instance());      
	}
}

void Sick::Exit(AlienGotchi *pAlien)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "..."; 
	pAlien->SetMessage("...");
	pAlien->ResetFitness();
}

//----------------------------------------methods for Dead

Dead *Dead::Instance()
{
	static Dead instance;

	return &instance;
}


void Dead::Enter(AlienGotchi *pAlien)
{  
	//on entry the alien is dead
	if (pAlien->Mood() != dead)
	{
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "I am dead:(((!!!";
		pAlien->SetMessage("I am dead:(((");
		pAlien->ChangeMood(dead);
	}
}

void Dead::Execute(AlienGotchi *pAlien)
{


	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " 
		<< "Game Over!!!... Next time try to keep me alive :(((! ";
	pAlien->SetMessage("Game Over!!!... Next time try to keep me alive :(((!");
	
}

void Dead::Exit(AlienGotchi *pAlien)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAlien->ID()) << ": " << "..."; 
	pAlien->SetMessage("...");
}