
#ifndef VARI_H
#define VARI_H 1

class Vari{
	public:
		/* Constructor */
		Vari(char r,char g,char b,char a, unsigned int z): elem{new char[r],new char[g], new char[b], new char[a], new char[z]},r{r},g{g},b{b},a{a},z{z} {}

		unsigned int get_rgba_32_bit() {
			// RRGGBBAA
			unsigned int tmp = ( ( (self.r & 0xFF) << (32 - 8 )) |
								 ( (self.g & 0xFF) << (32 - 16)  |
								 ( (self.b & 0xFF) << (32 - 24)  |
								 ( (self.a & 0xFF) << (32 - 32));
			return tmp;
		}

		unsigned int set_zone(int z) 	{ self.z = z; 	}
		unsigned int get_zone() 		{ return self.z;	}

	private:
		int r;
		int g;
		int b;
		int a;
		int z;
		
	
};



#endif /* VARI_H */

