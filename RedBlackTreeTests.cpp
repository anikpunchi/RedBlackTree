
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
	cout << "doing first test" << endl;
	assert(rbt1.ToPrefixString() == " B11  B9  R4  B31  R23  R52 ");

	RedBlackTree rbt2 = RedBlackTree(rbt1);
	cout << "doing second test" << endl;
	assert(rbt1.Size() == rbt2.Size());
	cout << "doing third test" << endl;
	assert(rbt2.ToPrefixString() == rbt1.ToPrefixString());

	rbt1.Insert(200);
	cout << "doing fouth test" << endl;
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
	cout << "doing fifth test" << endl;

	assert(rbt3.ToPrefixString() == " B12  R7  B3  B1  R0  R2  B5  R4  R6  B10  B9  R8  B11  R55  B20  B13  R37  B30  R33  B50  B69  R64  B57  B67  R90  B72  R89  B92  R99 ");

	RedBlackTree rbt4 = RedBlackTree(rbt3);

	string s3 = rbt3.ToPrefixString();
	//cout << "s3: " << s3 << endl;
	string s4 = rbt4.ToPrefixString();
	//cout << "s4: " << s4 << endl;
	cout << "doing sixth test" << endl;
	assert(rbt3.Size() == rbt4.Size());
	cout << "doing seventh test" << endl;
	assert(s3 == s4);


	rbt3.Insert(200);
	cout << "doing eighth test" << endl;
	assert(rbt3.ToPrefixString() != rbt4.ToPrefixString());


	// copy of empty tree
	RedBlackTree rbt5 = RedBlackTree();
	RedBlackTree rbt6 = RedBlackTree(rbt5);
	cout << "doing ninth test" << endl;
	assert(rbt5.ToPrefixString() == "");
	cout << "doing tenth test" << endl;
    assert(rbt6.ToPrefixString() == "");
	cout << rbt6.ToPrefixString() << endl;

	rbt5.Insert(65);
	cout << "doing eleventh test" << endl;
	cout << rbt5.ToPrefixString() << endl;

	rbt6.Insert(32);
	cout << "doing twelveth test" << endl;
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


	cout << "PASSED!" << endl << endl;
}

void TestGetSibling() {
    cout << "Testing GetSibling..." << endl;

    RedBlackTree rbt;

    // Insert nodes into the tree
    rbt.Insert(10);
    rbt.Insert(5);
    rbt.Insert(15);
    rbt.Insert(3);
    rbt.Insert(7);
    rbt.Insert(12);
    rbt.Insert(20);

    // Test case 1: Sibling of node 5 should be 15
	
    RBTNode* node5 = rbt.root->left; // Node with key 5
    RBTNode* sibling = rbt.GetSibling(node5);
	
    assert(sibling->key == 15);
	
    // Test case 2: Sibling of node 15 should be 5
    RBTNode* node15 = rbt.root->right; // Node with key 15
    sibling = rbt.GetSibling(node15);
    assert(sibling->key == 5);
	

    // Test case 3: Sibling of node 3 should be 7
    RBTNode* node3 = node5->left; // Node with key 3
    sibling = rbt.GetSibling(node3);
    assert(sibling->key == 7);
	
    // Test case 4: Sibling of node 7 should be 3
    RBTNode* node7 = node5->right; // Node with key 7
    sibling = rbt.GetSibling(node7);
    assert(sibling->key == 3);
	
    // Test case 5: Sibling of root should be nullptr
    sibling = rbt.GetSibling(rbt.root);
    assert(sibling == nullptr);
	

    cout << "PASSED!" << endl << endl;
}

void TestRemoveRoot() {
    cout << "Testing Remove Root..." << endl;

    RedBlackTree rbt;
    rbt.Insert(30);
    rbt.Insert(20);
    rbt.Insert(40);
    assert(rbt.ToPrefixString() == " B30  R20  R40 ");

    // Remove the root node (30)
    rbt.Remove(30);
    cout << "Tree after removing root: " << rbt.ToPrefixString() << endl;
    assert(rbt.ToPrefixString() == " B40  R20 ");  // 20 becomes the new root

    cout << "PASSED!" << endl << endl;
}


int main(){

	TestRemoveRoot();
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
	TestGetSibling();

	
	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
