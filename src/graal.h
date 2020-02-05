#ifndef GRAAL_LIB_H
#define GRAAL_LIB_H

namespace graal{

const void *min ( const void *, const void *, size_t, bool (*cmp)(const void *, const void *));

bool cmp ( const void * , const void * );

void reverse ( void * first , void * last , size_t size );

void * copy ( const void * first , const  void * last , const void * d_first , size_t size );

void * clone ( const void * first , const void * last , size_t size );

const void * find_if ( const void * first , const void * last , size_t size , bool (*p)(const void *) );

bool p ( const void * );

const void * find ( const void * first , const void * last , size_t size , const void * value , bool (*eq)( const void *, const void * ) );

bool eq ( const void * , const void * );

bool all_of ( const void * first , const void * last , size_t size , bool (*p)(const void *) );
bool any_of ( const void * first , const void * last , size_t size , bool (*p)(const void *) );
bool none_of ( const void * first , const void * last , size_t size , bool (*p)(const void *) );


void * unique ( void * first , void * last , size_t size , bool (*eq)( const void *, const void * )  );


void * partition ( void * first , void * last , size_t size ,  bool (*p)(const void *) );

}
#endif
