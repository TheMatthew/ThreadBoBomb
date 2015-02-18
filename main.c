/*
 *  Something to make many many threads
 *  Copyright (C) 2015  Matthew Khouzam
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <pthread.h>
#include <stdio.h>

#define NUM_THREAD 10000

int fibleft(int i){
	int l;
	long d = 0;
	for( l = 0; l < NUM_THREAD; l++){
		d+= i-l;
	}
}

void *fib(void *ignored){
   fibleft(7);
}

int main(){
	pthread_t threads[NUM_THREAD];
	int i;
	for( i =0; i < NUM_THREAD; i++){
		pthread_create(&threads[i], NULL, fib, (void*) NULL);
		pthread_setname_np(threads[i], "fluffy");
	}
	for( i =0; i < NUM_THREAD; i++){	
		pthread_join(threads[i], NULL);
	}
	return 0;
}

