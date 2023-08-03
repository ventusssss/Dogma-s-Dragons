#include "ddgm/pawn.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <chrono>
#include <iostream>
#include <random>

// ALL THE MEANINGS OF THE FUNCTIONS
// ARE EXPLAINED IN THE HPP FILE

namespace ddgm {
void Pawn::tellVulnerabilities(Enemy &obj) {
  uint e = obj.getVulnerabilities().size();
  std::cout << "'Tis weak to ";
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
    case Skill::SkillType::none:
      std::cout << "Nothing!";
      break;
    }
  }
}

// Exact same thing for resistances
void Pawn::tellResistances(Enemy &obj) {
  uint e = obj.getResistances().size();
  std::cout << "We shouldn't use ";
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
      std::cout << " against it, Master!";
      break;
    }
    std::cout << "\n";
  }
}

void Pawn::pawndeathTalk() {
  if (!this->hp) {
    uint n = generateRandom(1, 4);
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

} // namespace ddgm