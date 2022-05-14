#ifndef PLUS_TEN
#define PLUS_TEN
#include "../Source/arraylist.h"

template <class T>
class PlusTenArrayList: public arrayList<T>
{
  public:
    PlusTenArrayList(){}
    ~PlusTenArrayList(){}
    void resize()
    {
      int maxCount = arrayList<T>::maxCount;

      T* newarrayL = new T[maxCount+10]; //New array
      for (int i=0; i<maxCount; i++)
        newarrayL[i] = arrayList<T>::arrayL[i];

      T* temp;
      temp = arrayList<T>::arrayL;
      arrayList<T>::arrayL = newarrayL;
      delete [] temp;
      arrayList<T>::maxCount+=10;
    }
};

#endif
