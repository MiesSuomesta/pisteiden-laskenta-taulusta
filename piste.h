
#ifndef PISTE_H
#define PISTE_H 1

include "vari.h"

class Piste{
	public:
		/* Constructor */
		Piste(int x, int y, int zone, char r,char g,char b,char a) {
			color		= Vari(r,g,b,a);
			self.x		= x;
			self.y		= y;
			self.zone	= zone;
		}

		// Operaattori []
		double& operator[](int i) { return elem[i]; }

		int size() const { return sz; }

	private:
		Vari color;
		int x;
		int y;
		int zone;
};



#endif /* PISTE_H */

