#ifndef STACKDS_H
#define STACKDS_H
#include "framework.h"
namespace algolib
{
    template <typename T>
    class Stack
    {
    public:
        Stack(size_t MaximumCount, std::ostream *log = nullptr) : MAX(MaximumCount)
        {
            Linear = new T[MAX];
            TOP = -1;
            LOG = log;
        }

        void Push(T item)
        {
            if (TOP == MAX - 1)
            {
                _LOG_(LOG, "OVERFLOW");
                return;
            }
            TOP++;
            Linear[TOP] = item;
        }

        T PopAndGetTop()
        {
            T item{};
            if (TOP == -1)
            {
                _LOG_(LOG, "UNDERFLOW");
                return item;
            }
            item = Linear[TOP];
            TOP--;
            return item;
        }

        bool IsEmpty() const
        {
            if (TOP == -1)
                return true;
            return false;
        }

    private:
        T *Linear;
        size_t MAX{0};
        size_t TOP;
        std::ostream *LOG;
    };
} // namespace algolib
#endif