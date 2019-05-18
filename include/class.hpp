#ifndef __CLASS_HPP__
#define __CLASS_HPP__

#include <iostream>

class CASE
{
	public:
		CASE();
		~CASE();

	protected:
		bool bomb;
		int nbBombAround;

	private:

};

class MINE : public CASE
{

};

class DRAPEAU : public CASE
{

};

class POINTINTEROGATION : public CASE
{

};

class MINUTEUR
{
	public:
		MINUTEUR();
		~MINUTEUR();
		void beginTimer();
		void getTime();
		void incTime();

	protected:
		int time;

	private:

};

class GRILLE
{
	public:
		GRILLE();
		~GRILLE();

	protected:
		CASE **grid;
		int nbRow;
		int nbColumn;
		int nbBombs;
		int remainBombs;

	private:

};

class BOUTON
{
	public:
		BOUTON();
		~BOUTON();

	protected:
		std::string name;
		int xOrigin;
		int yOrigin;

	private:

};

class ELEMENT_FENETRE
{
	public:
		ELEMENT_FENETRE();
		~ELEMENT_FENETRE();

	protected:
		GRILLE field;
		MINUTEUR timer;
		bool isOver;
		BOUTON *button;

	private:

};

class PARTIE
{
	public:
		PARTIE();
		~PARTIE();
		void begin();

	protected:
		GRILLE field;
		MINUTEUR timer;
		bool isOver;

	private:

};

#endif //__CLASS_HPP__
