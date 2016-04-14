#ifndef _DYN_ARRAY_H__
#define _DYN_ARRAY_H__

template <typename TYPE>
class dyn_array{

public:

	uint num_elem = 0;
	uint capacity;
	TYPE* buffer;

public:

	dyn_array(uint ext_capacity){


		capacity = ext_capacity;

		buffer = new TYPE[capacity];


	}

	dyn_array(const dyn_array& copyfrom){

		capacity = copyfrom.capacity;
		buffer = new TYPE[capacity];



		int i;
		for (i = 0; i < copyfrom.num_elem; i++){

			buffer[i] = copyfrom.buffer[i];

		}

		num_elem = copyfrom.num_elem;


	}

	~dyn_array(){

		delete[] buffer;


	}


	void pushback(const TYPE& value){

		uint i;


		if (num_elem == capacity){

			capacity += 5;
			TYPE* aux_buffer = new TYPE[capacity];

			for (i = 0; i < num_elem; i++){
				aux_buffer[i] = buffer[i];
			}
			delete[] buffer;
			buffer = aux_buffer;


		}

		buffer[num_elem++] = value;

	}



	void pushfront(const TYPE& value){

		uint i;

		if (num_elem == capacity){

			capacity += 5;
			TYPE* aux_buffer = new TYPE[capacity];

			for (i = 0; i < num_elem; i++){
				aux_buffer[i] = buffer[i];
			}
			delete[] buffer;
			buffer = aux_buffer;


		}

		for (i = num_elem; i > 0; i--){

			buffer[i] = buffer[i - 1];

		}

		buffer[0] = value;
		num_elem++;

	}


	TYPE& operator [] (uint index) const{

		if (index < num_elem){

			return(buffer[index]);
		}

	}


	void erase(uint index){

		for (index; (index < num_elem - 1); index++){

			buffer[index] = buffer[index + 1];
		}

		num_elem--;

	}

};

#endif


	