#ifndef PLUS_ONE
#define PLUS_ONE
#include "../Source/arraylist.h"

template <class T>
class PlusOneArrayList: public arrayList<T>
{
  public:
    PlusOneArrayList(){}
    ~PlusOneArrayList(){}
    void resize()
    {
      int maxCount = arrayList<T>::maxCount;

      T* newarrayL = new T[maxCount+1]; //New array
      for (int i=0; i<maxCount; i++)
        newarrayL[i] = arrayList<T>::arrayL[i];

      T* temp;
      temp = arrayList<T>::arrayL;
      arrayList<T>::arrayL = newarrayL;
      delete [] temp;
      arrayList<T>::maxCount+=1;
    }
};

#endif
