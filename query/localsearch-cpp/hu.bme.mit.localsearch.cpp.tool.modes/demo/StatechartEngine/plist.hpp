template <class T, int max>
struct PList {
  T* list[max];
  int maxSize;
  int size;

  T*& operator[](int i) {
    return list[i];
  }

  T* operator[](int i) const {
    return list[i];
  }

  PList(T** _list, int num) : maxSize(max), size(num) {
    for(int i = 0; i < num; ++i) {
      list[i] = _list[i];
    }
  }

  PList& operator=(const PList& rhs) {
    size = rhs.size;
    for(int i = 0; i < max; i++) {
      list[i] = rhs[i];
    }
	return *this;
  }

  void add(T* pointer) {
    list[size] = pointer;
    size++;
  }

  void remove(const T* pointer) {
    int i = 0;
    while(i < size && list[i] != pointer) {
      i++;
    }
    if(i != size) {
      while(i < size - 1) {
        list[i] = list[i+1];
        i++;
      }
      size--;
    }
  }

  bool contains(const T* pointer) {
    int i = 0;
    while(i < size) {
      if(pointer == list[i]) {
        return true;
      }
      i++;
    }
    return false;
  }
};
