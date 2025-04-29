#pragma once

#include <iostream>

template <typename T>
class arbore {
private:
	class nod {
	public:
		T valoare;
		nod* parinte;
		nod* copil;
		nod* frate;

		nod(const T& val, nod* p = nullptr) : valoare(val), parinte(p), copil(nullptr), frate(nullptr) {}
	};

	nod* radacina;

public:
	arbore();
	~arbore();

	nod* add_node(const T& valoare, nod* parinte);
	nod* get_node(nod* parinte);
	void delete_node(nod* node);
	nod* find(const T& valoare, bool (*comparator)(const T&, const T&));
	nod* insert(const T& valoare, nod* parinte, int i);
	void sort(nod* node, bool (*comparator)(const T&, const T&));
	int count(nod* node);

};


template <typename T>
arbore<T>::arbore() {
	radacina = nullptr;
}

template <typename T>
arbore<T>::~arbore() {
	if (radacina == nullptr) return;
	nod* actual = radacina;
	nod* temp;

	while (actual != nullptr) {
		if (actual->copil != nullptr) {
			temp = actual;
			actual = actual->copil;
			temp->copil = nullptr;
		}
		else {
			temp = actual;
			if (actual->frate != nullptr) actual = actual->frate;
			else actual = actual->parinte;
			delete temp;
		}
	}

	radacina = nullptr;
}

template <typename T>
arbore<T>::nod* arbore<T>::add_node(const T& valoare, nod* parinte) {
	nod* newnod = new nod(valoare, parinte);

	if (parinte == nullptr) {
		if (radacina != nullptr) {
			delete_node(radacina);
		}
		radacine = newnod;
	}

	else {
		if (parinte->copil == nullptr) parinte->copil = newnod;
		else {
			nod* fratele = parinte->frate;
			while (fratele->frate != nullptr) {
				fratele = fratele->frate;
			}
			fratele->frate = newnod;
		}
	}
	return newnod;
}

template <typename T>
arbore<T>::nod* arbore<T>::get_node(nod* parinte) {
	if (parinte == nullptr) return radacina;
	return parinte->copil;
}

template <typename T>
void arbore<T>::delete_node(nod* node) {
    if (node == nullptr) return;

    if (node == radacina) {
        nod* actual = radacina;
        nod* temp;

        while (actual != nullptr) {
            if (actual->copil != nullptr) {
                temp = actual;
                actual = actual->copil;
                temp->copil = nullptr;
            }
            else {
                temp = actual;

                if (actual->frate != nullptr) {
                    actual = actual->frate;
                }
                else {
                    actual = actual->parinte;
                }

                delete temp;
            }
        }

        radacina = nullptr;
        return;
    }

    nod* parinte = node->parinte;
    if (parinte) {
        if (parinte->copil == node) {
            parinte->copil = node->frate;
        }
        else {
            nod* sibling = parinte->copil;
            while (sibling && sibling->frate != node) {
                sibling = sibling->frate;
            }
            if (sibling) {
                sibling->frate = node->frate;
            }
        }
    }

    nod* actual = node;
    nod* temp;

    while (actual != nullptr) {
        if (actual->copil != nullptr) {
            temp = actual;
            actual = actual->copil;
            temp->copil = nullptr;
        }
        else {
            temp = actual;

            if (actual->frate != nullptr) {
                actual = actual->frate;
            }
            else {
                actual = actual->parinte;
                if (actual == parinte) {
                    actual = nullptr;
                }
            }

            delete temp;
        }
    }
}

template <typename T>
arbore<T>::nod* arbore<T>::find(const T& valoare, bool (*comparator)(const T&, const T&)) {
    if (radacina == nullptr) return nullptr;
    nod* actual = radacina;
    while (actual != nullptr) {
        if (comparator(actual->valoare, valoare)) return actual;

        if(actual->copil != nullptr) actual = actual->copil;
        else {
            while (actual != nullptr && actual->frate == nullptr) actual = actual->parinte;
            if (actual != nullptr) actual = actual->frate;
        }
    }

    return nullptr;
}

template <typename T>
arbore<T>::nod* arbore<T>::insert(const T& valoare, nod* parinte, int i) {
    if (parinte == nullptr) return add_node(valoare, nullptr);

    nod* newNode = new nod(valoare, parinte);
    if (i == 0) {
        newNode->frate = parinte->copil;
        parinte->copil = newNode;
    }
    else {
        nod* anterior = parinte->copil;
        int j = 0;

        while (anterior && j < i - 1) {
            anterior = anterior->frate;
            j++;
        }

        if (anterior) {
            newNode->frate = anterior->frate;
            anterior->frate = newNode;
        }
        else return add_node(valoare, parinte);

    }

    return newNode;
}

template <typename T>
void arbore<T>::sort(nod* node, bool (*comparator)(const T&, const T&)) {
    if (node == nullptr) {
        node = radacina;
        if (node == nullptr) return;
    }

    if (node->copil != nullptr) {
        bool ok;
        nod* final = nullptr;

        do {
            ok = false;
            nod* actual = nod->copil;
            nod* anterior = nullptr;

            while (actual->frate != final) {
                nod* urmator = actual->frate;

                bool ok2;
                if (comparator != nullptr) {
                    ok2 = comparator(urmator->valoare, actual->valoare);
                }
                else {
                    ok2 = urmator->valoare < actual->valoare;
                }

                if (ok2) {
                    if (anterior) anterior->frate = urmator;
                    else node->copil = urmator;

                    actual->frate = urmator->frate;
                    urmator->frate = actual;

                    anterior = urmator;
                    ok = true;
                }
                else {
                    anterior = actual;
                    actual = actual->frate;
                }
            }
            final = actual;
        } while (ok);

        nod* child = node->copil;
        while (child) {
            sort(child, comparator);
            child = child->frate;
        }
    }
}

template <typename T>
int arbore<T>::count(nod* node) {
    if (node == nullptr) {
        if (radacina == nullptr) return 0;
        node = radacina;
    }

    int cnt = 0;

    Node* actual = node;
    Node* anterior = nullptr;

    while (actual != nullptr) {
        cnt++;

        if (actual->copil != nullptr) {
            actual = actual->copil;
        }
        else {
            while (actual != nullptr && (actual->frate == nullptr || actual == node)) {
                anterior = actual;
                actual = actual->parinte;

                if (actual == node->parinte) {
                    actual = nullptr;
                    break;
                }
            }

            if (actual != nullptr && actual != node->parinte) {
                actual = actual->frate;
            }
        }
    }

    return cnt;
}
