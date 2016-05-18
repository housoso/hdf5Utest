/*
 * Thread.cc
 *
 *  Created on: May 17, 2016
 *      Author: root
 */
#include "Threads.h"


pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
int Threads::iInPutsw = 0;
string Threads::strInputpath;
void* Threads::Thread_start(void *ptr)
{
	while(1)
	{
		cout<< "Thread_start"<<endl;
		cout<< "Threads::iInPutsw  "<<Threads::iInPutsw<<endl;
		if(0!=Threads::iInPutsw)
		{
			string FILEHDF5("/opt/gc/var/admin/");
			if(Threads::strInputpath.empty())
			{
				continue;
			}
			FILEHDF5 += Threads::strInputpath;
			GETHDFINFO stuGETHDFINFO;
			stuGETHDFINFO.BisHdf5(FILEHDF5);
			stuGETHDFINFO.Disp();
		}
		sleep(1);
	}
}
