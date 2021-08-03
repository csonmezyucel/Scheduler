# Makefile for Scheduler implemented by Cevat Sonmez Yucel
all: AVLTree clean
CXX=clang++ 

OBJECTS = AVLNode.cpp AVLTree.cpp scheduler.cpp

AVLTree: $(OBJECTS)
		$(CXX) $(OBJECTS)

.PHONY: clean
clean:
	-rm -f *.o *~ AVLTree