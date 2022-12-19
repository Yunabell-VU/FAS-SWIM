# FAS-SWIM
## SWIM examplar with extension, this examplar is runned locally not in docker

To run this examplar, 2 library needs to be installed and compiled
- omnetpp-6.0.1 (included)
- queueinglib   (included)

Detailed informaiton about installing and running omnetpp go see:
    ~/FAS-SWIM/FAS-SWIM/omnetpp-6.0.1/doc/InstallGuide.pdf


## Setting the examplar

### Omnetpp must first be compiled
1. Compile Omnetpp 
In the top-level OMNeT++ directory:
>./configure

after configure file complete:
>make

2. Setting Omnetpp environment variable, Apple Silicon need extra " arch -x86_64 /bin/zsh --login"

Apple Silicon:
> cd omnetpp-6.0.1                       
arch -x86_64 /bin/zsh --login

then:
>source setenv

Linux:
>cd omnetpp-6.0.1
source setenv

### Queueinglib must be compiled after Omnetpp 
3. Compile queueinglib
>cd ../queueinglib
make
cd ..

4. Compile FAS-SWIM source code:
>cd swim
make cleanall && make makefiles && make


## Running the simulation
.sh file locates in swim/simulations/swim

> cd simulations/swim;
./run.sh Reactive 1



## Configure the simulation
System configurtions are in swim/simulations/swim/swim.ini




Simulation parameters are in swim/simulations/swim/swim.ned

Adaptation option parameters:
int serverLowerLimit = default(3); 
int serverUpperLimit = default(3); 
double dimmerLowerLimit = default(0.8);
double dimmerUpperLimit = default(1.0);
int serverStep = default(1);
double dimmerStep = default(0.1);

Coefficient parameters:
double responseTimeCoefficient = default(1.0);
double serverCostCoefficient = default(1.0);
double revenueCoefficient = default(1.0);
double normalRevenueCoefficient = default(1.0);
double optRevenueCoefficient = default(1.5);