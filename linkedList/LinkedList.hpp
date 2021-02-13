/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO 
		Fix this method
	*/
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO 
		Fix this method
	*/
	while( temp != nullptr )
	{
		if(temp->getValue()==value){
			isFound = true;
			return(isFound);
		}
		temp = temp->getNext();
	}
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	/** TODO 
		Fix this method
	*/
	if(isEmpty()){
		return(false);
	}
	remove(m_size);
	isRemoved==true;
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}

template<typename T>
void LinkedList<T>::remove(int index)
{
  if(index <= 0 || index > m_size) //works
    {
        throw(std::runtime_error("Can't remove"));
    }
  else if(index==1)
  {
    Node<T>* temp=m_front;
    m_front=temp->getNext();
    delete temp;
    m_size--;
  }
  else if(index==m_size)
  {
    Node<T>* temp = m_front;
    for(int i = 1; i<m_size-1; i++)
      {
          temp = temp->getNext();
      }
    Node<T>* temp2 = temp->getNext();
    temp->setNext(nullptr);
    delete temp2;
    m_size--;
  }
  else
  {
    Node<T>* trav=m_front;
    Node<T>* temp=nullptr;
    for(int i=1;i<index-1;i++)
    {
      trav=trav->getNext();
    }
    temp=trav->getNext();
    trav->setNext(temp->getNext());
    delete temp;
    m_size--;
  }
}