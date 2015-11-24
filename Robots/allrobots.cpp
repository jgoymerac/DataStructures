//////////////////////////////////////////////////////////////////////////////
///@file allrobots.cpp													   ///
///@author Jeff Goymerac 153 sec a										   ///
///@this file is the implimentation of analysis of the robot census data   /// 			
//////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>
#include "robot.h"
#include "robot.hpp"
#include <string>
using namespace std;









int main()
{
	int		a = 0,					//Number of Robots 
			type = 0,				//Type of robot
			pS=0,					//powersources for industrial types
			cPu =0,					//CPUs for domestic types
			apps =0,				//Apps for Domestic
			geoCoPro = 0,			//geometric coprocessors for Bender types
			armPlate = 0,			//Armor Plates for Welder types
			leg = 0,				//Number of legs for Legged types
			wheel = 0,				//Number of wheels for Wheeled types
			rocket = 0,				//Rockets for Hover types
			aGe = 0;				//Anti-grav engines for Hover types
	
	float	armDensity = 0;			//Armor Density for Welders;
	
	string	robotName = "";			//Name of Robot
	
	float	avgSpeed = 0, speedTotal=0,			//Average accumulators
			avgStr = 0,	strTotal=0,
			avgTough = 0, toughTotal=0,
			avgInt = 0, intTotal=0;
	
	int		hSpeed = 0,								//high and low place holders
			lSpeed =0,
			hStr = 0,
			lStr = 0,
			hTough = 0,
			lTough = 0,
			hInt = 0,
			lInt = 0;
			


	
	Robot **AR;
	
	cin >> a;
	AR = new Robot*[a];			//Dynamically allocated array of Robot pointers

	for (int k = 0; k < a; k++)
	{
		cin >> type;
		cin >> robotName;
		if (type <2)
		{
			cin >> pS;
			if (type == 0)
			{
				cin >> geoCoPro;
				Bender *Bendy =new Bender(robotName, pS, geoCoPro);
				AR[k] = Bendy;
				
			}
			else
			{
				cin >> armPlate;
				cin >> armDensity;
				Welder *Weldy = new Welder(robotName, pS, armPlate, armDensity);
				AR[k] = Weldy;
				
			}
		}
		else
		{
			cin >> cPu;
			cin >> apps;
			if (type == 2)
			{
				cin >> leg;
				Legged *Leggy = new Legged(robotName, cPu, apps, leg);
				AR[k] = Leggy;
			}
			else if (type == 3)
			{
				cin >> wheel;
				Wheeled *Wheely = new Wheeled(robotName, cPu, apps, wheel);
				AR[k] = Wheely;
			}
			else
			{
				cin >> rocket;
				cin >> aGe;
				Hover *Hovers = new Hover(robotName, cPu, apps, rocket, aGe);
				AR[k] = Hovers;
			}
		
		
		}


	}

	//getting highs and lows
	for (int z = 0; z < a; z++)
	{
		if (AR[z]->speed() > AR[hSpeed]->speed())
		{
			hSpeed = z;
		}

		if (AR[z]->speed() < AR[lSpeed]->speed())
		{
			lSpeed = z;
		}

		if (AR[z]->strength() > AR[hStr]->strength())
		{
			hStr = z;
		}

		if (AR[z]->strength() < AR[lStr]->strength())
		{
			lStr = z;
		}

		if (AR[z]->toughness() > AR[hTough]->toughness())
		{
			hTough = z;
		}

		if (AR[z]->toughness() < AR[lTough]->toughness())
		{
			lTough = z;
		}

		if (AR[z]->intelligence() > AR[hInt]->intelligence())
		{
			hInt = z;
		}

		if (AR[z]->intelligence() < AR[lInt]->intelligence())
		{
			lInt = z;
		}
		speedTotal = speedTotal + AR[z]->speed();			//totals speed of all robots
		strTotal = strTotal + AR[z]->strength();			//totals strength of all robots
		toughTotal = toughTotal + AR[z]->toughness();		//totals toughness of all robots
		intTotal = intTotal + AR[z]->intelligence();		//totals intelligence of all robots
	}
	// average calculations
	avgSpeed = speedTotal / a;
	avgStr = strTotal / a;
	avgTough = toughTotal / a;
	avgInt = intTotal / a;
	
	cout << setprecision(4);
	cout << "[Speed]\n";
	cout << "The average speed is " << avgSpeed << " circus-rings per second. \n";
	cout << "The highest speed value is " << AR[hSpeed]->speed() << " by " << AR[hSpeed]->getName() << ".\n";
	cout << "The lowest speed value is " << AR[lSpeed]->speed() << " by " << AR[lSpeed]->getName() << ".\n\n";

	cout << "[Strength]\n";
	cout << "The average strength is " << avgStr << " dinosaur-power. \n";
	cout << "The highest strength value is " << AR[hStr]->strength() << " by " << AR[hStr]->getName() << ".\n";
	cout << "The lowest strength value is " << AR[lStr]->strength() << " by " << AR[lStr]->getName() << ".\n\n";

	cout << "[Toughness]\n";
	cout << "The average toughness is " << avgTough << " wrecking-balls. \n";
	cout << "The highest toughness value is " << AR[hTough]->toughness() << " by " << AR[hTough]->getName() << ".\n";
	cout << "The lowest toughness value is " << AR[lTough]->toughness() << " by " << AR[lTough]->getName() << ".\n\n";

	cout << "[Intelligence]\n";
	cout << "The average intelligence is " << avgInt << " nano-Turings. \n";
	cout << "The highest intelligence value is " << AR[hInt]->intelligence() << " by " << AR[hInt]->getName() << ".\n";
	cout << "The lowest intelligence value is " << AR[lInt]->intelligence() << " by " << AR[lInt]->getName() << ".\n\n";
	
	
	
	
	for (int z = 0; z < a; z++)
	{
		delete AR[z];
	}
	
	delete[]AR;
	return 0;
}
