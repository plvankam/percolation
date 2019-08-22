#include <QCoreApplication>
#include <iostream>
#include <string>
#include "grid.h"
#include "node.h"
#include "simulation.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // create instance of a simulation
    Simulation sim = Simulation();
    sim.start_simulation();
    // TODO
    // create threads to run multiple 
    // simulations at the same time 
    // for monte_carlo runs 


    return a.exec();
}

