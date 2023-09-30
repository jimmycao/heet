#include <string>
#include <iostream>
#include "../chunk_allocator.h"

struct Book {
    std::string name;
    float price;
};

void test1() {
    mulan::ChunkAllocator<Book> alloc;

    mulan::node_ptr_t node_ptr = alloc.acquire("ThreeBody", 15.9);

    Book* ptr = alloc.addr(node_ptr);

    std::cout << "name:" << ptr->name << std::endl;
    std::cout << "price:" << ptr->price << std::endl;

    alloc.release(node_ptr);
}


int main() {
    test1();
    return 0;
}