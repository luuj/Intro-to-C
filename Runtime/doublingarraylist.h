#ifndef DOUBLE_SIR
#define DOUBLE_SIR
#include "../Source/arraylist.h"

template <class T>
class DoublingArrayList: public arrayList<T>
{
  public:
    DoublingArrayList(){}
    ~DoublingArrayList(){}
    void resize()
    {
      int maxCount = arrayList<T>::maxCount;

      T* newarrayL = new T[maxCount*2]; //New array
      for (int i=0; i<maxCount; i++)
        newarrayL[i] = arrayList<T>::arrayL[i];

      T* temp;
      temp = arrayList<T>::arrayL;
      arrayList<T>::arrayL = newarrayL;
      delete [] temp;
      arrayList<T>::maxCount*=2;
    }
};

#endif
