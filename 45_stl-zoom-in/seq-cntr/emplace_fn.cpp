#include <vector>
#include <string>

struct Item {
    std::string name;
    int id;
    Item(std::string n, int i) : name(n), id(i) {}
};

int main() {
    std::vector<Item> inventory;

    // push_back: We create a temporary Item object first
    inventory.push_back(Item("Shield", 101));

    // emplace_back: We only pass the name and ID
    // The vector calls the Item constructor internally
    inventory.emplace_back("Sword", 102); 
    
    return 0;
}