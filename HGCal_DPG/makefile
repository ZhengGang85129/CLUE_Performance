
## $@: target name $<: First dependence  $^: All  Dependence $*: filename without sub name
ROOTLIBS:= $(shell root-config --libs) -lMinuit -lMLP -lXMLIO -lTMVA -lGenVector
CFLAGS:= $(shell root-config --cflags) -g -O3 -Wall -Wextra -fPIC -DREPLICATION_ENABLED -DJOURNALING_ENABLED -Os 
CC:= g++

plugin:= plugin/performance.cpp
src:=/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/src
include:=/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/include
Interface:=/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/HGCal_DPG/interface
source:=/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/HGCal_DPG/src
objects = main.o cluer.o processor.o cluer.o mycluster.o\
		  myphyobject.o plot_tool.o

all: $(objects)
	$(CC) $(CFLAGS) $^ -I$(include) -I$(Interface) $(ROOTLIBS) -o $@ 

main.o: plugin/performance.cpp $(Interface)/cluer.h $(include)/processor_base.h  
	@echo "Making main ..."
	$(CC) $(CFLAGS) -I$(include) -I$(Interface) $(ROOTLIBS) -c  -o $@ $< 
processor.o: $(src)/processor_base.cpp $(include)/processor_base.h\
		$(include)/myAnalyzer_base.h 
	@echo "Making processor ..."
	$(CC) $(CFLAGS) -I$(include) $(ROOTLIBS) -c $< -o $@  
cluer.o: $(source)/cluer.cpp $(Interface)/cluer.h \
		$(include)/mycluster.h $(include)/myAnalyzer_base.h\
		$(include)/plot_tool.h 
	@echo "Making cluer ..."
	$(CC) $(CFLAGS) -I$(include) -I$(Interface) $(ROOTLIBS) -c $< -o $@
mycluster.o: $(src)/mycluster.cpp $(include)/mycluster.h $(include)/myphyobject.h
	@echo "Making cluster ..."
	$(CC) $(CFLAGS) -I$(include) -I$(Interface) $(ROOTLIBS) -c $< -o $@
myphyobject.o: $(src)/myphyobject.cpp $(include)/myphyobject.h
	@echo "Making myphyobject ..."
	$(CC) $(CFLAGS) -I$(include) -I$(Interface) $(ROOTLIBS) -c $< -o $@
plot_tool.o : $(src)/plot_tool.cpp $(include)/plot_tool.h 
	@echo "Making plot_toll"
	$(CC) $(CFLAGS) -I$(include) -I$(Interface) $(ROOTLIBS) -c $< -o $@

.PHONY:clean
clean:
	@echo "Cleaning ..."
	rm -r *.o
	rm -r all
