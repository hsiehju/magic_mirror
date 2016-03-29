//USEFUL LINK: http://ece320web.groups.et.byu.net/labs/VGATextGeneration/VGA_Terminal.html

#include <stdio.h>
#include <stdlib.h>

#define start_addr 0x10000000
#define num_characters 41
#define char_array_size 128

void initialize_letters(volatile unsigned char* addr);
int starting_idx(char c);

int main(){
	volatile unsigned char* addr = (unsigned char*) start_addr;
	addr = (volatile unsigned char *) malloc(num_characters * 128);
	initialize_letters(addr);
	
	char c = '2';
	
	for (int i = starting_idx(c); i < char_array_size + starting_idx(c); ++i){
		if (i % 8 == 0)
			printf("\n ");
		if (addr[i] == 0)
			printf(" ");
		else
			printf("*");
			
	
	}
	
	printf("Done \n");
	
	free((void*)addr);
	return 0;
}

int starting_idx(char c){
	return ((int)c - 48) * 128;
}

//EQUATION TO PRINT CERTAIN LETTER = ASCII VALUE OF CHARACTER - 48 * 128;
void initialize_letters(volatile unsigned char* addr){
	unsigned char zero[] = {0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,1,1,1,1,1,0,0,
						    1,1,0,0,0,1,1,0,
						    1,1,0,0,0,1,1,0,
						    1,1,0,0,1,1,1,0,
						    1,1,0,1,1,1,1,0,
						    1,1,1,1,0,1,1,0,
						    1,1,1,0,0,1,1,0,
						    1,1,0,0,0,1,1,0,
						    1,1,0,0,0,1,1,0,
						    0,1,1,1,1,1,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0};
						    
	for(size_t i = 0; i < char_array_size; ++i){
		addr[i] = zero[i];
	}
	
	
	unsigned char one[] = {0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,1,1,0,0,0,
						   0,0,1,1,1,0,0,0,
						   0,1,1,1,1,0,0,0,
						   0,0,0,1,1,0,0,0,
						   0,0,0,1,1,0,0,0,
						   0,0,0,1,1,0,0,0,
						   0,0,0,1,1,0,0,0,
						   0,0,0,1,1,0,0,0,
						   0,0,0,1,1,0,0,0,
						   0,1,1,1,1,1,1,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0};
	
	for(size_t i = char_array_size; i < 2*char_array_size; ++i){
		addr[i] = one[i - char_array_size];
	}
	
	
	unsigned char two[] = {0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,1,1,1,1,1,0,0,
						   1,1,0,0,0,1,1,0,
						   0,0,0,0,0,1,1,0,
						   0,0,0,0,1,1,0,0,   
						   0,0,0,1,1,0,0,0,   
						   0,0,1,1,0,0,0,0, 
						   0,1,1,0,0,0,0,0, 
						   1,1,0,0,0,0,0,0,
						   1,1,0,0,0,1,1,0,
						   1,1,1,1,1,1,1,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0};
						   
	for(size_t i = 2*char_array_size; i < 3*char_array_size; ++i){
		addr[i] = two[i - 2*char_array_size];
	}
}

