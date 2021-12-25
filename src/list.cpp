
#include "src/list.h"

namespace Pt
{

List::List()
{
    Init();
}

List::~List()
{
}

List &List::Get()
{
    static List list;
    return list;
};

void List::Init()
{
    pageList.clear();
    izeArrayList.clear();
    adventureList.clear();
    miniGamesList.clear();
    puzzleList.clear();
    survivalList.clear();
    damageList.clear();
    hpList.clear();
    coinList.clear();
    timeList.clear();
    blockTypeList.clear();
    rowTypeList.clear();
    sceneList.clear();
    musicList.clear();
    itemList.clear();
    zombieStatusList.clear();
    zombieList.clear();
    slotsCountList.clear();
    slotsIndexList.clear();
    seedList.clear();
    rowList.clear();
    gardenHeadersList.clear();
    gardenSceneList.clear();
    directionList.clear();
    colorList.clear();
    plantStatusList.clear();
    vaseHeadersList.clear();
    vaseSkinList.clear();
    vaseTypeList.clear();
    debugModeList.clear();

    pageList
        << tr("Level")
        << tr("Resources")
        << tr("Plants")
        << tr("Zombies")
        << tr("Spawn")
        << tr("Slots")
        << tr("Scene")
        << tr("Lineup")
        << tr("Garden")
        << tr("Vase")
        << tr("Effects")
        << tr("Others")
        << tr("Status");

    izeArrayList
        << "输出主题"
        << "爆炸主题"
        << "倾斜主题"
        << "穿刺主题"
        << "回复主题"
        << "即死主题"
        << "控制主题"
        << "综合主题";

    adventureList
        << "1-1"
        << "1-2"
        << "1-3"
        << "1-4"
        << "1-5"
        << "1-6"
        << "1-7"
        << "1-8"
        << "1-9"
        << "1-10"
        << "2-1"
        << "2-2"
        << "2-3"
        << "2-4"
        << "2-5"
        << "2-6"
        << "2-7"
        << "2-8"
        << "2-9"
        << "2-10"
        << "3-1"
        << "3-2"
        << "3-3"
        << "3-4"
        << "3-5"
        << "3-6"
        << "3-7"
        << "3-8"
        << "3-9"
        << "3-10"
        << "4-1"
        << "4-2"
        << "4-3"
        << "4-4"
        << "4-5"
        << "4-6"
        << "4-7"
        << "4-8"
        << "4-9"
        << "4-10"
        << "5-1"
        << "5-2"
        << "5-3"
        << "5-4"
        << "5-5"
        << "5-6"
        << "5-7"
        << "5-8"
        << "5-9"
        << "5-10";

    miniGamesList
        << tr("ZomBotany")                  // 16
        << tr("Wall-nut Bowling")           // 17
        << tr("Slot Machine")               // 18
        << tr("It's Raining Seeds")         // 19
        << tr("Beghouled")                  // 20
        << tr("Invisi-ghoul")               // 21
        << tr("Seeing Stars")               // 22
        << tr("Zombiquarium")               // 23
        << tr("Beghouled Twist")            // 24
        << tr("Big Trouble Little Zombie")  // 25
        << tr("Portal Combat")              // 26
        << tr("Column Like You See'Em")     // 27
        << tr("Bobseld Bonanza")            // 28
        << tr("Zombie Nimble Zombie Quick") // 29
        << tr("Whack a Zombie")             // 30
        << tr("Last Stand")                 // 31
        << tr("ZomBotany 2")                // 32
        << tr("Wall-nut Bowling 2")         // 33
        << tr("Pogo Party")                 // 34
        << tr("Dr. Zomboss's Revenge")      // 35
        << tr("Art Challenge Wall-nut")     // 36
        << tr("Sunny Day")                  // 37
        << tr("Unsodded")                   // 38
        << tr("Big Time")                   // 39
        << tr("Art Challenge Sunflower")    // 40
        << tr("Air Raid")                   // 41
        << tr("Ice Level")                  // 42
        << tr("Zen Garden")                 // 43
        << tr("High Gravity")               // 44
        << tr("Grave Danger")               // 45
        << tr("Can You Dig It?")            // 46
        << tr("Dark Stormy Night")          // 47
        << tr("Bungee Blitz")               // 48
        << tr("Squirrel")                   // 49
        << tr("Tree of Wisdom");            // 50

    puzzleList
        << tr("Vasebreaker")                    // 51
        << tr("To the Left")                    // 52
        << tr("Third Vase")                     // 53
        << tr("Chain Reaction")                 // 54
        << tr("M is for Metal")                 // 55
        << tr("Scary Potter")                   // 56
        << tr("Hokey Pokey")                    // 57
        << tr("Another Chain Reaction")         // 58
        << tr("Ace of Vase")                    // 59
        << tr("Vasebreaker Endless")            // 60
        << tr("I, Zombie")                      // 61
        << tr("I, Zombie Too")                  // 62
        << tr("Can You Dig It?")                // 63
        << tr("Totally Nuts")                   // 64
        << tr("Dead Zeppelin")                  // 65
        << tr("Me Smash!")                      // 66
        << tr("ZomBoogie")                      // 67
        << tr("Three Hit Wonder")               // 68
        << tr("All your brainz r belong to us") // 69
        << tr("I, Zombie Endless")              // 70
        << tr("Upsell")                         // 71
        << tr("Intro");                         // 72

    survivalList
        << tr("Survival: Day")             // 1
        << tr("Survival: Night")           // 2
        << tr("Survival: Pool")            // 3
        << tr("Survival: Fog")             // 4
        << tr("Survival: Roof")            // 5
        << tr("Survival: Day (Hard)")      // 6
        << tr("Survival: Night (Hard)")    // 7
        << tr("Survival: Pool (Hard)")     // 8
        << tr("Survival: Fog (Hard)")      // 9
        << tr("Survival: Roof (Hard)")     // 10
        << tr("Survival: Day (Endless)")   // 11
        << tr("Survival: Night (Endless)") // 12
        << tr("Survival: Endless")         // 13
        << tr("Survival: Fog (Endless)")   // 14
        << tr("Survival: Roof (Endless)"); // 15

    damageList
        << tr("Pea")
        << tr("Frozen Pea")
        << tr("Cabbage")
        << tr("Melon")
        << tr("Fume")
        << tr("Winter Melon")
        << tr("Fireball")
        << tr("Star")
        << tr("Spike")
        << tr("Basketball")
        << tr("Kernel")
        << tr("Butter")
        << tr("Zombie Pea")
        << tr("Ash")
        << tr("Potato Mine")
        << tr("Ice-shroom")
        << tr("Squash")
        << tr("Bite");

    hpList
        << tr("Plant", "Normal Plant")
        << tr("Wall-nut")
        << tr("Tall-nut")
        << tr("Pumpkin")
        << tr("Garlic")
        << tr("Spikerock")
        << tr("Zombie", "Normal Zombie")
        << tr("Conehead Zombie") // 7 路障
        << tr("Pole Vaulting Zombie")
        << tr("Buckethead Zombie")  // 9 铁桶
        << tr("Newspaper Zombie")   // 10 报纸
        << tr("Screen Door Zombie") // 11 铁栅门
        << tr("Football Zombie")    // 12 橄榄球帽
        << tr("Dancing Zombie")
        << tr("Zomboni")
        << tr("Dolphin Rider Zombie")
        << tr("Jack-in-the-Box Zombie")
        << tr("Digger Zombie") // 17 矿工帽
        << tr("Pogo Zombie")
        << tr("Zombie Yeti")
        << tr("Bungee Zombie")
        << tr("Ladder Zombie") // 21 扶梯
        << tr("Gargantuar")
        << tr("Dr. Zomboss")
        << tr("Dr. Zomboss Extra")
        << tr("Wall-nut Zombie") // 25 僵尸坚果
        << tr("Jalapeno Zombie")
        << tr("Tall-nut Zombie") // 27 僵尸高坚果
        << tr("GigaGargantuar")
        << tr("Imp in I, Zombie")
        << tr("Balloon"); // 30 气球

    coinList
        << tr("Silver Coin")
        << tr("Gold Coin")
        << tr("Diamond")
        << tr("Sun")
        << tr("Small Sun")
        << tr("Big Sun")
        << "7"
        << "8"
        << "9"
        << "10"
        << "11"
        << "12"
        << "13"
        << "14"
        << "15"
        << "16"
        << "17"
        << "18"
        << "19"
        << "20"
        << "21"
        << "22"
        << "23"
        << "24"
        << "25"
        << "26"
        << "27";

    timeList
        << tr("Fog Clear")
        << tr("Cherry Bomb / Jalapeno")
        << tr("Potato Mine")
        << tr("Chomper")
        << tr("Sun-shroom")
        << tr("Ice-shroom")
        << tr("Doom-shroom")
        << tr("Blover")
        << tr("Magnet-shroom")
        << tr("Cob Cannon Filling")
        << tr("Backup Dancer Call")
        << tr("Zombie Yeti Run Away")
        << tr("Bungee Zombie Stay");

    blockTypeList
        << tr("Lawn")
        << tr("Bare")
        << tr("Pool");

    rowTypeList
        << tr("None")
        << tr("Land")
        << tr("Water");

    sceneList
        << tr("Day")
        << tr("Night")
        << tr("Pool")
        << tr("Fog")
        << tr("Roof")
        << tr("Moon")
        << tr("Mushroom Garden")
        << tr("Zen Garden")
        << tr("Aquarium Garden")
        << tr("Tree of Wisdom");

    musicList // keep original name
        << "Grasswalk"
        << "Moongrains"
        << "Watery Graves"
        << "Rigor Mormist"
        << "Graze the Roof"
        << "Choose Your Seeds"
        << "Crazy Dave"
        << "Zen Garden"
        << "Cerebrawl"
        << "Loonboon"
        << "Ultimate Battle"
        << "Brainiac Maniac";

    itemList
        << tr("Grave")        // 1
        << tr("Crater")       // 2
        << tr("Ladder")       // 3
        << tr("White Portal") // 4
        << tr("Black Portal") // 5
        << tr("Vase")         // 7
        << tr("Snail")        // 10
        << tr("Rake")         // 11
        << tr("Brain")        // 12
        << tr("Plants")
        << tr("Zombies");

    zombieStatusList
        << tr("Kill")
        << tr("Hypno")
        << tr("Freeze")
        << tr("Decelerate")
        << tr("Immobilize")
        << tr("Blow Away")
        << tr("Dying")
        << tr("Disappear")
        << tr("Black")
        << tr("Bigger");

    zombieList
        << tr("Zombie", "Zombie")                 // 0
        << tr("Flag Zombie", "Zombie")            // 1
        << tr("Conehead Zombie", "Zombie")        // 2
        << tr("Pole Vaulting Zombie", "Zombie")   // 3
        << tr("Buckethead Zombie", "Zombie")      // 4
        << tr("Newspaper Zombie", "Zombie")       // 5
        << tr("Screen Door Zombie", "Zombie")     // 6
        << tr("Football Zombie", "Zombie")        // 7
        << tr("Dancing Zombie", "Zombie")         // 8
        << tr("Backup Dancer", "Zombie")          // 9
        << tr("Ducky Tube Zombie", "Zombie")      // 10
        << tr("Snorkel Zombie", "Zombie")         // 11
        << tr("Zomboni", "Zombie")                // 12
        << tr("Zombie Bobsled Team", "Zombie")    // 13
        << tr("Dolphin Rider Zombie", "Zombie")   // 14
        << tr("Jack-in-the-Box Zombie", "Zombie") // 15
        << tr("Balloon Zombie", "Zombie")         // 16
        << tr("Digger Zombie", "Zombie")          // 17
        << tr("Pogo Zombie", "Zombie")            // 18
        << tr("Zombie Yeti", "Zombie")            // 19
        << tr("Bungee Zombie", "Zombie")          // 20
        << tr("Ladder Zombie", "Zombie")          // 21
        << tr("Catapult Zombie", "Zombie")        // 22
        << tr("Gargantuar", "Zombie")             // 23
        << tr("Imp", "Zombie")                    // 24
        << tr("Dr. Zomboss", "Zombie")            // 25
        << tr("Peashooter Zombie", "Zombie")      // 26
        << tr("Wall-nut Zombie", "Zombie")        // 27
        << tr("Jalapeno Zombie", "Zombie")        // 28
        << tr("Gatling Pea Zombie", "Zombie")     // 29
        << tr("Squash Zombie", "Zombie")          // 30
        << tr("Tall-nut Zombie", "Zombie")        // 31
        << tr("GigaGargantuar", "Zombie");        // 32

    slotsCountList
        << tr("1 slot")
        << tr("2 slots")
        << tr("3 slots")
        << tr("4 slots")
        << tr("5 slots")
        << tr("6 slots")
        << tr("7 slots")
        << tr("8 slots")
        << tr("9 slots")
        << tr("10 slots");

    slotsIndexList
        << tr("1st slot")
        << tr("2nd slot")
        << tr("3rd slot")
        << tr("4th slot")
        << tr("5th slot")
        << tr("6th slot")
        << tr("7th slot")
        << tr("8th slot")
        << tr("9th slot")
        << tr("10th slot");

    seedList
        << tr("Peashooter") // 0
        << tr("Sunflower")
        << tr("Cherry Bomb")
        << tr("Wall-nut")
        << tr("Potato Mine")
        << tr("Snow Pea")
        << tr("Chomper")
        << tr("Repeater")
        << tr("Puff-shroom")
        << tr("Sun-shroom")
        << tr("Fume-shroom")
        << tr("Grave Buster")
        << tr("Hypno-shroom")
        << tr("Scaredy-shroom")
        << tr("Ice-shroom")
        << tr("Doom-shroom")
        << tr("Lily Pad")
        << tr("Squash")
        << tr("Threepeater")
        << tr("Tangle Kelp")
        << tr("Jalapeno")
        << tr("Spikeweed")
        << tr("Torchwood")
        << tr("Tall-nut")
        << tr("Sea-shroom")
        << tr("Plantern")
        << tr("Cactus")
        << tr("Blover")
        << tr("Split Pea")
        << tr("Starfruit")
        << tr("Pumpkin")
        << tr("Magnet-shroom")
        << tr("Cabbage-pult")
        << tr("Flower Pot")
        << tr("Kernel-pult")
        << tr("Coffee Bean")
        << tr("Garlic")
        << tr("Umbrella Leaf")
        << tr("Marigold")
        << tr("Melon-pult")
        << tr("Gatling Pea")
        << tr("Twin Sunflower")
        << tr("Gloom-shroom")
        << tr("Cattail")
        << tr("Winter Melon")
        << tr("Gold Magnet")
        << tr("Spikerock")
        << tr("Cob Cannon") // 47
        << tr("Imitater")   // 48
        << tr("Explode-o-nut")
        << tr("Giant Wall-nut")
        << tr("Sprout")
        << tr("Reverse Repeater")
        << tr("Nothing")       // 53
        << tr("Shuffle plant") // 54
        << tr("Refill crator") // 55
        << tr("Sun")           // 56
        << tr("Diamond")       // 57
        << tr("Snorkel Zombie")
        << tr("Trophy")
        << tr("Zombie", "Zombie Zombie")
        << tr("Conehead Zombie")
        << tr("Pole Vaulting Zombie")
        << tr("Buckethead Zombie")
        << tr("Ladder Zombie")
        << tr("Digger Zombie")
        << tr("Bungee Zombie")
        << tr("Football Zombie")
        << tr("Balloon Zombie")
        << tr("Screen Door Zombie")
        << tr("Zomboni")
        << tr("Pogo Zombie")
        << tr("Dancing Zombie")
        << tr("Gargantuar")
        << tr("Imp")
        << tr("<Missing>"); // 75

    rowList
        << tr("All Rows")
        << tr("1st Row")
        << tr("2nd Row")
        << tr("3rd Row")
        << tr("4th Row")
        << tr("5th Row")
        << tr("6th Row");

    gardenHeadersList
        << tr("Index")
        << tr("Row")
        << tr("Column")
        << tr("Scene")
        << tr("Type")
        << tr("Direction")
        << tr("Color")
        << tr("Status", "grow up status");

    gardenSceneList
        << tr("Zen Garden")
        << tr("Mushroom Garden")
        << tr("Wheel Barrow")
        << tr("Aquarium Garden");

    directionList
        << tr("Right")
        << tr("Left");

    colorList
        << tr("Original")
        << tr("Imitater")
        << tr("White")
        << tr("Magenta")
        << tr("Orange")
        << tr("Pink")
        << tr("Cyan")
        << tr("Red")
        << tr("Blue")
        << tr("Purple")
        << tr("Lavender")
        << tr("Yellow")
        << tr("LightGreen");

    plantStatusList
        << tr("Sprout")
        << tr("Small Size")
        << tr("Medium Size")
        << tr("Full Size");

    vaseHeadersList
        << tr("Index")
        << tr("Row")
        << tr("Column")
        << tr("Skin")
        << tr("Type")
        << tr("Content");

    vaseSkinList
        << tr("None")
        << tr("Unknown")
        << tr("Plant")
        << tr("Zombie");

    vaseTypeList
        << tr("Empty")
        << tr("Plant")
        << tr("Zombie")
        << tr("Sun");

    debugModeList
        << tr("Off")
        << tr("Spawning")
        << tr("Music")
        << tr("Memory")
        << tr("Collision");
}

} // namespace Pt
