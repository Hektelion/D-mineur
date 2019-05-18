#ifndef __MINUTEUR_HPP__
#define __MINUTEUR_HPP__

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

#endif //__MINUTEUR_HPP__
