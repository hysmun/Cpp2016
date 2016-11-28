#ifndef H_LISTETRIEE
#define H_LISTETRIEE

#include "listeBase.h"

template<class T>
class ListeTriee : public listeBase<T> {
	public:
		T* insere(const T&);
};

#endif /* H_LISTETRIEE */
