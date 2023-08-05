#include "ddgm/items.hpp"

// ALL THE MEANINGS OF THE FUNCTIONS
// ARE EXPLAINED IN THE HPP FILE

namespace ddgm {

// Defining the constructor of each item
Item::Item(std::string name, uint value, std::string description)
    : name(name), value(value), description(description) {}

// Initializing the constructors for each of the type of item
HealingItem::HealingItem(std::string name, uint heal, std::string description)
    : Item(name, heal, description) {}

AttackItem::AttackItem(std::string name, uint attackPower,
                       std::string description)
    : Item(name, attackPower, description) {}

MagicItem::MagicItem(std::string name, uint magicDamage,
                     std::string description)
    : Item(name, magicDamage, description) {}

BufferItem::BufferItem(std::string name, std::string description, uint buffx)
    : Item(name, buffx, description) {}

std::string Item::getName() const { return this->name; }
uint Item::getValue() const { return this->value; }
std::string Item::Item::getDescription() const { return this->description; }

} // namespace ddgm