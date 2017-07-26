// DO NOT MODIFY THIS FILE.

#include <exception>
#include <iostream>
#include "ArrayList.h"
#include "TestCase.h"

using namespace std;
using namespace cs235;

//##############################################################################
//###   Constructor tests
//##############################################################################

/**************************************/
void ConstructorBasic()
{
    TestCase tc("Make a new instance of ArrayList.");

    try
    {
        ArrayList<int> list;
        tc.LogResult(RESULT_PASSED, "Make an instance of an ArrayList");
    }
    catch (exception ex)
    {
        tc.LogException(ex);
    }
}


/**************************************/
void ConstructorCheckCount()
{
	TestCase tc("After creating a new ArrayList, GetCount() returns 0.");

	try
	{
		ArrayList<int> list;
		tc.LogResult(RESULT_PASSED, "Make an instance of an ArrayList.");

		tc.AssertEquals(0, list.GetCount(), "Make sure GetCount() returns a 0 for a new ArrayList.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


/**************************************/
void ConstructorCheckCapacity()
{
	TestCase tc("After creating a new ArrayList, GetCapacity() returns 10.");

	try
	{
		ArrayList<int> list;
		tc.LogResult(RESULT_PASSED, "Make an instance of an ArrayList.");

		tc.AssertEquals(10, list.GetCapacity(), "Make sure GetCapacity() returns 10.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   Append 
//##############################################################################

/**************************************/
void AppendItemsAndCheckCount()
{
	TestCase tc("Append items to the list and check the count.");

	try
	{
		ArrayList<int> list;
		tc.AssertEquals(0, list.GetCount(), "GetCount returns 0 on empty list.");
		list.Append(5);
		tc.AssertEquals(1, list.GetCount(), "Append, then make sure GetCount returns 1.");
		list.Append(3);
		tc.AssertEquals(2, list.GetCount(), "Append, then make sure GetCount returns 2.");
		list.Append(7);
		tc.AssertEquals(3, list.GetCount(), "Append, then make sure GetCount returns 3.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void AppendBeyondCapacity()
{
	TestCase tc("Append fails properly when ArrayList is full.");

	try
	{
		ArrayList<double> list;
		list.Append(5.0);
		list.Append(3.0);
		list.Append(7.0);
		list.Append(1.0);
		list.Append(4.0);
		list.Append(2.0);
		list.Append(6.0);
		list.Append(9.0);
		list.Append(8.0);
		list.Append(0.0);
		tc.AssertEquals(10, list.GetCount(), "Add 10 items into the list.");

		try
		{
			list.Append(100.0);
			tc.LogResult(RESULT_FAILED, "Inserting an 11th item should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "Inserting an 11th item threw an exception, as expected.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   GetValue
//##############################################################################

/**************************************/
void GetValueAfterAppend()
{
	TestCase tc("Use GetValue to get a value after appending.");

	try
	{
		ArrayList<string> list;
		list.Append("cat");
		tc.AssertEquals("cat", list.GetValue(0), "Add 5, read 5 at position 0.");
		list.Append("dog");
		tc.AssertEquals("dog", list.GetValue(1), "Add 3, read 3 at position 1.");
		list.Append("bird");
		tc.AssertEquals("bird", list.GetValue(2), "Add 7, read 7 at position 2.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void GetValueBeyondCurrentCount()
{
	TestCase tc("Verify that GetValue beyond the current count returns 0.");

	try
	{
		ArrayList<int> list;
		try
		{
			list.GetValue(0);
			tc.LogResult(RESULT_FAILED, "GetValue(0) should throw an exception on an empty list!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "GetValue(0) threw an exception on an empty list, as expected.");
		}
		
		list.Append(5);
		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) after inserting 1 item returns the item.");
		
		list.Append(3);
		list.Append(7);

		tc.AssertEquals(3, list.GetCount(), "Verify GetCount returns 3, after inserting 3 items.");
		tc.AssertEquals(7, list.GetValue(2), "Value at list[2] = 7");

		try
		{
			list.GetValue(3);
			tc.LogResult(RESULT_FAILED, "GetValue(3) should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "GetValue(3) threw an exception, as expected.");
		}

		try
		{
			tc.AssertEquals(0, list.GetValue(1000), "Value at list[1000] = 0");
			tc.LogResult(RESULT_FAILED, "GetValue(1000) should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "GetValue(1000) threw an exception, as expected.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   InsertAt
//##############################################################################

/**************************************/
void InsertAtBeginning()
{
	TestCase tc("Verify that InsertAt to the beginning inserts properly.");

	try
	{
		ArrayList<int> list;
		tc.AssertEquals(0, list.GetCount(), "Starting count is 0.");

		list.InsertAt(0, 5);
		tc.LogResult(RESULT_PASSED, "Inserting 5 at pos 0 returns success.");
		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) returns 5.");
		tc.AssertEquals(1, list.GetCount(), "New count is 1.");

		list.InsertAt(0, 3);
		tc.LogResult(RESULT_PASSED, "Inserting 3 at pos 0 returns success.");
		tc.AssertEquals(3, list.GetValue(0), "GetValue(0) returns 3.");
		tc.AssertEquals(2, list.GetCount(), "New count is 2.");

		list.InsertAt(0, 7);
		tc.LogResult(RESULT_PASSED, "Inserting 7 at pos 0 returns success.");
		tc.AssertEquals(7, list.GetValue(0), "GetValue(0) returns 7.");
		tc.AssertEquals(3, list.GetCount(), "New count is 3.");
		tc.AssertEquals(3, list.GetValue(1), "GetValue(1) returns 3.");
		tc.AssertEquals(5, list.GetValue(2), "GetValue(2) returns 5.");

		try
		{
			list.GetValue(3);
			tc.LogResult(RESULT_FAILED, "GetValue(3) should have thrown an exception!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "GetValue(3) threw an exception, as expected.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtMiddle()
{
	TestCase tc("Verify that InsertAt to the middle inserts properly.");

	try
	{
		ArrayList<int> list;
		list.Append(5);
		list.Append(3);
		list.Append(7);
		tc.AssertEquals(3, list.GetCount(), "Count is 3.");
		list.InsertAt(1, 8);
		tc.LogResult(RESULT_PASSED, "Inserting 8 at pos 2 returns success.");
		tc.AssertEquals(4, list.GetCount(), "New count is 4.");

		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) returns 5.");
		tc.AssertEquals(8, list.GetValue(1), "GetValue(1) returns 8.");
		tc.AssertEquals(3, list.GetValue(2), "GetValue(2) returns 3.");
		tc.AssertEquals(7, list.GetValue(3), "GetValue(3) returns 7.");

		try
		{
			list.GetValue(4);
			tc.LogResult(RESULT_FAILED, "GetValue(4) should have thrown an exception!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "GetValue(4) threw an exception, as expected.");
		}

	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtEnd()
{
	TestCase tc("Verify that InsertAt to the end inserts properly.");

	try
	{
		ArrayList<int> list;
		list.InsertAt(0, 5);
		tc.LogResult(RESULT_PASSED, "Inserting 5 at pos 0 returns success.");
		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) returns 5.");

		list.InsertAt(1, 3);
		tc.LogResult(RESULT_PASSED, "Inserting 3 at pos 1 returns success.");
		tc.AssertEquals(3, list.GetValue(1), "GetValue(1) returns 3.");

		list.InsertAt(2, 7);
		tc.LogResult(RESULT_PASSED, "Inserting 7 at pos 2 returns success.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtEndingHandlesOverflow()
{
	TestCase tc("Verify that InsertAt errors out beyond 10 items (ending).");

	try
	{
		ArrayList<string> list;
		list.Append("apple");
		list.Append("pear");
		list.Append("peach");
		list.Append("banana");
		list.Append("strawberry");
		list.Append("pineapple");
		list.Append("plum");
		list.Append("nectarine");
		list.Append("cherry");
		tc.AssertEquals(9, list.GetCount(), "List starts out with 9 items.");
		list.InsertAt(9, "orange");
		tc.LogResult(RESULT_PASSED, "Inserting a value at position 9 returns success.");

		try
		{
			list.InsertAt(10, "broccoli");
			tc.LogResult(RESULT_FAILED, "InsertAt(10, ...) should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "InsertAt(10, ...) threw an exception, as expected.");
		}

		try
		{
			list.InsertAt(11, "peas");
			tc.LogResult(RESULT_FAILED, "InsertAt(11, ...) should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "InsertAt(11, ...) threw an exception, as expected.");
		}

		tc.AssertEquals(10, list.GetCount(), "List has only 10 items.");
		tc.AssertEquals("cherry", list.GetValue(8), "check value at data[8]");
		tc.AssertEquals("orange", list.GetValue(9), "check value at data[9]");

		try
		{
			tc.AssertEquals("yams", list.GetValue(10), "check value at data[10]");
			tc.LogResult(RESULT_FAILED, "GetValue(10) should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "GetValue(10) threw an exception, as expected.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtBeginningHandlesOverflow()
{
	TestCase tc("Verify that InsertAt errors out beyond 10 items (beginning).");

	try
	{
		ArrayList<int> list;
		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);
		list.Append(80);
		list.Append(90);
		tc.AssertEquals(9, list.GetCount(), "List starts out with 9 items.");
		list.InsertAt(0, 100);
		tc.LogResult(RESULT_PASSED, "Inserting a value at pos 0 returns success.");

		try
		{
			list.InsertAt(0, 101);
			tc.LogResult(RESULT_FAILED, "InsertAt(0, ...) should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "InsertAt(0, ...) threw an exception, as expected.");
		}

		try
		{
			list.InsertAt(0, 101);
			tc.LogResult(RESULT_FAILED, "InsertAt(0, ...) should have failed!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "InsertAt(0, ...) threw an exception, as expected.");
		}

		tc.AssertEquals(10, list.GetCount(), "List has only 10 items.");
		tc.AssertEquals(100, list.GetValue(0), "check value at data[0]");
		tc.AssertEquals(10, list.GetValue(1), "check value at data[1]");
		tc.AssertEquals(90, list.GetValue(9), "check value at data[9]");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtAfterCountFails()
{
	TestCase tc("Verify that InsertAt errors out when inserting past count.");

	try
	{
		ArrayList<int> list;
		list.Append(10);
		list.Append(20);
		list.Append(30);
		tc.LogResult(RESULT_PASSED, "Starting the list with three items.");

		try
		{
			list.InsertAt(4, 100);
			tc.LogResult(RESULT_FAILED, "InsertAt(4) should have thrown an exception!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "InsertAt(4) threw an exception, as expected.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   RemoveAt
//##############################################################################

/**************************************/
void RemoveAtMaxList()
{
	TestCase tc("Verify RemoveAt with a full list.");

	try
	{
		ArrayList<int> list;
		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);
		list.Append(80);
		list.Append(90);
		list.Append(100);
		tc.AssertEquals(10, list.GetCount(), "Start out with a list of 10 elements.");
		list.RemoveAt(9);
		tc.LogResult(RESULT_PASSED, "RemoveAt(9) succeeds.");

		try
		{
			list.RemoveAt(9);
			tc.LogResult(RESULT_FAILED, "RemoveAt(9) should have failed on the second try!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "RemoveAt(9) threw an exception, as expected.");
		}

		tc.AssertEquals(9, list.GetCount(), "The array has 9 elements");
		list.RemoveAt(7), 
		tc.LogResult(RESULT_PASSED, "RemoveAt(7) succeeds once.");
		list.RemoveAt(7);
		tc.LogResult(RESULT_PASSED, "RemoveAt(7) succeeds twice.");

		try
		{
			list.RemoveAt(7);
			tc.LogResult(RESULT_FAILED, "RemoveAt(7) should have failed on the third try!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "RemoveAt(7) threw an exception, as expected.");
		}

		list.RemoveAt(0),
		tc.LogResult(RESULT_PASSED, "RemoveAt(0) succeeds on the first try.");
		list.RemoveAt(0),
		tc.LogResult(RESULT_PASSED, "RemoveAt(0) succeeds on the second try.");
		list.RemoveAt(0),
		tc.LogResult(RESULT_PASSED, "RemoveAt(0) succeeds on the third try.");
		list.RemoveAt(0),
		tc.LogResult(RESULT_PASSED, "RemoveAt(0) succeeds on the fourth try.");
		list.RemoveAt(0), 
		tc.LogResult(RESULT_PASSED, "RemoveAt(0) succeeds on the fifth try.");
		list.RemoveAt(0), 
		tc.LogResult(RESULT_PASSED, "RemoveAt(0) succeeds on the sixth try.");
		list.RemoveAt(0),
		tc.LogResult(RESULT_PASSED, "RemoveAt(0) succeeds on the seventh try.");

		try
		{
			list.RemoveAt(0);
			tc.LogResult(RESULT_FAILED, "RemoveAt(0) should have failed on the eighth try!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "RemoveAt(0) threw an exception, as expected on the eighth try.");
		}

		tc.AssertEquals(0, list.GetCount(), "The array is now empty.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   SetValue
//##############################################################################

/**************************************/
void SetValueOnEmptyList()
{
	TestCase tc("Try calling SetValue on an empty list fails.");

	try
	{
		ArrayList<int> list;
		tc.AssertEquals(0, list.GetCount(), "We're starting with an empty list.");

		try
		{
			list.SetValue(0, 100);
			tc.LogResult(RESULT_FAILED, "SetValue(0, ...) should have thrown an exception!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "SetValue(0, ...) threw an exception, as expected.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void SetValueOnData()
{
	TestCase tc("Try calling SetValue on data in a list.");

	try
	{
		ArrayList<int> list;
		list.Append(5);
		list.Append(3);
		list.Append(7);
		tc.AssertEquals(3, list.GetCount(), "We're starting with three items in the list.");
		list.SetValue(0, 10);
		tc.LogResult(RESULT_PASSED, "SetValue(0, 10) succeeds.");
		list.SetValue(1, 20);
		tc.LogResult(RESULT_PASSED, "SetValue(1, 20) succeeds.");
		list.SetValue(2, 30);
		tc.LogResult(RESULT_PASSED, "SetValue(2, 30) succeeds.");

		try
		{
			list.SetValue(3, 99);
			tc.LogResult(RESULT_FAILED, "SetValue(3, ...) should have thrown an exception!");
		}
		catch (...)
		{
			tc.LogResult(RESULT_PASSED, "SetValue(3, ...) threw an exception, as expected.");
		}

		tc.AssertEquals(10, list.GetValue(0), "GetValue(0) returns 10.");
		tc.AssertEquals(20, list.GetValue(1), "GetValue(1) returns 20.");
		tc.AssertEquals(30, list.GetValue(2), "GetValue(2) returns 30.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}




//##############################################################################
//###   main
//##############################################################################

/**************************************/
int main()
{
	TestCase::PrintBanner("Constructor tests");
	ConstructorBasic();
	ConstructorCheckCount();
	ConstructorCheckCapacity();

	TestCase::PrintBanner("Test Append() method");
	AppendItemsAndCheckCount();
	AppendBeyondCapacity();

	TestCase::PrintBanner("Test GetValue() method");
	GetValueAfterAppend();
	GetValueBeyondCurrentCount();

	TestCase::PrintBanner("Test InsertAt() method");
	InsertAtBeginning();
	InsertAtMiddle();
	InsertAtEnd();
	InsertAtEndingHandlesOverflow();
	InsertAtBeginningHandlesOverflow();
	InsertAtAfterCountFails();

	TestCase::PrintBanner("Test RemoveAt() method");
	RemoveAtMaxList();

	TestCase::PrintBanner("Test SetValue() method");
	SetValueOnEmptyList();
	SetValueOnData();

    TestCase::PrintSummary();
}