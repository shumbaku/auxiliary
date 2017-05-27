namespace aad {
	
template<class T>
	class array{
		T *p;
		unsigned int i,j;//row and column size
		unsigned int d; // array dimension
		unsigned int s; //array size
		public:
		
		/** COnstructers **/
		array(unsigned i);
		array(unsigned i,unsigned j);
		
		/** Destructer **/
		~array();
		
		/** Operator Overloads **/
		T& operator [] (unsigned i);
	//	T& operator [][] (unsigned i,unsigned j);
		
		/** Member Functions **/
		T& get(unsigned i);
		T& get(unsigned i,unsigned j);
		
		void set(unsigned i,T &data);
		void set(unsigned i,unsigned j, T &data);
		
		T* unpack(); 
		
		unsigned int dimension();
		unsigned int size();
		unsigned int row();
		unsigned int column();
	};

	template<class T> array<T>::array(unsigned i)
	{
		if(i>0 && i<this->i)
		{
			this->p = new T[i];
			d = 1;
			this->i = i;
			
			this->s = i;
		}
	}
	template<class T> array<T>::array(unsigned i, unsigned j)
	{
		if(i>0 && j>0 )
		{	
			this->p = new T[i*j];
			this->d = 2;
			this->i=i;
			this->j=j;
			this->s = i*j;
		}
	}
	/** Destructers **/
	template<class T> array<T>::~array()
	{
		delete [] p;
	}
	
	template<class T> T& array<T>::operator[] (unsigned i)
	{
		if(i >= 0 && i < this->i )
		{
			return this->p[i];
		}
		else
		{
			return nullptr;
		}
	}
	template<class T> T& array<T>::get(unsigned i)
	{
		if(i>=0 && i < this->i)
		{
			return this->p[i];
		}
	}

	template<class T> T& array<T>::get(unsigned i,unsigned j)
	{
		if(this->d == 2)
		{
			if((i>=0 && i< this->i) && ( j>=0 && j < this->j))
			{
				return this->p[i*j+j];
			}
		}
		return this->p[0];
	}
	template<class T> void array<T>::set(unsigned i, T &data)
	{
		if(i>=0 && i<this->i)
		{
			this->p[i] = data;
		}
	}
	template<class T> void array<T>::set(unsigned i, unsigned j,T &data)
	{
		if((i>=0 && i<this->i) && (j>=0) && j<this->j)
		{
			this->p[i*j+j] = data;
		}
	}
	template<class T> unsigned int array<T>::size()
	{
		return this->s;
	}
	template<class T> unsigned int array<T>::column()
	{
		return this->j;
	}
	template<class T> unsigned int array<T>::row()
	{
		return this->i;
	}
	template<class T> unsigned int array<T>::dimension()
	{
		return this->d;
	}
	template<class T> T* array<T>::unpack()
	{
		return this->p;
	}
}
