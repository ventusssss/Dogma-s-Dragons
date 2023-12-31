#include "ddgm/items.hpp"

namespace ddgm {

Item::Item(std::string name, uint value) : name(name), value(value) {}
std::string Item::getName() const { return this->name; }
uint Item::getValue() const { return this->value; }

HealingItem::HealingItem(std::string name, uint heal) : Item(name, heal) {}

AttackItem::AttackItem(std::string name, uint attackPower)
    : Item(name, attackPower) {}

MagicItem::MagicItem(std::string name, uint magicDamage)
    : Item(name, magicDamage) {}

BufferItem::BufferItem(std::string name, uint buffx) : Item(name, buffx) {}
} // namespace ddgm