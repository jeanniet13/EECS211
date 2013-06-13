#include "definitions.h"
#include "devices.h"
#include <iostream>

using namespace std;


int main() {
	
	malfunctionRecord m1, m2;  
	device d1("Turn Signal Lever", 195), d2("Accelerator", 247), *d3;
	int c, m, t;          // Temp variables to hold values retrieved from getRecord.
	char ch;              // Used to hold display until user presses enter.
	
	// malfunctionReport tests.
	cout << "Initially both m1 and m2 should have no malfunctions:\n\n";
	m1.display();
	cout << "\n";
	m2.display();
	cout << "\n";

	// Set a malfunction in m1.
	m1.malfunction(MALFUNCTION_UNDER_RANGE,10);
	cout << "m1 should now have one malfunction with time 10 and under range.\n";
	m1.display();
	// Now add some malfunctions and verify that only the last is kept.
	m1.malfunction(MALFUNCTION_OVER_RANGE,25);
	cout << "\nm1 should now have two malfunctions, the last one with time 25 and over range.\n";
	m1.display();
	m1.malfunction(MALFUNCTION_STOPPED_WORKING,32);
	cout << "\nm1 should now have three malfunctions, the last one with time 32 and stopped working.\n";
	m1.display();

	// Now test the retrieval function.
	c = m1.getRecord(&m, &t);
	cout << "\n\nValues returned from getRecord are " << c << ", " << m << ", and " << t << ".\n";
	cout << "\nEnd of malfunctionReport tests.\n\n\n";

	// Hold display so user has a chance to check results so far.
	cout << "Press ENTR when ready to continue:";
	ch = cin.get();


	
	// device class tests.
	cout << "\n\n\nBeginning tests for device class.\n";
	cout << "Display original d1 and d2:\n\n";
	d1.display();
	cout << "\n";
	d2.display();
	cout << "\n\nTest the amIThisDevice function.  \n";

	if(d1.amIThisDevice("Turn Signal Lever"))  cout << "  First test on d1 passed.\n";
	else                                       cout << "  First test on d1 failed.\n";

	if(d1.amIThisDevice("Accelerator")==0)     cout << "  Second test on d1 passed.\n";
	else                                       cout << "  Second test on d1 failed.\n";
	
	cout << "\n\nNow test record and get malfunction function members.\n";
	d1.recordMalfunction(MALFUNCTION_UNDER_RANGE,25);
	cout << "  Should see count equal 1 and under range malfunction at time 25:\n";
	d1.display();
	d1.recordMalfunction(MALFUNCTION_OVER_RANGE,50);
	cout << "\n  Should see count equal 2 and over range malfunction at time 50:\n";
	d1.display();
	d1.recordMalfunction(MALFUNCTION_STOPPED_WORKING,64);
	cout << "\n  Should see count equal 3 and stopped working malfunction at time 64:\n";
	d1.display();
	cout << "\n\nTry to retrieve malfunction report.  Should see same values as above.\n";
	c = d1.getMalfunctionRecord(&m,&t);
	cout << "Values returned from getRecord are " << c << ", " << m << ", and " << t << ".\n";
	
	// Test destructor.  Create a new device and then delete it.
	cout << "\n\nTesting create and destroy n object.  If you don't see the";
	cout << "\nend of tests message, there is something wrong with your destructor.\n\n";
	d3 = new device("Temporary Device", 100);
	d3->display();
	delete d3;
	
	
	cout << "\n\nEnd of tests for Program 3.\n";

	char rawr;
	cout << "Enter any letter, and then press enter to terminate:";  //prompt user to terminate program
	cin >> rawr;
	return 1;
	
	
	//return 0;
}


