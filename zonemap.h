
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
		
			self.max_x = xsize; // ROW
			self.max_y = ysize; // COLS

			for (int x = 0; x < self.max_x; x++)
			{
				Vector<Vari> tmpv:
				
				for (int y = 0; y < self.max_y; y++)
				{
					unsigned int z = scr[x][y];
					Vari v = Vari(z,z,z,z,z);
					tmpv.push_back(v);
				}
			}

			self.map.push_back(tmpv);

		}

		int check_vector(Vari& vec[]) 
		{
			unsigned int a = vec[0].get_rgba_32_bit();
			unsigned int b = vec[1].get_rgba_32_bit();
			unsigned int c = vec[2].get_rgba_32_bit();
			
			if (! ((a == b) && (a == c)) )
			{ /* All maches */
				return 0;
			}
		
			return 1;
		}

		int check_half_vector(Vari& vec[]) 
		{
			unsigned int a = vec[0].get_rgba_32_bit();
			unsigned int b = vec[1].get_rgba_32_bit();
			unsigned int c = vec[2].get_rgba_32_bit();
			
			if (a == b)
			{ /* a & b maches */
				return -1;
			} elif (b == c)
			{ /* b & c maches */
				return 1;
			}
		
			return 0;
		}
		
		void direction_of_change(Vari minimap[][])
		{
			
			/* \ ja / */
			Vari& diagA[3] = { minimap[0][0], minimap[1][1], minimap[2][2] };
			Vari& diagB[3] = { minimap[0][2], minimap[1][1], minimap[2][2] };

			/* ------ */
			Vari& horA[3] = { minimap[0][0], minimap[0][1], minimap[0][2] };
			Vari& horB[3] = { minimap[1][0], minimap[1][1], minimap[1][2] };
			Vari& horC[3] = { minimap[2][0], minimap[2][1], minimap[2][2] };

			/* | */
			/* | */
			/* | */
			Vari& verA[3] = { minimap[0][0], minimap[1][0], minimap[2][0] };
			Vari& verB[3] = { minimap[0][1], minimap[1][1], minimap[2][1] };
			Vari& verC[3] = { minimap[0][2], minimap[1][2], minimap[2][2] };

			/* tarkastelua */
			int diagAall = check_vector(diagA);
			int diagBall = check_vector(diagB);

			int horAall = check_vector(horA);
			int horBall = check_vector(horB);
			int horCall = check_vector(horC);

			int verAall = check_vector(verA);
			int verBall = check_vector(verB);
			int verCall = check_vector(verC);

			int diagAhalf = check_half_vector(diagA);
			int diagBhalf = check_half_vector(diagB);

			int horAhalf  = check_half_vector(horA);
			int horBhalf  = check_half_vector(horB);
			int horChalf  = check_half_vector(horC);
			
			int verAhalf  = check_half_vector(verA);
			int verBhalf  = check_half_vector(verB);
			int verChalf  = check_half_vector(verC);


			/*
			 a \ = 7, b / = 9
			                   |		 |
				7 8 9  - 1    79		89
				4 5 6  - 2    45		56
				1 2 3  - 3    12		23
				
			    | | |
				4 5 6
				|  |  |
			y	74 85 96
				
			a	41 52 63
				
			 */
			 
			 int rv = 5;
			 /* täydet viivat */
			 if (diagAall) {
				 rv = 7;
			} elif (diagBall) {
				 rv = 9;
			} elif (horAall) { rv = 1; } elif (horAhalf) { if (horAhalf < 0) { rv = 79; } else { rv = 89; } }
			  elif (horBall) { rv = 2; } elif (horBhalf) { if (horBhalf < 0) { rv = 45; } else { rv = 56; } }
			  elif (horCall) { rv = 3; } elif (horChalf) { if (horChalf < 0) { rv = 12; } else { rv = 23; } }
			  
			  elif (verAall) { rv = 4; } elif (verAhalf) { if (verAhalf < 0) { rv = 74; } else { rv = 41; } }
			  elif (verBall) { rv = 5; } elif (verBhalf) { if (verBhalf < 0) { rv = 85; } else { rv = 52; } }
			  elif (verCall) { rv = 6; } elif (verChalf) { if (verChalf < 0) { rv = 96; } else { rv = 63; } }
			
			cout << "Hahmotettu: " << rv << endl;
			 

		}

		void update_zones_to_map()
		{
			for (int x = 1; x < (self.max_x - 1); x++)
			{
				for (int y = 1; y < (self.max_y - 1); y++)
				{

					Vari center = self.map[x][y];
					
					Vari near[3][3] = { {	self.map[x - 1][y - 1],	self.map[x - 1][y],		self.map[x - 1][y + 1] },
										{	self.map[x + 0][y - 1],	self.map[x + 0][y],		self.map[x + 0][y + 1] },
										{	self.map[x + 1][y - 1],	self.map[x + 1][y],		self.map[x + 1][y + 1] } };

					/*
					 a \ = 7, b / = 9
									   |		 |
						7 8 9  - 1    79		89
						4 5 6  - 2    45		56
						1 2 3  - 3    12		23
						
						| | |
						4 5 6
						|  |  |
					y	74 85 96
						
					a	41 52 63
						
					 */
					
					
					
					
					
					// Center matrix
					
					cout << v.get_zone() << " ";
				}
				cout << endl;
			}
		}

		void zone_dump_map()
		{
			
			for (int x = 0; x < self.max_x; x++)
			{
				for (int y = 0; y < self.max_y; y++)
				{
					Vari v = self.map[x][y];
					cout << v.get_zone() << " ";
				}
				cout << endl;
			}

			
		}

	private:
		int max_x;
		int max_y;
		vector<vector<Vari>> map;


	
};



#endif /* VARI_H */

