A* Shortest Path Algorithm
Description

This program demonstrates the A* (A-Star) shortest path finding algorithm using a 10 × 10 grid. The user selects a starting location and a goal location, and the program randomly generates obstacles (approximately 20% of the grid). The A* algorithm then searches for the shortest path while avoiding obstacles.

The program displays:

The initial map with randomly generated obstacles.
The shortest path from the start to the goal (if one exists).
The final map with the discovered path highlighted.

----------------------------------------------------------------------
Compiling the Program
Using GCC
gcc astar.c -o astar
Using Clang
clang astar.c -o astar

----------------------------------------------------------------------
Running the Program
macOS / Linux
./astar
Windows
astar.exe

----------------------------------------------------------------------
User Input

When the program starts, it will ask for four values:

Enter your starting Row:
Enter your starting Colon:
Enter your ending Row:
Enter your ending Colon:

Rows and columns are numbered from 1 to 10.

Example:

Enter your starting Row: 1
Enter your starting Colon: 1
Enter your ending Row: 10
Enter your ending Colon: 10

----------------------------------------------------------------------
Output

The program first prints the randomly generated map.

Symbols used in the map:

Symbol	Meaning
S	Starting position
G	Goal position
#	Obstacle
.	Empty square
Yellow .	Final shortest path

If a path exists, the program will display:

Path Found!

followed by the coordinates of the path and the final map.

If no valid path exists because the obstacles completely block the route, the program will display:

No Path Exists