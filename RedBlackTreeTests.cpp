
#include <iostream>
#include <cassert>
#include <random>
#include "RedBlackTree.h"

using namespace std;

void TestSimpleConstructor(){
	cout << "Testing Simple Constructor... " << endl;
	RedBlackTree rbt = RedBlackTree();
	//cout << "empty r-b-tree: " << rbt.ToInfixString() << endl;
	assert(rbt.ToInfixString() == "");
	
	cout << "PASSED!"<< endl << endl;
}


void TestInsertFirstNode(){
	cout << "Testing Insert One Node..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(30);
	cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B30 ");

	cout << "PASSED!" << endl << endl;
}


void TestInsertSecondNode(){
	cout << "Testing Insert Second Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	assert(rbt->ToPrefixString() == " B30  R15 ");
	cout << rbt->ToInfixString() << endl;
	cout << rbt->ToPostfixString() << endl;
	cout << rbt->ToPrefixString() << endl;
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	assert(rbt->ToPrefixString() == " B30  R45 ");	
	delete rbt;

	cout << "PASSED!" << endl << endl;
}


void TestInsertThirdNode(){
	cout << "Testing Insert Third Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	
	
	rbt->Insert(15);
	
	rbt->Insert(10);
	
	assert(rbt->ToPrefixString() == " B15  R10  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree(); 
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(25); // Right Left
	assert(rbt->ToPrefixString() == " B25  R15  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45); // Easy case
	assert(rbt->ToPrefixString() == " B30  R15  R45 ");
	delete rbt;
	
	// more tests go here
	// consider some symmetry!
	
	cout << "TESTS MISSING" << endl << endl;
	cout << "PASSED!" << endl << endl;
}

void TestInsertFourthNode(){
	cout << "Testing Insert Fourth Node..." << endl;

	cout << "TESTS MISSING" << endl << endl;
	
	cout << "PASSED!" << endl << endl;
}

void TestInsertFifthNode(){
	cout << "Testing Insert Fifth Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45);
	rbt->Insert(10);
	rbt->Insert(25);
	//cout << "result: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  B15  R10  R25  B45 ");
	delete rbt;
	
	cout << "TESTS MISSING" << endl << endl;
	
	cout << "PASSED!" << endl << endl;
}


void TestToStrings(){
	cout << "Testing ToString Methods..." << endl;

	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(12);
	rbt.Insert(11);
	

	rbt.Insert(15);
	rbt.Insert(5);
	
	


	rbt.Insert(13);
	cout << "hi" << endl;

	rbt.Insert(7);

	

	assert(rbt.ToPrefixString() == " B12  B7  R5  R11  B15  R13 ");
	assert(rbt.ToInfixString() == " R5  B7  R11  B12  R13  B15 ");
	
	assert(rbt.ToPostfixString() == " R5  R11  B7  R13  B15  B12 ");

	cout << "PASSED!" << endl << endl;
}

void TestInsertRandomTests(){
	cout << "Testing Random Insert Stuff..." << endl;
	cout << "\t This test passes if it doesn't crash and valgrind reports no issues" << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(13);
	rbt->Insert(20);
	rbt->Insert(12);
	cout << endl;
	//cout << "tree: " << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	// probably should have a delete or something here
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(11);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(15);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(5);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(13);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(7);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(10);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(8);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	delete rbt;
	
	cout << "PASSED!" << endl << endl;
}

void TestCopyConstructor(){
	cout << "Testing Copy Constructor..." << endl;

	RedBlackTree rbt1 = RedBlackTree();
	rbt1.Insert(11);
	rbt1.Insert(23);
	rbt1.Insert(9);
	rbt1.Insert(52);
	rbt1.Insert(31);
	rbt1.Insert(4);

	assert(rbt1.ToPrefixString() == " B11  B9  R4  B31  R23  R52 ");

	RedBlackTree rbt2 = RedBlackTree(rbt1);

	assert(rbt1.Size() == rbt2.Size());
	cout <<rbt1.Size() << endl;
	assert(rbt2.ToPrefixString() == rbt1.ToPrefixString());

	rbt1.Insert(200);
	assert(rbt2.ToPrefixString() != rbt1.ToPrefixString());




	RedBlackTree rbt3 = RedBlackTree();
	rbt3.Insert(12);
	rbt3.Insert(10);
	rbt3.Insert(0);
	rbt3.Insert(11);
	rbt3.Insert(3);
	rbt3.Insert(9);
	rbt3.Insert(2);
	rbt3.Insert(7);
	rbt3.Insert(1);
	rbt3.Insert(4);
	rbt3.Insert(6);
	rbt3.Insert(8);
	rbt3.Insert(37);
	rbt3.Insert(5);
	rbt3.Insert(72);
	rbt3.Insert(55);
	rbt3.Insert(90);
	rbt3.Insert(92);
	rbt3.Insert(20);
	rbt3.Insert(13);
	rbt3.Insert(57);
	rbt3.Insert(30);
	rbt3.Insert(64);
	rbt3.Insert(69);
	rbt3.Insert(50);
	rbt3.Insert(67);
	rbt3.Insert(99);
	rbt3.Insert(89);
	rbt3.Insert(33);

	assert(rbt3.ToPrefixString() == " B12  R7  B3  B1  R0  R2  B5  R4  R6  B10  B9  R8  B11  R55  B20  B13  R37  B30  R33  B50  B69  R64  B57  B67  R90  B72  R89  B92  R99 ");

	RedBlackTree rbt4 = RedBlackTree(rbt3);
	

	string s3 = rbt3.ToPrefixString();
	//cout << "s3: " << s3 << endl;
	string s4 = rbt4.ToPrefixString();
	//cout << "s4: " << s4 << endl;
	assert(rbt3.Size() == rbt4.Size());
	assert(s3 == s4);


	// thoroughly test rbt3 and rbt4 by doing inserts
	// that should invoke rotations, this helps ensure that 
	// the trees aren't intertwined with one another
	rbt4.Insert(1000);
	rbt4.Insert(1001);
	rbt4.Insert(1002);
	rbt4.Insert(1003);
	rbt4.Insert(1004);
	
	assert(rbt3.Size() != rbt4.Size());
	s3 = rbt3.ToPrefixString();
	s4 = rbt4.ToPrefixString();
	assert(s3 != s4);
	assert(rbt3.ToPrefixString() == " B12  R7  B3  B1  R0  R2  B5  R4  R6  B10  B9  R8  B11  R55  B20  B13  R37  B30  R33  B50  B69  R64  B57  B67  R90  B72  R89  B92  R99 ");
	//cout << rbt4.ToPrefixString() << endl;
	assert(rbt4.ToPrefixString() == " B12  B7  B3  B1  R0  R2  B5  R4  R6  B10  B9  R8  B11  B55  B20  B13  R37  B30  R33  B50  R69  B64  B57  B67  B99  R90  B72  R89  B92  R1001  B1000  B1003  R1002  R1004 ");
	rbt3.Insert(200);
	assert(rbt3.ToPrefixString() != rbt4.ToPrefixString());



	// copy of empty tree
	RedBlackTree rbt5 = RedBlackTree();
	RedBlackTree rbt6 = RedBlackTree(rbt5);
	assert(rbt5.ToPrefixString() == "");
	assert(rbt6.ToPrefixString() == "");

	rbt5.Insert(65);
	assert(rbt5.ToPrefixString() == " B65 ");

	rbt6.Insert(32);
	assert(rbt6.ToPrefixString() == " B32 ");

	cout << "PASSED!" << endl << endl;
}












void TestContains(){
	cout << "Testing Contains..." << endl;

	RedBlackTree *rbt = new RedBlackTree();
	assert(rbt->Contains(6) == false);
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(22);
	rbt->Insert(15);
	rbt->Insert(31);
	rbt->Insert(55);
	rbt->Insert(12);
	rbt->Insert(17);
	rbt->Insert(29);
	rbt->Insert(34);
	
	assert(rbt->Contains(34));
	delete rbt;

	
	cout << "TESTS MISSING" << endl << endl;
	cout << "PASSED!" << endl << endl;
}




void TestGetMinimumMaximum(){
	cout << "Testing Get Minimum and Get Maximum..." << endl;


	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	assert(rbt->GetMax() == 30);
	assert(rbt->GetMin() == 30);
	rbt->Insert(10);
	rbt->Insert(5);
	rbt->Insert(15);
	assert(rbt->GetMax() == 30);
	assert(rbt->GetMin() == 5);

	delete rbt;
	cout << "PASSED!" << endl << endl;
}
void TestRemoveNodeWithTwoChildren(){
	cout << "Testing Remove Node With Two Children" << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(20);
	rbt->Insert(60);
	rbt->Insert(30);
	rbt->Insert(10);
	rbt->Insert(25);
	rbt->Insert(24);
	rbt->Insert(23);


	//cout << "rbt before: " << rbt->ToPrefixString() << endl;
	cout << "test1" << endl;
	assert(rbt->ToPrefixString() == " B25  R20  B10  B24  R23  R40  B30  B60 ");

	rbt->Remove(20);
	cout << "rbt after remove(20): " << rbt->ToPrefixString() << endl;
	cout <<"test2" << endl;
	assert(rbt->ToPrefixString() == " B25  R23  B10  B24  R40  B30  B60 ");
	delete rbt;


	// IDK what I was thinking!  This test seems unnecessary to me now

	// A test in which the in-order-successor should keep it's
	// color (I think that's always), but in which the node that
	// replaced the ios needs to have a fix-up on it to change it's color
	// to black
	// 
	rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(20);
	rbt->Insert(80);
	rbt->Insert(10);
	rbt->Insert(30);
	rbt->Insert(60);
	rbt->Insert(100);
	rbt->Insert(5);
	rbt->Insert(15);
	rbt->Insert(25);
	rbt->Insert(35);
	rbt->Insert(50);
	rbt->Insert(70);
	rbt->Insert(90);
	rbt->Insert(26);

	//cout << "rbt before: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B40  B20  B10  R5  R15  R30  B25  R26  B35  B80  B60  R50  R70  B100  R90 ");

	rbt->Remove(20);
	//cout << "rbt after remove(20): " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B40  B25  B10  R5  R15  R30  B26  B35  B80  B60  R50  R70  B100  R90 ");
	delete rbt;


	cout << "PASSED!" << endl << endl;
}

void TestRemoveLeaf(){
cout << "Testing Remove Leaf..." << endl;
RedBlackTree rbt = RedBlackTree();
rbt.Insert(40);
// removing root
rbt.Remove(40);
//cout << "rbt: " << rbt.ToPrefixString() << endl;
assert(rbt.ToPrefixString() == "");
//assert(rbt.root == nullptr);
cout <<rbt.Size() << endl;
assert(rbt.Size() == 0);
rbt.Insert(40);
rbt.Insert(23);
rbt.Remove(23);
//cout << "rbt after: " << rbt.ToPrefixString() << endl;
assert(rbt.ToPrefixString() == " B40 ");
rbt.Insert(23);
rbt.Insert(52);
rbt.Remove(52);
cout << "{" << rbt.ToPrefixString() << "}" << endl;
assert(rbt.ToPrefixString() == " B40  R23 ");

rbt.Insert(52);
rbt.Insert(15);
rbt.Remove(15);
//cout << "rbt after: " << rbt.ToPrefixString() << endl;
assert(rbt.ToPrefixString() == " B40  B23  B52 ");
cout << rbt.Size() << endl;
assert(rbt.Size() == 3);
cout << "PASSED!" << endl << endl;
}

void TestRemoveWithDoubleBlack(){
	cout << "Testing Remove (Double Black Condition)" << endl;

	// Right right case
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(20);
	rbt->Insert(60);
	rbt->Insert(70);
	assert(rbt->ToPrefixString() == " B40  B20  B60  R70 ");

	rbt->Remove(20);
	//cout << "rbt after: " << rbt->ToPrefixString() << endl;
	
	assert(rbt->ToPrefixString() == " B60  B40  B70 ");
	delete rbt;


	// Right left case
	rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(20);
	rbt->Insert(60);
	rbt->Insert(50);
	
	assert(rbt->ToPrefixString() == " B40  B20  B60  R50 ");
	

	rbt->Remove(20);
	
	//cout << "rbt after: " << rbt->ToPrefixString() << endl;
	
	assert(rbt->ToPrefixString() == " B50  B40  B60 ");
	delete rbt;



	// Left right case
	rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(20);
	rbt->Insert(60);
	rbt->Insert(30);
	
	assert(rbt->ToPrefixString() == " B40  B20  R30  B60 ");

	rbt->Remove(60);
	//cout << "rbt after: " << rbt->ToPrefixString() << endl;
	
	assert(rbt->ToPrefixString() == " B30  B20  B40 ");
	delete rbt;



	// Left left case
	rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(20);
	rbt->Insert(60);
	rbt->Insert(10);
	
	assert(rbt->ToPrefixString() == " B40  B20  R10  B60 ");

	rbt->Remove(60);
	//cout << "rbt after: " << rbt->ToPrefixString() << endl;
	
	assert(rbt->ToPrefixString() == " B20  B10  B40 ");
	delete rbt;


	// done with red child cases
	// below are two cases in which the sibling is red and has no red children
	// we will delete a black node which will create a double black to remove
	rbt = new RedBlackTree();
	rbt->Insert(50);
	rbt->Insert(30);
	rbt->Insert(70);
	rbt->Insert(60);
	rbt->Insert(80);
	rbt->Insert(55);
	rbt->Remove(55);
	assert(rbt->ToPrefixString() == " B50  B30  R70  B60  B80 ");

	rbt->Remove(30);
	//cout << "rbt after: " << rbt->ToPrefixString() << endl;
	
	assert(rbt->ToPrefixString() == " B70  B50  R60  B80 ");
	delete rbt;




	rbt = new RedBlackTree();
	rbt->Insert(50);
	rbt->Insert(30);
	rbt->Insert(70);
	rbt->Insert(20);
	rbt->Insert(40);
	rbt->Insert(45);
	rbt->Remove(45);
	cout <<"eighth" << endl;
	assert(rbt->ToPrefixString() == " B50  R30  B20  B40  B70 ");

	rbt->Remove(70);
	//cout << "rbt after: " << rbt->ToPrefixString() << endl;
	
	assert(rbt->ToPrefixString() == " B30  B20  B50  R40 ");
	delete rbt;

	cout << "PASSED!" << endl << endl;
}



void randomtest(){
	cout << "Trying random tests" << endl;
	RedBlackTree rbt = RedBlackTree();
	for (int i = 0; i < 200; ++i){
		rbt.Insert(i);
		
	}
	assert(rbt.Size() == 200);
	for (int i = 0; i < 200; ++i){
		
		rbt.Remove(i);
		
	}
	cout << rbt.Size() << endl;
	assert(rbt.Size() == 0);
	cout << "Passed!" << endl;
}

void SpecialTestOne(){
	cout << "Special Test One..." << endl;

	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(160);
	//cout << "rbt.Size(): " << to_string(rbt.Size()) << endl;
	assert(rbt.Size() == 1);
	rbt.Insert(388);
	assert(rbt.Size() == 2);
	rbt.Insert(434);
	assert(rbt.Size() == 3);
	rbt.Insert(88);
	assert(rbt.Size() == 4);
	rbt.Insert(79);
	assert(rbt.Size() == 5);
	assert(rbt.ToPrefixString() == " B388  B88  R79  R160  B434 ");

	//cout << "rbt: " << rbt.ToPrefixString() << endl;
	cout << "Before removing 160 size is " << rbt.Size() << endl;
	rbt.Remove(160);
	cout << "after removing 160 size is " << rbt.Size() << endl;
	//cout << "\n\nrbt: " << rbt.ToPrefixString() << endl;
	cout << "Before removing 388 size is " << rbt.Size() << endl;
	rbt.Remove(388);
	cout << "after removing 388 size is " << rbt.Size() << endl;
	//cout << "\n\nrbt: " << rbt.ToPrefixString() << endl;
	cout << "Before removing 434 size is " << rbt.Size() << endl;
	rbt.Remove(434);
	//cout << "\n\nrbt: " << rbt.ToPrefixString() << endl;
	cout << "after removing 434 size is " << rbt.Size() << endl;
	cout << "Before removing 88 size is " << rbt.Size() << endl;
	rbt.Remove(88);
	cout << "after removing 88 size is " << rbt.Size() << endl;
	//cout << "\n\nrbt: " << rbt.ToPrefixString() << endl;
	cout << "Before removing 79 size is " << rbt.Size() << endl;
	rbt.Remove(79);
	cout << "after removing 79 size is " << rbt.Size() << endl;
	//cout << "\n\nrbt: " << rbt.ToPrefixString() << endl;
	cout <<rbt.Size() << endl;
	assert(rbt.Size() == 0);
	cout << "PASSED!" << endl << endl;
}



int main(){

	
	TestSimpleConstructor();
	
	TestInsertFirstNode();
	TestInsertSecondNode();
	TestInsertThirdNode();
	TestInsertFourthNode();
	TestInsertFifthNode();

	TestToStrings();
	TestInsertRandomTests();

	TestCopyConstructor();

	TestContains();
	TestGetMinimumMaximum();
	TestRemoveNodeWithTwoChildren();
	TestRemoveLeaf();
	TestRemoveWithDoubleBlack();
	randomtest();
	SpecialTestOne();
	
	
	

	
	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
