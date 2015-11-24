/*/////////////////////////////////////////////////////////////////////////////
///@file heist.cpp															///
///@author Jeff Goymerac 153 sec a											///
///@this file is the implimentation of a recursive pathfinding algorithm	///
/// 																		///
/////////////////////////////////////////////////////////////////////////////*/

#include <iomanip>
#include <iostream>

#include <string>


using namespace std;

bool path(string *maze, int x, int y)
{
	if (maze[x][y] == '.')
	{
		return false;
	}
	if (maze[x][y] == '#')
	{
		return false;
	}
	if (maze[x][y] == 'T')
	{
		return false;
	}
	if (maze[x][y] == 'E')
	{
		return true;
	}
	//if (maze[x][y] == 'B')
	//{
	//	//maze[x][y] = 'B';
	//}
	////else
	//{
		maze[x][y] = '.';
//	}
	if (path(maze,x, y - 1) == true)
	{
		return true;
	}
	if (path(maze,x + 1, y) == true)
	{
		return true;
	}
	if (path(maze,x, y + 1) == true)
	{
		return true;
	}
	if (path(maze,x - 1, y) == true)
	{
		return true;
	}
	maze[x][y] = ' ';
	return false;
}

int main()
{
	string* maze;
	int cs, rs;
	int startx =0, starty=0,mapNum =0;

	
	do
	{

		cin >> cs;
		cin >> rs;
		cin.ignore();
		
		if (cs == 0 && rs == 0)
		{
			return 0;
		}
		cout << "Map   : " << mapNum << endl;
		//cin.ignore();
		maze = new string[rs];
		for (int k = 0; k < rs; k++)
		{
			//cin.ignore();
			getline(cin, maze[k]);
			//cout << maze[k] << endl;
			//cin.ignore();
		}
		for (int k = 0; k < cs; k++)
		{
			for (int j = 0; j < rs; j++)
			{
				if (maze[j][k] == 'B')
				{
					startx = j;
					starty = k;
				}
			}
		}

		path(maze,startx, starty);
		
		
		//cout << startx << " " << starty << endl;
		maze[startx][starty] = 'B';
		for (int k = 0; k < rs; k++)
		{
			cout << maze[k] << endl;
		}



		delete[] maze;
		mapNum++;
	} while (rs != 0 && cs != 0)

		;















	return 0;
}




























