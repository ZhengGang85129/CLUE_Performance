#ifndef MYANALYZER_BASE_H
#define MYANALYZER_BASE_H
#include "TMath.h"
#include "TFile.h"
#include "TChain.h"
class myAnalyzer_base{
    public:
        myAnalyzer_base(){};
        ~myAnalyzer_base(){};

        virtual void beginJob(char *, char *, char* , char * ) = 0; // set up 
        
        virtual void read(int ev) = 0;//read event
        
        virtual void clean() = 0 ;

        virtual void endJob() = 0; //plot or output something
        
        virtual int nevent() const = 0;
    protected:
        int nev = 0;

};

#endif
