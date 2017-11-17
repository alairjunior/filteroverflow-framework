/***************************************************************************************
*
*  Copyright 2016 Alair Dias Junior
*
*  This file is part of FixedFilterOverflow.
*
*  FixedFilterOverflow is free software: you can redistribute it and/or modify it under the
*  terms of the GNU General Public License as published by the Free Software Foundation,
*  either version 3 of the License, or any later version.
*
*  FilterOverflow is distributed in the hope that it will be useful, but WITHOUT ANY
*  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
*  PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License along with
*  FixedFilterOverflow. If not, see http://www.gnu.org/licenses/.
*
*
***************************************************************************************/

#include "filterChecking.h"
#include "filterEval.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"
#include "time.h"

int main(int argc, char* argv[])
{
	
    
    if (argc > 1) {
        int i = 0;
        long *t = malloc((argc - 1)*sizeof(long));
        for (i = 1; i < argc; ++i) {
            sscanf(argv[i], "%ld", &t[i-1]);
        }
        long ret = filterEval(argc -1, t);
        printf ("The filter evaluation was %ld\n",ret);
        free(t);
        return !ret;
        
    }else{
        srand(time(NULL));
        // initializes the algorithm
        struct timeval tp;
        double sec, usec, start, end;
        // Time stamp before the computations
        gettimeofday( &tp, NULL );
        sec = (double)( tp.tv_sec );
        usec = (double)( tp.tv_usec )/1E6;
        start = sec + usec;

        int ret = filterChecking();

        gettimeofday( &tp, NULL );
        sec = (double) ( tp.tv_sec );
        usec = (double) ( tp.tv_usec )/1E6;
        end = sec + usec;


        if (ret)
        {
            printf("Filter Ok!\nExecution Time: %f seconds\n", end -start);
        }else{
            printf("Filter Overflow!\nExecution Time: %f seconds\n", end -start);
        }

        return !ret;

    }
}
