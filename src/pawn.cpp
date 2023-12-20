#include "ddgm/pawn.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
<<<<<<< HEAD
//#include <algorithm>
//#include <chrono>
#include <iostream>
//#include <random>
#include <sys/types.h>
//#include <system_error>
=======
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <sys/types.h>
#include <system_error>
>>>>>>> origin/dev

// ALL THE MEANINGS OF THE FUNCTIONS
// ARE EXPLAINED IN THE HPP FILE

namespace ddgm {
void Pawn::tellVulnerabilities(Enemy &obj) {
  std::cout << obj.getName() << "'s weak to ";
  // Iterating through all the vulnerabilities of the enemy
  // and printing the corresponding one
  // I also made some controls on the value of i in relation
  // to the remaining items
  for (int i = 0; i < obj.getVulnerabilities().size(); i++) {
    switch (obj.getVulnerabilities()[i]) {
    case Skill::SkillType::slash:
      if (i == obj.getVulnerabilities().size() - 1) {
        std::cout << "Slash.";
      } else if (obj.getVulnerabilities().size() == 2 ||
                 i == obj.getVulnerabilities().size() - 2) {
        std::cout << "Slash and ";
      } else if (i < obj.getVulnerabilities().size() - 1) {
        std::cout << "Slash, ";
      }
      break;
    case Skill::SkillType::dash:
      if (i == obj.getVulnerabilities().size() - 1) {
        std::cout << "Dash.";
      } else if (obj.getVulnerabilities().size() == 2 ||
                 i == obj.getVulnerabilities().size() - 2) {
        std::cout << "Dash and ";
      } else if (i < obj.getVulnerabilities().size() - 1) {
        std::cout << "Dash, ";
      }
      break;
    case Skill::SkillType::fire:
      if (i == obj.getVulnerabilities().size() - 1) {
        std::cout << "Fire.";
      } else if (obj.getVulnerabilities().size() == 2 ||
                 i == obj.getVulnerabilities().size() - 2) {
        std::cout << "Fire and ";
      } else if (i < obj.getVulnerabilities().size() - 1) {
        std::cout << "Fire, ";
      }
      break;
    case Skill::SkillType::ice:
      if (i == obj.getVulnerabilities().size() - 1) {
        std::cout << "Ice.";
      } else if (obj.getVulnerabilities().size() == 2 ||
                 i == obj.getVulnerabilities().size() - 2) {
        std::cout << "Ice and ";
      } else if (i < obj.getVulnerabilities().size() - 1) {
        std::cout << "Ice, ";
      }
      break;
    case Skill::SkillType::thunder:
      if (i == obj.getVulnerabilities().size() - 1) {
        std::cout << "Thunder.";
      } else if (obj.getVulnerabilities().size() == 2 ||
                 i == obj.getVulnerabilities().size() - 2) {
        std::cout << "Thunder and ";
      } else if (i < obj.getVulnerabilities().size() - 1) {
        std::cout << "Thunder, ";
      }
      break;
    case Skill::SkillType::holy:
      if (i == obj.getVulnerabilities().size() - 1) {
        std::cout << "Holy.";
      } else if (obj.getVulnerabilities().size() == 2 ||
                 i == obj.getVulnerabilities().size() - 2) {
        std::cout << "Holy and ";
      } else if (i < obj.getVulnerabilities().size() - 1) {
        std::cout << "Holy, ";
      }
      break;
    case Skill::SkillType::dark:
      if (i == obj.getVulnerabilities().size() - 1) {
        std::cout << "Dark.";
      } else if (obj.getVulnerabilities().size() == 2 ||
                 i == obj.getVulnerabilities().size() - 2) {
        std::cout << "Dark and ";
      } else if (i < obj.getVulnerabilities().size() - 1) {
        std::cout << "Dark, ";
      }
      break;
    case Skill::SkillType::cure:
      break;
    case Skill::SkillType::none:
      std::cout << "Nothing!";
      break;
    }
  }
}

// Exact same thing for resistances
void Pawn::tellResistances(Enemy &obj) {
  uint e = obj.getResistances().size();
  std::cout << ": We shouldn't use ";
  for (int i = 0; i < obj.getResistances().size(); i++) {
    switch (obj.getResistances()[i]) {
    case Skill::SkillType::slash:
      if (i == obj.getResistances().size() - 1) {
        std::cout << "Slash";
      } else if (obj.getResistances().size() == 2 ||
                 i == obj.getResistances().size() - 2) {
        std::cout << "Slash or ";
      } else if (i < obj.getResistances().size() - 1) {
        std::cout << "Slash, ";
      }
      break;
    case Skill::SkillType::dash:
      if (i == obj.getResistances().size() - 1) {
        std::cout << "Dash";
      } else if (obj.getResistances().size() == 2 ||
                 i == obj.getResistances().size() - 2) {
        std::cout << "Dash or ";
      } else if (i < obj.getResistances().size() - 1) {
        std::cout << "Dash, ";
      }
      break;
    case Skill::SkillType::fire:
      if (i == obj.getResistances().size() - 1) {
        std::cout << "Fire";
      } else if (obj.getResistances().size() == 2 ||
                 i == obj.getResistances().size() - 2) {
        std::cout << "Fire or ";
      } else if (i < obj.getResistances().size() - 1) {
        std::cout << "Fire, ";
      }
      break;
    case Skill::SkillType::ice:
      if (i == obj.getResistances().size() - 1) {
        std::cout << "Ice";
      } else if (obj.getResistances().size() == 2 ||
                 i == obj.getResistances().size() - 2) {
        std::cout << "Ice or ";
      } else if (i < obj.getResistances().size() - 1) {
        std::cout << "Ice, ";
      }
      break;
    case Skill::SkillType::thunder:
      if (i == obj.getResistances().size() - 1) {
        std::cout << "Thunder";
      } else if (obj.getResistances().size() == 2 ||
                 i == obj.getResistances().size() - 2) {
        std::cout << "Thunder or ";
      } else if (i < obj.getResistances().size() - 1) {
        std::cout << "Thunder, ";
      }
      break;
    case Skill::SkillType::holy:
      if (i == obj.getResistances().size() - 1) {
        std::cout << "Holy";
      } else if (obj.getResistances().size() == 2 ||
                 i == obj.getResistances().size() - 2) {
        std::cout << "Holy or ";
      } else if (i < obj.getResistances().size() - 1) {
        std::cout << "Holy, ";
      }
      break;
    case Skill::SkillType::dark:
      if (i == obj.getResistances().size() - 1) {
        std::cout << "Dark";
      } else if (obj.getResistances().size() == 2 ||
                 i == obj.getResistances().size() - 2) {
        std::cout << "Dark or ";
      } else if (i < obj.getResistances().size() - 1) {
        std::cout << "Dark, ";
      }
      break;
    case Skill::SkillType::cure:
      break;
    case Skill::SkillType::none:
      std::cout << "Nothing!";
      break;
    }
  }
}

// In those functions, the quote is chose randomly
void Pawn::travelTalk(bool cas) {
  if (cas) {
    uint n = generateRandom(1, 5);
    std::cout << this->getName() << ": ";
    switch (n) {
    case 1:
      std::cout << "We better travel during the day, Master.";
      break;
    case 2:
      std::cout << "The roads are dangerous at night.";
      break;
    case 3:
      std::cout << "We'd best be careful Arisen, monsters prowl these roads.";
      break;
    case 4:
      std::cout << "Best be careful of ambushes";
      break;
    case 5:
      std::cout << "Even in numbers, a weakling is a weakling still.";
      break;
    }
    std::cout << "\n";
  }
}

void Pawn::itemfindTalk(bool cas) {
  if (cas) {
    uint n = generateRandom(1, 3);
    std::cout << this->getName() << ": ";
    switch (n) {
    case 1:
      std::cout << "What's that?";
      break;
    case 2:
      std::cout << "This looks interesting.";
      break;
    case 3:
      std::cout << "I wonder what this is...";
      break;
    }
    std::cout << "\n";
  }
}

void Pawn::battleTalk(bool cas, Enemy &obj) {
  if (cas) {
    uint n = generateRandom(1, 6);
    std::cout << this->getName() << ": ";
    switch (n) {
    case 1:
      std::cout << "They hold the advantage!";
      break;
    case 2:
      std::cout << "No one may touch the Arisen!";
      break;
    case 3:
      std::cout << "I've had quite enough of battle.";
      break;
    case 4:
      std::cout << "'Tis a troubling foe!";
      break;
    case 5:
      this->tellVulnerabilities(obj);
      break;
    case 6:
      this->tellResistances(obj);
      std::cout << " against " << obj.getName() << ", Master!";
      break;
    }
    std::cout << "\n\n";
  }
}

void Pawn::pawndeathTalk() {
  if (!this->hp) {
    uint n = generateRandom(1, 4);
    std::cout << this->getName() << ": ";
    switch (n) {
    case 1:
      std::cout << "I was clumsy...";
      break;
    case 2:
      std::cout << "I'm sorry, Master...";
      break;
    case 3:
      std::cout << "Danger is a part and parcel of adventure, Arisen.";
      break;
    case 4:
      std::cout << "Help...HELP!";
      break;
    }
    std::cout << "\n";
  }
}

void Pawn::calculate_dmg(Enemy &obj, Skill *skill) {
  uint dmg = dynamic_cast<Magic *>(&obj)
                 ? generateRandom(this->matk - percu(this->matk, 10),
                                  this->matk + percu(this->matk, 10))
                 : generateRandom(this->atk - percu(this->atk, 10),
                                  this->atk + percu(this->atk, 10)),
       dmg_eff = 0;

  if (skill) {
    if (isIn(skill->getName(), {"Fire Pact", "Ice Pact", "Thunder Pact",
                                "Holy Pact", "Dark Pact"})) {
      std::cout << this->name << " used " << skill->getName() << "!\n";
      std::cout
          << "This means that all of your skill types have been changed\n";
      std::cout << "to " << skill->getSkillType()
                << " for the rest of the battle\n";
      return;
    } else if (skill->returnSkillType() == Skill::SkillType::cure) {
      std::cout << this->name << " used " << skill->getName()
                << " and healed you!\n";
      return;
    } else {
      // calculating the damage based on the skill multiplier
      dmg *= skill->getMultiplier();
      if (obj.isEffective(skill->returnSkillType())) {
        dmg += percu(dmg, obj.getVulperc());
      } else if (obj.isResistant(skill->returnSkillType())) {
        dmg -= percu(dmg, obj.getResperc());
      }

      if (dynamic_cast<Magic *>(&obj)) {
        if (dmg >= obj.getMdef()) {
          dmg_eff = dmg - obj.getMdef();
        } else {
          dmg_eff = ceil(
              log((3 * pow(obj.getMdef(), 2)) - (4 * obj.getMdef()) + dmg));
        }
      } else {
        if (dmg >= obj.getDef()) {
          dmg_eff = dmg - obj.getDef();
        } else {
          dmg_eff =
              ceil(log((3 * pow(obj.getDef(), 2)) - (4 * obj.getMdef()) + dmg));
        }
      }
    }
  } else {
    dmg_eff = dmg;
  }
  obj.getHit(dmg_eff);
  std::cout << this->name << " used " << skill->getName() << " and dealt "
            << dmg_eff << " damage to " << obj.getName() << "\n";
}

Skill *Pawn::pawn_attack(Enemy &obj, Player &player) {
  // vector to store usable skills
  std::vector<Skill *> usable_skills;
  Skill *skill_to_use = nullptr;

  for (uint i = 0; i < this->player_skills.size(); i++) {
    // checks if there is a healing skill
    // and if it can be used
    if ((this->player_skills[i].returnSkillType() == Skill::SkillType::cure) &&
        (!this->player_skills[i].getActualCd()) &&
        (player.getHp() <= percu(player.getMaxHp(), 35))) {
      skill_to_use = &this->player_skills[i];
      skill_to_use->use();
      player.healEntity(percu(player.getMaxHp(), 40));
      return skill_to_use;
    }

    // checks if there are usable skills
    // and pushes back
    if ((!obj.isResistant(this->player_skills[i].returnSkillType())) &&
        (!this->player_skills[i].getActualCd())) {
      usable_skills.push_back(&this->player_skills[i]);
    }
  }

  // if skills were found, proceeds to search for
  // effective ones
  if (usable_skills.size()) {
    std::vector<Skill *> effective_skills;
    for (uint i = 0; i < usable_skills.size(); i++) {
      if (obj.isEffective(usable_skills[i]->returnSkillType())) {
        effective_skills.push_back(usable_skills[i]);
      }
    }

    // and, if it found some, overloads the usable_skills
    // vector with the effective_skills one
    if (effective_skills.size()) {
      usable_skills = effective_skills;
    }
  }

  if (usable_skills.size()) {
    // generates a random skill among the effective ones
    bool is_skill_chosen = false;
    do {
      std::cout << "enters here\n";
      skill_to_use = usable_skills[generateRandom(0, usable_skills.size() - 1)];
      if ((isIn(skill_to_use->getName(),
                {"Fire Pact", "Ice Pact", "Thunder Pact", "Holy Pact",
                 "Dark Pact"}))) {
        if ((isIn(player.getVocation(),
                  {Vocations::Mage, Vocations::Sorcerer}))) {
          continue;
        } else {
          std::vector<Skill> *p_skills = player.getSkillsAddr();
          for (Skill &x : *p_skills) {
            x.setSkillType(skill_to_use->returnSkillType());
          }
          skill_to_use->use();
        }
      }
      is_skill_chosen = true;
    } while (!is_skill_chosen);
  }
  return skill_to_use;
}
} // namespace ddgm