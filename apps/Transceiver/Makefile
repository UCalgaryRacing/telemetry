SRCS = transceiverComponent/main.cpp \
	   transceiverComponent/encoder.cpp \
	   transceiverComponent/flash.cpp \
	   transceiverComponent/can.cpp \
	   transceiverComponent/reader.cpp \
	   transceiverComponent/server.cpp \
	   transceiverComponent/sender.cpp \
	   transceiverComponent/transceiver.cpp \
	   transceiverComponent/sensor.cpp \
	   transceiverComponent/vfdcp_encoder.cpp

OBJS = $(SRCS:%.cpp=%.o)
NRT  = main

CC		 = gcc
CXX		 = g++
CXXFLAGS = -Wall -O3 -g -std=c++17 -pthread
LDFLAGS	 =
RM		 = rm -f

#------------------------------------------------------------
# do not modify
all: $(NRT) Makefile

$(NRT): $(OBJS)
	echo $@
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

.cpp:.o
	$(CXX) $(CXXFLAGS) -c $<


verify:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(NRT)

clean:
	-@$(RM) $(OBJS) $(NRT)

# files:
#	g++ std=c++17 transceiverComponent/main.cpp transceiverComponent/main.cpp transceiverComponent/encoder.cpp transceiverComponent/flash.cpp transceiverComponent/can.cpp transceiverComponent/reader.cpp transceiverComponent/server.cpp transceiverComponent/sender.cpp -o main

