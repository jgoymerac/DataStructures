///////////////////////////////////////////////////////////////////////////////
///@file Robot.hpp															///
///@author Jeff Goymerac 153 sec a											///
///@this file is the implimentation of the different robot classes			/// 			
///////////////////////////////////////////////////////////////////////////////

#ifndef ROBOT_HPP
#define ROBOT_HPP
#include <iomanip>
#include <string>
#include "robot.h"
using namespace std;


class Industrial : public Robot
{
protected:
	int powerSources;

public:
	Industrial(string n, int q) :Robot(n)
	{
		
		powerSources = q;
	};
		
};
class Domestic : public Robot
{
protected:
	int CPUs;
	int Apps;

public:
	Domestic(string n, int c, int a) :Robot(n)
	{

		CPUs = c;
		Apps = a;
	};

};

class Bender : public Industrial
{
protected:
	int coPro;

public:
	Bender(string n, int q,int c) :Industrial(n, q)
	{

		coPro = c;
	};
	
	// Purpose: Returns the speed of a robot.
	// -- PURE VIRTUAL
	float speed() 
	{ 
		float speed = 0;
		speed = (0.3*powerSources) + (0.02* coPro);
		if (speed < 0)
		{
			speed = 0;
		}
		return speed; 
	}

	// Purpose: Returns the strength of a robot.
	// -- PURE VIRTUAL
	float strength()
	{ 
		float strength = 0;
		strength = 0.55*powerSources;
		return strength; 
	}
	
	// Purpose: Returns the toughness of a robot.
	// -- PURE VIRTUAL
	float toughness() 
	{ 
		static const float toughness = 3.1415;
		return toughness; 
	}

	// Purpose: Returns the intelligence of a robot.
	// -- PURE VIRTUAL
	float intelligence() 
	{ 
		float intelligence = 0;
		intelligence = 0.34 + (1.3*coPro);
		return intelligence; 
	}
};

class Welder : public Industrial
{
protected:
	int plates;
	float density;

public:
	Welder(string n, int q, int p, float d) :Industrial(n, q)
	{
		plates = p;
		density = d;
	};

	// Purpose: Returns the speed of a robot.
	// -- PURE VIRTUAL
	float speed()
	{
		float speed = 0;
		speed = (0.1* static_cast<float>(powerSources)) - (0.22* static_cast<float>(plates) * density);
		if (speed < 0)
		{		
			speed = 0;
		}
		
		return speed;
	}

	// Purpose: Returns the strength of a robot.
	// -- PURE VIRTUAL
	float strength()
	{
		float strength = 0;
		strength = 3.15*powerSources;
		return strength;
	}

	// Purpose: Returns the toughness of a robot.
	// -- PURE VIRTUAL
	float toughness()
	{
		float toughness = 0;
		toughness = 5.19 * plates * density;
		return toughness;
	}

	// Purpose: Returns the intelligence of a robot.
	// -- PURE VIRTUAL
	float intelligence()
	{
		static const float intelligence = 0.45;
		return intelligence;
	}
};

class Legged: public Domestic
{
protected:
	int legs;

public:
	Legged(string n, int c, int a, int l) :Domestic(n,c,a)
	{
		legs = l;
	};

	// Purpose: Returns the speed of a robot.
	// -- PURE VIRTUAL
	float speed()
	{
		float speed = 0;
		speed = 7.15-(0.04 *(static_cast<float>(legs)*legs));
		if (speed < 0)
		{
			speed = 0;
		}
		return speed;
	}

	// Purpose: Returns the strength of a robot.
	// -- PURE VIRTUAL
	float strength()
	{
		static const float strength = 0.123;
		return strength;
	}

	// Purpose: Returns the toughness of a robot.
	// -- PURE VIRTUAL
	float toughness()
	{
		float toughness = 0;
		toughness = 1.4 /static_cast<float>(legs);
		return toughness;
	}

	// Purpose: Returns the intelligence of a robot.
	// -- PURE VIRTUAL
	float intelligence()
	{
		float intelligence = 0;
		intelligence = 2.4* (CPUs/static_cast<float>(Apps));
		return intelligence;
	}
};

class Wheeled : public Domestic
{
protected:
	int wheels;

public:
	Wheeled(string n, int c, int a, int w) :Domestic(n, c, a)
	{
		wheels = w;
	};

	// Purpose: Returns the speed of a robot.
	// -- PURE VIRTUAL
	float speed()
	{
		float speed = 0;
		speed = 0.33 *(static_cast<float>(wheels) * wheels);
		if (speed < 0)
		{
			speed = 0;
		}
		return speed;
	}

	// Purpose: Returns the strength of a robot.
	// -- PURE VIRTUAL
	float strength()
	{
		static const float strength = 4.444;
			return strength;
	}

	// Purpose: Returns the toughness of a robot.
	// -- PURE VIRTUAL
	float toughness()
	{
		float toughness = 0;
		toughness = 5.12-(0.7 * wheels);
		return toughness;
	}

	// Purpose: Returns the intelligence of a robot.
	// -- PURE VIRTUAL
	float intelligence()
	{
		float intelligence = 0;
		intelligence = 1.3 * (CPUs / static_cast<float>(Apps));
		return intelligence;
	}
};

class Hover : public Domestic
{
protected:
	int rockets;
	int antigrav;

public:
	Hover(string n, int c, int a, int r, int ag) :Domestic(n, c, a)
	{
		rockets = r;
		antigrav = ag;
	};

	// Purpose: Returns the speed of a robot.
	// -- PURE VIRTUAL
	float speed()
	{
		float speed = 0;
		speed =0.59 * rockets * static_cast<float>(antigrav);
		if (speed < 0)
		{
			speed = 0;
		}
		return speed;
	}

	// Purpose: Returns the strength of a robot.
	// -- PURE VIRTUAL
	float strength()
	{
		float strength = 0;
		strength = 1.12 *(1 / static_cast<float>(antigrav));
		return strength;
	}

	// Purpose: Returns the toughness of a robot.
	// -- PURE VIRTUAL
	float toughness()
	{
		static const float toughness = 0.99;
		return toughness;
	}

	// Purpose: Returns the intelligence of a robot.
	// -- PURE VIRTUAL
	float intelligence()
	{
		float intelligence = 0;
		intelligence = 5.2* (CPUs / static_cast<float>(Apps)) - 0.8*(1 / static_cast<float>(rockets));
		return intelligence;
	}
};


#endif

