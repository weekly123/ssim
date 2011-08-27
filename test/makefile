CXXFLAGS =	 -g -Wall -fmessage-length=0

INC = -I./include -I/home/wxm/soft/boost_1_47_0  -I./src

OBJS =		src/ssm.o  \
            src/ssm_parser.o 

TEST_OBJS = test/utest.o  \
            test/ssm_parser_utest.o 

LIBS = -lpthread -L./lib -lgtest

TARGET =	utest

$(TARGET):	$(OBJS) $(TEST_OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(TEST_OBJS) $(LIBS)

all:	$(TARGET)

.SUFFIXES : .cpp
.cpp.o : 
	$(CXX)  $(CXXFLAGS) -D_UNITTEST  $(INC)  -c $< -o $*.o 


.PHONY:clean
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET)
