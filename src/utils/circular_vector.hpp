#include <vector>

template <class T>
class CircularVector
{
  public:
    CircularVector(size_t maxSizeIn) : maxSize(maxSizeIn)
    {}

    template <class... Args>
    void emplace(Args&&... args)
    {
        if (maxSize == 0)
        {
            return;
        }
        if (vec.size() == maxSize)
        {
            vec.at(idx) = T(std::forward<Args>(args)...);
        }
        else
        {
            vec.emplace_back(std::forward<Args>(args)...);
        }
        idx = (idx + 1) == maxSize ? 0 : (idx + 1);
    }

    void clear()
    {
        vec.clear();
        idx = 0;
    }

    void clearAndResize(size_t newMaxSize)
    {
        clear();
        maxSize = newMaxSize;
    }

    bool isFull() const
    {
        return vec.size() == maxSize;
    }

    typename std::vector<T>::const_iterator begin() const
    {
        return vec.begin();
    }

    typename std::vector<T>::const_iterator end() const
    {
        return vec.end();
    }

  private:
    size_t maxSize = 0;
    size_t idx = 0;
    std::vector<T> vec;
};
