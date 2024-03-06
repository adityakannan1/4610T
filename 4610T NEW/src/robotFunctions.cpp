#include "vex.h"

int x=0;//largest angle cata can be at(degrees)
int y=0;//smallest angle cata can be at(degrees)
int z=.5;//distance triball is from cata at launch(inches)

void cataSpin(){
    while (true){
        while(!(cataPos.angle()<x&&cataPos.angle()>y)) {
            cata.spin(forward,100,pct);
        }
        cata.setStopping(hold);
        cata.stop();
        if (cataDist.objectDistance(inches)<z){
            cata.spin(forward,100,pct);
        }    
    }   
}

void cataSpin(int amt){
    int triballsFired = 0;
    while (triballsFired<amt){
        while(!(cataPos.angle()<x&&cataPos.angle()>y)) {
            cata.spin(forward,100,pct);
        }
        cata.setStopping(hold);
        cata.stop();
        if (cataDist.objectDistance(inches)<z){
            cata.spin(forward,100,pct);
            waitUntil(cataDist.objectDistance(inches)>z);
            triballsFired++;
        }    
    }
    cata.setStopping(hold);
    cata.stop();
}
