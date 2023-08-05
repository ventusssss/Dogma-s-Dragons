#include "ddgm/items.hpp"

// ALL THE MEANINGS OF THE FUNCTIONS
// ARE EXPLAINED IN THE HPP FILE

namespace ddgm {

// Defining the constructor of each item
Item::Item(std::string name, uint value, std::string description, uint rarity)
    : name(name), value(value), description(description), rarity(rarity) {}

// Initializing the constructors for each of the type of item
HealingItem::HealingItem(std::string name, uint heal, std::string description,
                         uint rarity)
    : Item(name, heal, description, rarity) {}

AttackItem::AttackItem(std::string name, uint attackPower,
                       std::string description, uint rarity)
    : Item(name, attackPower, description, rarity) {}

MagicItem::MagicItem(std::string name, uint magicDamage,
                     std::string description, uint rarity)
    : Item(name, magicDamage, description, rarity) {}

BufferItem::BufferItem(std::string name, std::string description, uint rarity,
                       uint buffx)
    : Item(name, buffx, description, rarity) {}

std::string Item::getName() const { return this->name; }
uint Item::getValue() const { return this->value; }
std::string Item::Item::getDescription() const { return this->description; }
uint Item::getRarity() const { return this->rarity; }

} // namespace ddgm