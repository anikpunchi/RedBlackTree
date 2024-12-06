all:
	g++ -g -Wall RedBlackTree.cpp RedBlackTreeTestsFirstStep.cpp -o test1
	g++ -g -Wall RedBlackTree.cpp RedBlackTreeTests.cpp -o test2
	g++ -g -Wall RedBlackTree.cpp SpeedTest.cpp -o speed
