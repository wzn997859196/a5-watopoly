CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = watopoly
OBJECTS = main.o acbuilding.o al.o b1.o b2.o bmh.o building.o c2.o cif.o collectosap.o coopfee.o cph.o dc.o dctimsline.o dwe.o ech.o eit.o esc.o ev1.o ev2.o ev3.o Game.o goosenesting.o gototims.o gym.o hh.o lhi.o mc.o mkv.o ml.o needleshall.o nonproperty.o opt.o pac.o pas.o phys.o player.o property.o rch.o residence.o rev.o slc.o textdisplay.o tuition.o uwp.o v1.o auction.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
