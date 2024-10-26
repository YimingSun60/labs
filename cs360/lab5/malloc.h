#ifndef _MALLOC_H
#define _MALLOC_H

#ifdef _cplusplus
extern "C"{
#endif

void *malloc(unsigned int size);
void *calloc(unsigned int nmemb, unsigned int size);
void *realloc(void *ptr, unsigned int size);
void free(void *ptr);

#ifdef _cpluplus
} /* extern C */
#endif
#endif
