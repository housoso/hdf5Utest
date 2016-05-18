/*
 * Thread.h
 *
 *  Created on: May 17, 2016
 *      Author: root
 */

#ifndef THREAD_H_
#define THREAD_H_
#include "hdf.h"
#include <pthread.h>

class Threads
{
public:
	static void* Thread_start(void *ptr);
	static int iInPutsw;
	static string strInputpath;
};

#endif /* THREAD_H_ */
