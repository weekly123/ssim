CXXFLAGS =	 -g -Wall -fmessage-length=0

OBJS =		test/utest.o

LIBS =

TARGET =	utest

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
