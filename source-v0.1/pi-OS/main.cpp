//
// main.c
//
// Pi-OS C++ bare metal environment for Raspberry Pi


#include "../pi-OS/include/circle/kernel.h"
#include "../pi-OS/include/circle/startup.h"

int main (void)
{

	CKernel Kernel;
	if (!Kernel.Initialize ())
	{
		halt ();
		return EXIT_HALT;
	}
	Kernel.write_log("Welcome to ENEE447, Operating System Design Lab");
	Kernel.write_log("This is a test");
	Kernel.write_log("This is a test\n");


	
	TShutdownMode ShutdownMode = ShutdownHalt;

	switch (ShutdownMode)
	{
	case ShutdownReboot:
		reboot ();
		return EXIT_REBOOT;

	case ShutdownHalt:
	default:
		Kernel.write_log("Going to halt");
		halt ();
		Kernel.write_log("Never goes here");
		return EXIT_HALT;
	}



}
