#ifndef __CASE_HPP__
#define __CASE_HPP__

class CASE
{
	public:
		CASE();
		virtual ~CASE();
		bool getBomb();
		int getNbBombAround();
		void placeBomb();
		void incNbBombAround();

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

#endif //__CASE_HPP__
