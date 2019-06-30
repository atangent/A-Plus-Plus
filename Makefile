OPT = -Wall
OBJS = main.o Student.o Course.o Storage.o Control.o View.o Monitor.o GPAMonitor.o FWMonitor.o

sas:	$(OBJS) StuServer.o
	g++ $(OPT) -o sas $(OBJS) StuServer.o

main.o:	main.cc Control.h
	g++ $(OPT) -c main.cc

Student.o:	Student.cc Student.h Course.h defs.h List.h
	g++ $(OPT) -c Student.cc

Course.o:	Course.cc Course.h
	g++ $(OPT) -c Course.cc

Storage.o:	Storage.cc Storage.h defs.h Student.h
	g++ $(OPT) -c Storage.cc

Control.o:	Control.cc Control.h Storage.h View.h
	g++ $(OPT) -c Control.cc

View.o:	View.cc View.h
	g++ $(OPT) -c View.cc

Monitor.o:	Monitor.cc Monitor.h
	g++ $(OPT) -c Monitor.cc

GPAMonitor.o:	GPAMonitor.cc GPAMonitor.h
	g++ $(OPT) -c GPAMonitor.cc

FWMonitor.o:	FWMonitor.cc FWMonitor.h
	g++ $(OPT) -c FWMonitor.cc

clean:
	rm -f $(OBJS) sas
