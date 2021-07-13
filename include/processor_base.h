#ifndef PROCESSOR_BASE_H
#define PROCESSOR_BASE_H
#include "myAnalyzer_base.h"
class processor_base{
    public:
        processor_base(){};
        ~processor_base(){};
        virtual void runAnalyzer(myAnalyzer_base *,char *, char*,char*,char*);
};
#endif

