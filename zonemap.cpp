
/* STD namespace headers start --------------*/
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <functional>
#include <future>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <string>
#include <set>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>
/* STD namespace headers end --------------*/

#include "Vector.h"
#include "vari.h"

#ifndef ZONE_MAP_H
#define ZONE_MAP_H 1


class ZoneMap{
	public:
		/* Constructor */
		ZoneMap(int xsize, int ysize, int src[][])
		{
		
			self.max_x = xsize; // COLS
			self.max_y = ysize; // ROW

			for (int y = 0; y < xsize; y++)
			{
				Vector<Vari> tmpv:
				
				for (int x = 0; x < xsize; x++)
				{
					unsigned int z = scr[x][y];
					Vari v = Vari(z,z,z,z,z);
					tmpv.push_back(v);
				}
			}

		}

		

	private:
		int max_x;
		int max_y;
		vector<vector<Vari>> map;
		
	
};



#endif /* VARI_H */

