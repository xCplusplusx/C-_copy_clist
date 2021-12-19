
template<typename t>
class Slist {

private:
	struct Container {
		t data;
		Container* next, * before;
	}* first,* last;

public:

	Slist();
	Slist(const Slist<t>&);
	~Slist();
	t olast();
	bool isEmpty(); //Return a zero one value back if the list is empty
	bool existing(t); //Return one if a element is available
	t posread(int); //Read an object at a position 
	void insertlast(t); //Insert a element at the end
	void insert(t, int); //Insert a element at a position 
	void insert(t elem) { insertlast(elem); };
	void eject(t); //Delete a Element
	
	
};

template<typename t>
Slist<t>::Slist() {

	first = last = nullptr;

}

template<typename t>
Slist<t>::Slist(const Slist& copy) {

	Container dummy;

	Container* Ptr1 = &dummy;
	Container* Ptr2 = copy.first;

	Ptr1->next = new Container;
	Ptr1->next->before = nullptr;
	Ptr1 = Ptr1->next;
	Ptr1->next = nullptr;
	Ptr1->data = Ptr2->data;
	Ptr2 = Ptr2->next;


	while (Ptr2 != nullptr) {
		
		Ptr1->next = new Container;
		Ptr1->next->before = Ptr1;
		Ptr1 = Ptr1->next;
		Ptr1->next = nullptr;
		Ptr1->data = Ptr2->data;
		Ptr2 = Ptr2->next;

	}

	Ptr1->next = nullptr;

	last = Ptr1;
	first = dummy.next;

}

template<typename t>
void Slist<t>::insertlast(t in) {


	if (last == nullptr) {

		Container dummy;
		last = &dummy;

		last->next = new Container;
		last = last->next;
		last->next = nullptr;
		last->data = in;
		first = last;
		last->before = nullptr;
	}
	else {

		last->next = new Container;
		last->next->before = last;
		last = last->next;
		last->next = nullptr;
		last->data = in;
	}
}

template<typename t>
Slist<t>::~Slist() {
	if (last != nullptr) {
		while (last->before != nullptr) {

			Container* pointer_before = last;

			last = last->before;
			last->next = nullptr;


			delete pointer_before;
		}
		delete last;
	}

}

template<typename t>
bool Slist<t>::isEmpty() {

	return (first == nullptr && last == nullptr) ? true : false;

}

template<typename t>
bool Slist<t>::existing(t elem) {

	Container* pointer = first;

	while (pointer != nullptr) {

		if (pointer->data == elem) return 1;
		pointer = pointer->next;

	}

	return 0;

}


template<typename t>
void Slist<t>::eject(t elem){

	Container* pointer = first;

	while (pointer != nullptr) {

		if (pointer->data == elem) {

			if (pointer->before != nullptr && pointer->next != nullptr) {

				pointer->before->next = pointer->next;
				pointer->next->before = pointer->before;
				delete pointer;
				return;

			}
			else if (pointer->next == nullptr && pointer->before == nullptr) {

				first = last = nullptr;
				delete pointer;
				return;

			}
			else if (pointer->before != nullptr && pointer->next == nullptr) {

				pointer->before->next = nullptr;
				last = pointer->before;
				delete pointer;
				return;

			}
			else{

				pointer->next->before = nullptr;
				first = pointer->next;
				delete pointer;
				return;

			}

		}
		pointer = pointer->next;
	}


}

template<typename t>
t Slist<t>::posread(int pos) {

	Container *point = first->next;

	for (int i = 1; i < pos && point != nullptr; i++) {

		point = point->next;

	}
	if (point == nullptr) { std::cerr << "out of line" << std::endl; return false; }
	return point->data;


}

template<typename t>
void Slist<t>::insert(t elem, int pos) {


}

template<typename t>
t Slist<t>::olast() {
	return last->data;
}