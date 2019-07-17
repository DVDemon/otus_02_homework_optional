#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <functional>


#define UNUSED(variable) ((void)variable)

namespace
{
 
    constexpr size_t bin_id_helper(size_t x,size_t index);
    constexpr size_t bin_id_helper(size_t x,size_t index){
        if(x > (1<<index)){
            return bin_id_helper(x,++index);
        } else {
            return index;
        }
    }

    constexpr size_t bin_id(size_t x)
	{
		return bin_id_helper(x,0);
	}


	static_assert(bin_id(0) == 0);
	static_assert(bin_id(1) == 0);
	static_assert(bin_id(2) == 1);
	static_assert(bin_id(4) == 2);
	static_assert(bin_id(7) == 3);
	static_assert(bin_id(8) == 3);
	static_assert(bin_id(9) == 4);
	static_assert(bin_id(1023) == 10);
	static_assert(bin_id(1024) == 10);
	static_assert(bin_id(1025) == 11);
	static_assert(bin_id(1024*1024-33) == 20);
	static_assert(bin_id(1024*1024) == 20);
	static_assert(bin_id(1024*1024+33) == 21);
	static_assert(bin_id(1024*1024*1024-127) == 30);
	static_assert(bin_id(1024*1024*1024) == 30);
	static_assert(bin_id(1024*1024*1024+127) == 31);
}

int main(int argc, char* argv[])
{
    size_t n;
    while(std::cin >> n)
        std::cout << bin_id(n) << std::endl;

    UNUSED(argc);
    UNUSED(argv);
    return 0;
}
