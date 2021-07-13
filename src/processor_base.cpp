#include "processor_base.h"
#include <iostream>
void processor_base::runAnalyzer(myAnalyzer_base* player, char * filename,char * filename2, char* filename3 , char *treename){
    int ev = 0 ;
    player->beginJob(filename,filename2,filename3,treename);
    while(ev < player->nevent()){
        player->read(ev);
        ev++;
    }
    player->endJob();
}
