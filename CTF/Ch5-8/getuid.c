

int getuid()
{
	return 603375;
}

int main()
{
	return getuid();
}


//BASH

/**
 * INSTRUCTIONS:
 * 1. Save as .C file
 * 
 * BASH:
 * 
 * 2. $ gcc -c -fpic ./getuid.c
 * 3. $ ld -shared getuid.o - getuid.so
 * 4. $ LD_PRELOAD=./getuid.so ./Ch7_13_LdPreloadGetUID
 */
