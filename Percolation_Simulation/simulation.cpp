#include "simulation.h"
#include<time.h>
#include<stdlib.h>

Simulation::Simulation()
{

}


// return will determine if we
// run another simulation
// in main loop()
bool Simulation::start_simulation()
{
    // TODO:
    // collect N from user

    // generate random number 
    // to determine size of Grid
    int rand_num;
    // --
    srand(time(NULL));
    rand_num = (rand() % 100) + 1;

    // create rand_num x rand_num 
    // sized (square) grid
    Grid* grid = new Grid(rnd_num);

    // begin choosing random nodes
    // to open 
    // TODO
    // while (!grid->percolates())
    //  grid->open_node(rand() % (rand_num * rand_num) + 1)
    //

}
