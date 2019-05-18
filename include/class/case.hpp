#ifndef __CASE_HPP__
#define __CASE_HPP__

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

#endif //__CASE_HPP__
