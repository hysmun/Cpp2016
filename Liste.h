#ifndef H_LISTE
#define H_LISTE

#include "ListeBase.h"

template<class T>
class Liste : public listeBase<T> {
	public:
		T* insere(const T&);
};

#endif /* H_LISTE */
