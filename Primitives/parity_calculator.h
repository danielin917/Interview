#pragma once

unsigned short parity_brute_force(unsigned int x){
	unsigned short parity = 0;
        while(x){
		parity = parity^(x & 1);
		x >>= 1;	
	}
	return parity;
}

unsigned short parity_efficient(unsigned int x){
	unsigned short parity = 0;	
	while(x){
		parity ^= 1;
		unsigned int z = x - 1;
		x = x & z;	
	}
	return parity;
}
