# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include <time.h>

#define ROWS 10
#define COLS 10

#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

// Each Square on the grid is a Node
typedef struct Node {
    int row;
    int col;

    int g;  // Cost from the start
    int h;  // Estimated cost to goal
    int f;  // g + h

    int obstacle;

    int isPath;
    int visited;
    struct Node *parent;
} Node;

// Initialize every node
Node grid[ROWS][COLS];
Node *openList[ROWS * COLS];
int openCount = 0;

// Setup the grid map
void initializeGrid(){

    for(int i = 0; i < ROWS; i++) {

        for(int j = 0; j < COLS; j++) {

            grid[i][j].row = i;
            grid[i][j].col = j;

            grid[i][j].g = 999999;
            grid[i][j].h = 0;
            grid[i][j].f = 999999;

            grid[i][j].isPath = 0;
            grid[i][j].visited = 0;

            grid[i][j].parent = NULL;

            grid[i][j].obstacle = 0;
        }
    }
}

// Generate random obstacles (around 20% obstacles)
void GenerateRandomObstacles(Node *start, Node *goal) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(rand() % 100 < 20) {
                // Assign an obstacle whenever the value is 1
                grid[i][j].obstacle = 1;
            }else{
                grid[i][j].obstacle = 0;
            }
        }
    }
    // Starting and ending node will always be non-obstacle 
    start->obstacle = 0;
    goal->obstacle = 0;
}

// Manhattan Distance - count for the estimated cost - The H value
int heuristic(Node *current, Node *goal) {
    return abs(current->row - goal->row) + abs(current->col - goal->col);
}

// Print the map
void printGrid(Node *start, Node *goal) {
    for(int i = 0; i < ROWS; i++) {
        printf(MAGENTA "%d" RESET "   ", i);
        for(int j = 0; j < COLS; j++) {
            Node *node = &grid[i][j];
            // special mark on the starting node
            if(node == start) {
                printf(YELLOW "S   " RESET);
            }
            // special mark on the ending node
            else if(node == goal) {
                printf(YELLOW "G   " RESET);
            }else if(node->obstacle) {
                printf("#   ");
            }else{
                if(node->isPath) {
                    printf(YELLOW ".   " RESET);
                }else{
                    printf(".   ");
                }
            }
        }
        printf("\n\n");
    }
}

// Find node with smallest F
Node *getLowestF()
{

    int index = 0;


    for(int i = 1; i < openCount; i++)
    {

        if(openList[i]->f < openList[index]->f)
        {
            index = i;
        }

    }


    Node *best = openList[index];


    // remove from array
    openList[index] = openList[openCount - 1];

    openCount--;


    return best;
}

// Check if node exists in open list
int inOpenList(Node *node)
{

    for(int i = 0; i < openCount; i++)
    {
        if(openList[i] == node)
            return 1;
    }

    return 0;
}

// Reconstruct final path
void printPath(Node *goal)
{

    Node *current = goal;


    while(current != NULL)
    {
        current->isPath = 1;
        printf("(%d,%d) ", 
               current->row,
               current->col);

        
        current = current->parent;
    }

    printf("\n");
}

// A* Algorithm
void AStar(Node *start, Node *goal)
{

    start->g = 0;

    start->h = heuristic(start, goal);

    start->f = start->g + start->h;


    openList[openCount++] = start;



    while(openCount > 0)
    {

        Node *current = getLowestF();

        // Instead of having a closed list array, we mark the node as visited
        current->visited = 1;

        // Goal reached
        if(current == goal)
        {
            printf("\nPath Found!\n");

            printPath(goal);

            return;
        }


        // These represent the coordinate of the 4 neighbors around the current node
        int rowChange[4] = {-1,1,0,0};
        int colChange[4] = {0,0,-1,1};


        // Check neighbors
        for(int i = 0; i < 4; i++)
        {

            int newRow = current->row + rowChange[i];

            int newCol = current->col + colChange[i];


            // Out of boundary, ignore the current node and continue on the next one
            if(newRow < 0 || newRow >= ROWS){
                continue;
            }


            if(newCol < 0 || newCol >= COLS) {
                continue;
            }

            // Obtain the real neighnbor
            Node *neighbor = &grid[newRow][newCol];


            // Ignore walls
            if(neighbor->obstacle) {
                continue;
            }


            int newG = current->g + 1;


            if(newG < neighbor->g)
            {

                neighbor->parent = current;


                neighbor->g = newG;


                neighbor->h = heuristic(neighbor, goal);


                neighbor->f = neighbor->g + neighbor->h;



                if(!inOpenList(neighbor))
                {
                    openList[openCount++] = neighbor;
                }

            }

        }

    }


    printf("No Path Exists\n");

}

int main() {
    srand(time(NULL));
    initializeGrid();
    // GenerateRandomObstacles();

    char s[100];

    while(1) {
        printf("Enter your starting Row: ");
        if (fgets(s, sizeof(s), stdin) == NULL) {
            break; 
        }
        int sRow = atoi(s);
        printf("Enter your starting Colon: ");
        if (fgets(s, sizeof(s), stdin) == NULL) {
            break; 
        }
        int sCol = atoi(s);
        printf("Enter your ending Row: ");
        if (fgets(s, sizeof(s), stdin) == NULL) {
            break; 
        }
        int eRow = atoi(s);
        printf("Enter your ending Colon: ");
        if (fgets(s, sizeof(s), stdin) == NULL) {
            break; 
        }
        int eCol = atoi(s);

        Node *start = &grid[sRow-1][sCol-1];
        Node *goal = &grid[eRow-1][eCol-1];

        GenerateRandomObstacles(start, goal);
    
        printf("Initial Map:\n\n");
    
        printGrid(start, goal);
    
        AStar(start, goal);
    
        printf("\nSearch Result:\n\n");
    
        printGrid(start, goal);
    }

    return 0;
}