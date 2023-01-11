#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <set>
#include <future>
#include <chrono>

using namespace std::chrono_literals;
std::mutex  lock_boxes;

struct Box
{
    int16_t m_id;
    int16_t price;
    Box(int16_t box_num, int16_t box_price): m_id(box_num), price(box_price) {}
};

bool operator< (const Box &lbox, const Box &rbox)
{
    return lbox.price < rbox.price;
}

std::multiset <Box> shelf;

const int numberOfBoxes = 10;
bool end;

void Human()
{
    for (int i = 0; i < numberOfBoxes; ++i)
    {
        std::this_thread::sleep_for(1000ms);
        {
            std::lock_guard shelf_lock_guard(lock_boxes);
            const std::pair<size_t, int16_t> box {i + 1, rand()% 300};
            shelf.insert(Box(box.first, box.second));
            std::cout << "new box on the shelf:   " << box.first << " price " << box.second << std::endl;
        }
        std::lock_guard shelf_lock_guard(lock_boxes);
        end = true;
    }
}

void Thief()
{
    for (int i = 0; i < numberOfBoxes; ++i)
    {
        std::this_thread::sleep_for(1500ms);
        {
            std::lock_guard shelf_lock_guard(lock_boxes);
            std::cout << "Stollen box " << shelf.end()->m_id << std::endl;

            shelf.erase(--shelf.end());

        }
    }
}




int main()
{
   std::thread human (Human);
   std::thread thief (Thief);
   human.join();
   thief.join();

   return 0;
}
